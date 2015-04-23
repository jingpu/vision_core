#! /usr/bin/python
# Compile a chunk of bit-width-specified DPDA into C code which simulates
# its operation.

import sys

from dpdadag import expand_range
from dpdadag import parse_dpda


class CodeWriter:
  """
  Little class that makes it easy to pretty-print code to a file or to stdout.
  """
  def __init__(self, filename=None):
    self.indentAmount = 0
    if filename is not None:
      self.outputFile = open(filename, 'w')
    else:
      self.outputFile = None

  def close(self):
    if self.outputFile is not None:
      self.outputFile.close()

  def writeln(self, line=''):
    if self.outputFile is not None:
      self.outputFile.write(' ' * self.indentAmount + line + '\n')
    else:
      print ' ' * self.indentAmount + line

  def indent(self):
    self.indentAmount += 2

  def unindent(self):
    self.indentAmount = max(0, self.indentAmount - 2)

def opOk(op, validRegs):
  """
  Checks whether an operation can be evaluated, i.e., if all of its operands
  have valid values.
  """
  for operand in op.operands:
    if not operand in validRegs:
      return False
  # If we make it here, they're all valid
  return True

def mangle(signal):
  """
  Takes a signal name as a (name, index) tuple and returns a C-safe identifier.
  """
  if type(signal) is list:
    return [mangle(s) for s in signal]
  else:
    (name, index) = signal
    return name + '_' + str.join('_', [str(x) for x in index])

def write_complex_op(writer, op, datatype):
  """
  write a complex operation (more than one line of C)
  """
  if op.name == "max":
    final_dst = mangle(op.result)
    # write a line of comment
    writer.writeln("// max {dst} <= ({src})"\
                     .format(dst=final_dst, src=str.join(' , ', mangle(op.operands))))
    w.writeln("{dtype} {dst} = ({src1} > {src2}) ? {src1} : {src2};"\
                .format(dtype=datatype, dst=(final_dst+'_cotmp_1'), 
                        src1=mangle(op.operands[0]), src2=mangle(op.operands[1])))
    for i in range(2, len(op.operands)):
      dst_name = final_dst + '_cotmp_' + str(i)
      src1_name = final_dst + '_cotmp_' + str(i-1)
      src2_name = mangle(op.operands[i])
      w.writeln("{dtype} {dst} = ({src1} > {src2}) ? {src1} : {src2};"\
                  .format(dtype=datatype, dst=dst_name, 
                          src1=src1_name, src2=src2_name))
    
    # move final result to dst
    w.writeln("{dtype} {dst} = {src};\n"\
                .format(dtype=datatype, dst=final_dst, 
                        src=(final_dst + '_cotmp_' + str(len(op.operands)-1))))

  elif op.name == "min": 
    final_dst = mangle(op.result)
    # write a line of comment
    writer.writeln("// min {dst} <= ({src})"\
                     .format(dst=final_dst, src=str.join(' , ', mangle(op.operands))))
    w.writeln("{dtype} {dst} = ({src1} < {src2}) ? {src1} : {src2};"\
                .format(dtype=datatype, dst=(final_dst+'_cotmp_1'), 
                        src1=mangle(op.operands[0]), src2=mangle(op.operands[1])))
    for i in range(2, len(op.operands)):
      dst_name = final_dst + '_cotmp_' + str(i)
      src1_name = final_dst + '_cotmp_' + str(i-1)
      src2_name = mangle(op.operands[i])
      w.writeln("{dtype} {dst} = ({src1} < {src2}) ? {src1} : {src2};"\
                  .format(dtype=datatype, dst=dst_name, 
                          src1=src1_name, src2=src2_name))
    
    # move final result to dst
    w.writeln("{dtype} {dst} = {src};\n"\
                .format(dtype=datatype, dst=final_dst, 
                        src=(final_dst + '_cotmp_' + str(len(op.operands)-1))))

  else:
    print "Unhandled complex operator " + opKey


dtypeMap = {'float':'float', 'ufix':'unsigned int', 'fix':'signed int', 'bool':'bool'}

def write_kernel(w, k):
  """
  Parameters are the CodeWriter object, and the kernel object (not just the name)
  """
  w.writeln("void {k}(const Image<int>& in, Image<int>& out".format(k=k.name))
  # write the tap signal in the function argument list
  for tapName in k.rtapNames:
    tapType = k.edges[tapName].dtype
    tapCType = dtypeMap[tapType]
    for indices in expand_range(k.edges[tapName].dim):
      w.writeln("\t, {type} {sig}".format(type=tapCType, sig=mangle((tapName, indices))))
  w.writeln(")")
  w.writeln("{")
  w.indent()
  # TODO: insert size error checking into C code here

  w.writeln("for(int y = 0; y < in.height(); y++){")
  w.indent()
  w.writeln("for(int x = 0; x < in.width(); x++){")
  w.indent()

  
  # Grab the register declaration for the partial-pixel output and blow it into
  # the complete list of input registers
  startName = k.ppoutName
  startType = k.edges[startName].dtype
  startCType = dtypeMap[startType]
  for indices in expand_range(k.edges[startName].dim):
    # HACK: work with multi-channel or single-channel images
    z_idx = 0
    if len(indices) == 3:
      z_idx = indices[2]

    w.writeln("{type} {reg} = in(x+{xoff}, y+{yoff}, {z});".format(
        type=startCType,
        reg=mangle((startName, indices)),
        xoff=(indices[0]-k.centroid[0]), 
        yoff=(indices[1]-k.centroid[1]), z=z_idx))
  
  # Set up the constants
  for const in k.constants:
    # TODO: be careful here, because we need to be consistent with naming/indexing
    # TODO: handle int/float; infer datatype in parser
    w.writeln("const float {reg} = {val};".format(reg=mangle((const[0], [0])), val=const[1]))
  
  w.writeln("")


  #Special Register Examples for Reduce:
  #fix_17_0 pixel_out_pos[1:0]  # Location of Reduce pixel in output image
  #fix_17_0 centroid_pos[1:0]  # Location of Centroid in input image
  if "centroid_pos" in k.specialRegs:
    w.writeln("int centroid_pos_0 = x;")
    w.writeln("int centroid_pos_1 = y;")

  if "pixel_out_pos" in k.specialRegs:
    w.writeln("int pixel_out_pos_0 = x;")
    w.writeln("int pixel_out_pos_1 = y;")
  
  # Create a list of (name, index) tuples representing the valid (i.e., evaluated) signal
  validRegs = [(startName, i) for i in expand_range(k.edges[startName].dim)]
  validRegs += [(tapName, i) for tapName in k.rtapNames 
                for i in expand_range(k.edges[tapName].dim)]
  validRegs += [(regName, i) for regName in k.specialRegs 
                for i in expand_range(k.edges[regName].dim)]
  validRegs += [(c[0], [0]) for c in k.constants]
  
  # Make a copy of the list of operations which we can remove stuff from
  unprocessed = dict(k.ops)
  
  # Process all the operations
  while len(unprocessed) > 0:
    progress = False
    for opKey in unprocessed:
      op = k.ops[opKey]
      # Find an operation that can be evaluated
      if opOk(op, validRegs):
        dtype = k.edges[op.result[0]].dtype
        dtype = dtypeMap[dtype] # Look up the C-equivalent for this type
        # TODO: include integer/fraction width
  
        # TODO: error checking that we have the right number of operands - this should be done in the parser, actually
        # Evaluate it
        if op.name in ['max', 'min']:
          write_complex_op(w, op, dtype)
        elif op.name == "sum": 
          w.writeln("{dtype} {dst} = {src};".format(dtype=dtype, dst=mangle(op.result), src=str.join(' + ', mangle(op.operands))))
        elif op.name == "mv":
          w.writeln("{dtype} {dst} = {src};".format(dtype=dtype, dst=mangle(op.result), src=mangle(op.operands[0])))
        elif op.name == "add":
          w.writeln("{dtype} {dst} = {src};".format(dtype=dtype, dst=mangle(op.result), src=str.join(' + ', mangle(op.operands))))
        elif op.name == "sub":
          w.writeln("{dtype} {dst} = {src};".format(dtype=dtype, dst=mangle(op.result), src=str.join(' - ', mangle(op.operands))))
        elif op.name == "mult":
          w.writeln("{dtype} {dst} = {src};".format(dtype=dtype, dst=mangle(op.result), src=str.join(' * ', mangle(op.operands))))
        elif op.name == "div":
          w.writeln("{dtype} {dst} = {src};".format(dtype=dtype, dst=mangle(op.result), src=str.join(' / ', mangle(op.operands))))

        elif op.name == "lshift":
          w.writeln("{dtype} {dst} = {op1} << {op2};".format(dtype=dtype, dst=mangle(op.result), op1=mangle(op.operands[0]), op2=mangle(op.operands[1])))
        elif op.name == "rshift":
          w.writeln("{dtype} {dst} = {op1} >> {op2};".format(dtype=dtype, dst=mangle(op.result), op1=mangle(op.operands[0]), op2=mangle(op.operands[1])))
        elif op.name == "and":
          w.writeln("{dtype} {dst} = {op1} & {op2};".format(dtype=dtype, dst=mangle(op.result), op1=mangle(op.operands[0]), op2=mangle(op.operands[1])))
        elif op.name == "or":
          w.writeln("{dtype} {dst} = {op1} | {op2};".format(dtype=dtype, dst=mangle(op.result), op1=mangle(op.operands[0]), op2=mangle(op.operands[1])))
        elif op.name == "ne":
          w.writeln("{dtype} {dst} = {op1} != {op2};".format(dtype=dtype, dst=mangle(op.result), op1=mangle(op.operands[0]), op2=mangle(op.operands[1])))
        elif op.name == "eq":
          w.writeln("{dtype} {dst} = {op1} == {op2};".format(dtype=dtype, dst=mangle(op.result), op1=mangle(op.operands[0]), op2=mangle(op.operands[1])))
        elif op.name == "lt":
          w.writeln("{dtype} {dst} = {op1} < {op2};".format(dtype=dtype, dst=mangle(op.result), op1=mangle(op.operands[0]), op2=mangle(op.operands[1])))
        elif op.name == "lte":
          w.writeln("{dtype} {dst} = {op1} <= {op2};".format(dtype=dtype, dst=mangle(op.result), op1=mangle(op.operands[0]), op2=mangle(op.operands[1])))
        elif op.name == "gt":
          w.writeln("{dtype} {dst} = {op1} > {op2};".format(dtype=dtype, dst=mangle(op.result), op1=mangle(op.operands[0]), op2=mangle(op.operands[1])))
        elif op.name == "gte":
          w.writeln("{dtype} {dst} = {op1} >= {op2};".format(dtype=dtype, dst=mangle(op.result), op1=mangle(op.operands[0]), op2=mangle(op.operands[1])))
        elif op.name == "not":
          w.writeln("{dtype} {dst} = !{src};".format(dtype=dtype, dst=mangle(op.result), src=mangle(op.operands[0])))
        elif op.name == "abs":
          w.writeln("{dtype} {dst} = ({src} >= 0) ? {src} : (-{src});".format(dtype=dtype, dst=mangle(op.result), src=mangle(op.operands[0])))
        elif op.name == "inv":
          w.writeln("{dtype} {dst} = -{src};".format(dtype=dtype, dst=mangle(op.result), src=mangle(op.operands[0])))

        elif op.name == "mux":
          w.writeln("{dtype} {dst} = {cond} ? {op1} : {op2};".format(dtype=dtype, dst=mangle(op.result), \
              cond=mangle(op.operands[0]), op1=mangle(op.operands[1]), op2=mangle(op.operands[2])))
        else:
          print "Unhandled operator " + opKey
  
        validRegs.append(op.result)
        # Remove it from the list
        unprocessed.pop(opKey)
        progress = True
        break # We changed the list, so we gotta start over
  
    # If we went through the whole list without finding any ops to evaluate,
    # something is wrong and we need to give up.
    if progress is False:
      print "Failed to evaluate some ops!"
      for opKey in unprocessed:
        print "\t %s %s" % (unprocessed[opKey].name, unprocessed[opKey].result)
      break
  
  for indices in expand_range(k.edges[k.sink].dim):
    #writeln('printf("result: %f\\n", {reg});'.format(reg=mangle((k.sink, indices))))
    # TODO: make this handle depths other than 3
    w.writeln('out(x,y,{z}) = {reg};'.format(z=indices[0], reg=mangle((k.sink, indices))))

  w.unindent()
  w.writeln("}")
  w.unindent()
  w.writeln("}")
  w.unindent()
  w.writeln("} // END %s" % k.name)
  w.writeln("\n")

def write_main(w, dag):
  """
  Writes the main function which makes invocations to all the kernels.
  Arguments are the CodeWriter object to use, and the parsed top-level DAG.
  """
  w.writeln("int main(int argc, char* argv[])");
  w.writeln("{");
  w.indent()

  head = dag.head # Get the edge which points to the first kernel
  w.writeln("int width = 256;  // TODO change to match input image")
  w.writeln("int height = 256;  // TODO change to match input image")
  w.writeln("int channels = 3;  // TODO change to match input image")
  w.writeln("Image<int> %s(width, height, channels, 0);" % head)
  w.writeln("%s.load(argv[1]);" % head)
  w.writeln()

  w.writeln("// Set tap values")
  head = dag.head # Get the edge which points to the first kernel
  tapSet = set()  # use a set to avoid redeclaration of tap in C
  while head != dag.tail:
    # Look up the kernel corresponding to the edge sink
    k = dag.kernels[dag.edges[head][1]]

    # Create placeholder for tap values
    for tapName in k.rtapNames:
      if tapName not in tapSet:
        tapSet.add(tapName)
        tapType = k.edges[tapName].dtype
        tapType = dtypeMap[tapType]
        for indices in expand_range(k.edges[tapName].dim):
          w.writeln("{type} {sig} = 0; \t// TODO change in value".format(type=tapType, sig=mangle((tapName, indices))))

    # go to the next kernel
    head = k.sink

  w.writeln("") 

  w.writeln("// Construct the pipeline of kernels")
  head = dag.head # Get the edge which points to the first kernel
  while head != dag.tail:
    # Look up the kernel corresponding to the edge sink
    k = dag.kernels[dag.edges[head][1]]

    # Create an image for the output
    channels = len(expand_range(k.edges[k.sink].dim))
    w.writeln("Image<int> {0}(width, height, {1}, 0);".format(k.sink, channels))

    # Invoke the kernel
    w.writeln("{k}({src}, {sink}".format(k=k.name, src=head, sink=k.sink))
    for tapName in k.rtapNames:
      for indices in expand_range(k.edges[tapName].dim):
        w.writeln("\t, {sig}".format(sig=mangle((tapName, indices))))
    w.writeln(");")
    w.writeln("") 

    # go to the next kernel
    head = k.sink

  w.writeln('{sink}.save("result.bmp");'.format(sink=k.sink))

  w.writeln("return(0);");
  w.unindent()
  w.writeln("}");



if __name__ == "__main__":
  import sys
  if len(sys.argv) < 2:
    print "Usage: compile.py DPDA_FILE"
    exit()
  else:
    sourceFile = sys.argv[-1]

  w = CodeWriter("pipeline.cpp")
  #w = CodeWriter()
  w.writeln("#include <stdio.h>");
  w.writeln("#include <stdlib.h>");
  w.writeln("#include \"image.h\"");

  dag = parse_dpda(sourceFile)

  for k in dag.kernels.values():
    print ("\twriting kernel {}...".format(k.name))
    write_kernel(w, k)

  write_main(w, dag)

  w.close()

