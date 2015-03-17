#! /usr/bin/python

# dpda2tie.py
# Read in a DPDA YAML file and generate C program using TIE
#
# Jing Pu <jingpu@stanford.edu>
# March 2015

import dpdadag
import compile


dtypeMap = {'float':'float', 'ufix':'unsigned int', 'fix':'signed int', 'bool':'bool'}

def write_complex_op_tie(writer, op, datatype):
    """
    write a complex operation (more than one line of C)
    """
    if op.name in ["max", "min", "sum"]:
        inst = op.name
        if inst == "sum":
            inst = "add"
        final_dst = compile.mangle(op.result)
        # write a line of comment
        writer.writeln("// {op} {dst} <= ({src})"\
                           .format(op=inst, dst=final_dst, 
                                   src=str.join(' , ', compile.mangle(op.operands))))
        w.writeln("{dtype} {dst} = {op}32_vv({src1}, {src2});"\
                      .format(dtype=datatype, dst=(final_dst+'_cotmp_1'), op=inst,
                              src1=compile.mangle(op.operands[0]), 
                              src2=compile.mangle(op.operands[1])))

        for i in range(2, len(op.operands)):
            dst_name = final_dst + '_cotmp_' + str(i)
            src1_name = final_dst + '_cotmp_' + str(i-1)
            src2_name = compile.mangle(op.operands[i])
            w.writeln("{dtype} {dst} = {op}32_vv({src1}, {src2});"\
                          .format(dtype=datatype, dst=dst_name, op=inst,
                                  src1=src1_name, src2=src2_name))
    
        # move final result to dst
        w.writeln("{dtype} {dst} = {src};\n"\
                      .format(dtype=datatype, dst=final_dst, 
                              src=(final_dst + '_cotmp_' + str(len(op.operands)-1))))

    else:
        print "Unhandled complex operator " + op

def write_kernel_tie(w, k, code_type):
  """
  Parameters are the CodeWriter object, and the kernel object (not just the name)
  """
  w.writeln("void {k}(const Image<vector32>& in, Image<vector32>& out".format(k=k.name))
  # write the tap signal in the function argument list
  for tapName in k.rtapNames:
    tapType = k.edges[tapName].dtype
    tapCType = dtypeMap[tapType]
    for indices in dpdadag.expand_range(k.edges[tapName].dim):
      w.writeln("\t, {type} {tap}_s".format(type=tapCType, 
                                            tap=compile.mangle((tapName, indices))))
  
  # for header type, only print declaration
  if code_type == 'header':
      w.writeln(");")
      w.writeln("")
      return
  
  w.writeln(")")
  w.writeln("{")
  w.indent()
  # TODO: insert size error checking into C code here

  reg_idx = 0;
  # Set up the taps  
  w.writeln("// Set up the tap values")
  for tapName in k.rtapNames:
    # TODO: be careful here, because we need to be consistent with naming/indexing
    # TODO: handle int/float; infer datatype in parser
    for indices in dpdadag.expand_range(k.edges[tapName].dim):
        w.writeln("register vector32 {tap} asm(\"v32r{idx}\"); // keep in the register\n"
                  "  {tap} = mv32_sv({tap}_s);"
                  .format(tap=compile.mangle((tapName, indices)), idx=reg_idx))
        reg_idx += 1
  
  w.writeln("")

  # Set up the constants
  w.writeln("// Set up the constant values")
  for const in k.constants:
    # TODO: be careful here, because we need to be consistent with naming/indexing
    # TODO: handle int/float; infer datatype in parser
    w.writeln("register vector32 {sig} asm(\"v32r{idx}\"); // keep in the register\n"
              "  {sig} = mv32_sv({val});"
              .format(sig=compile.mangle((const[0], [0])), val=const[1], idx=reg_idx))
    reg_idx += 1
  
  w.writeln("")


  w.writeln("const vector32 *in_ptr = in.mData; // use direct access to speed up inner loop")
  w.writeln("vector32 *out_ptr = out.mData; // use direct access to speed up inner loop")
  w.writeln("const int IN_WIDTH = in.width();")
  w.writeln("const int IN_HEIGHT = in.height();")

  # Grab the register declaration for the partial-pixel output and blow it into
  # the complete list of input registers
  startName = k.ppoutName
  # extract some information from input/output stencil dimention
  input_dim = k.edges[startName].dim
  output_dim = k.edges[k.sink].dim
  in_channels = 1   # default number of the channels is one
  out_channels = 1   # default number of the channels is one
  if (len(input_dim) == 3):
      c_dim = input_dim[2]  # tuple of (start, end)
      in_channels = abs(c_dim[0] - c_dim[1] + 1)
  if (len(output_dim) == 1):
      c_dim = output_dim[0]  # tuple of (start, end)
      out_channels = abs(c_dim[0] - c_dim[1] + 1)
  w.writeln("const int IN_CHANNELS = {}; // use static value to allow more compiler optimization".format(in_channels))
  w.writeln("const int OUT_CHANNELS = {}; /// use static value to allow more compiler optimization".format(out_channels))

  w.writeln("")
  w.writeln("// Turn on SAIF power toggle data capture")
  w.writeln("set_power_toggle(POWER_TOGGLE_ON);")
  w.writeln("for(int y = 0; y < in.height(); y++){")
  w.indent()

  w.writeln("// declare the registers storing the stencil window")
  for indices in dpdadag.expand_range(k.edges[startName].dim):
    w.writeln("register vector32 {sig} asm(\"v32r{idx}\");".format(
            sig=compile.mangle((startName, indices)), idx=reg_idx))
    reg_idx += 1
  
  w.writeln("")

  # load first stencil in a row from the image
  w.writeln("// load the stencil window for each scan of row")

  # calculate the range of X
  x_dim =  input_dim[0]  # tuple of (start, end)
  if (x_dim[1] < x_dim[0]):
      x_dim = (x_dim[1], x_dim[0]) # sort the order
  x_range = range(x_dim[0]+1, x_dim[1]+1) # skip the first x value

  # calculate condition on Y for direct load, i.e. stencil not on boundry
  y_dim =  input_dim[1]  # tuple of (start, end)
  y_conditions = []
  y_min = min(y_dim) - k.centroid[1]
  y_max = max(y_dim) - k.centroid[1]
  if (y_min < 0):
      y_conditions.append("y + {} >= 0".format(y_min))
  if (y_max > 0):
      y_conditions.append("y + {} < IN_HEIGHT".format(y_max))
  y_cond_string = str.join(' && ', y_conditions)

  if (y_cond_string != ""):
      w.writeln("if ({cond}) {{".format(cond=y_cond_string))
      w.indent()
      w.writeln("#pragma frequency_hint FREQUENT")
      w.writeln("// not on Y boundry, use direct access")
      w.writeln("")

  for xx in x_range:
      for indices in dpdadag.expand_range(input_dim[1:]):
          sigName_x = "{0}_{1}".format(startName, xx)
          sigName = compile.mangle((sigName_x, indices))
          # HACK: work with multi-channel or single-channel images
          z_idx = 0
          if len(indices) == 2:
              z_idx = indices[1]
      
          # Note that is x is out of range (i.e. x_pos<0), 
          # we need to wrap around, then do a shift ('getl' operation)
          x_pos = xx - k.centroid[0] - 1
          x_idx = x_pos
          if (x_pos < 0):
              x_idx = "IN_WIDTH {0}".format(x_pos)

          w.writeln("{sig} = in_ptr[(y+{yoff})*IN_WIDTH*IN_CHANNELS + ({x})*IN_CHANNELS + {z}];".format(sig=sigName, x=x_idx, yoff=(indices[0]-k.centroid[1]), z=z_idx))
          if (x_pos < 0):
              w.writeln("{sig} = getl32_vv({sig});".format(sig=sigName))


  if (y_cond_string != ""):
      w.unindent()
      w.writeln("} else {")
      w.indent()
      
      for xx in x_range:
          for indices in dpdadag.expand_range(input_dim[1:]):
              sigName_x = "{0}_{1}".format(startName, xx)
              sigName = compile.mangle((sigName_x, indices))
              # HACK: work with multi-channel or single-channel images
              z_idx = 0
              if len(indices) == 2:
                  z_idx = indices[1]
      
              # Note that is x is out of range (i.e. x_pos<0), 
              # we need to wrap around, then do a shift ('getl' operation)
              x_pos = xx - k.centroid[0] - 1
              x_idx = x_pos
              if (x_pos < 0):
                  x_idx = "IN_WIDTH {0}".format(x_pos)

              w.writeln("{sig} = in({x}, y+{yoff}, {z});".format(sig=sigName, x=x_idx, yoff=(indices[0]-k.centroid[1]), z=z_idx))
              if (x_pos < 0):
                  w.writeln("{sig} = getl32_vv({sig});".format(sig=sigName))
      
      w.unindent()
      w.writeln("}")

  w.writeln("")
  # scan a row
  w.writeln("for(int x = 0; x < IN_WIDTH; x++){")
  w.indent()
  
  # shift the stencil window
  w.writeln("// shift the stencil window, and load the new input pixel")
  x_range = range(x_dim[0], x_dim[1]) # skip the last x value, since it is gonna load from mem
  for xx in x_range:
      for indices in dpdadag.expand_range(k.edges[startName].dim[1:]):
          desName_x = "{0}_{1}".format(startName, xx)
          desName = compile.mangle((desName_x, indices))
          srcName_x = "{0}_{1}".format(startName, xx+1)
          srcName = compile.mangle((srcName_x, indices))
          w.writeln("{des} = {src};".format(
                  des=desName, src=srcName))
  w.writeln("")

  # load the new input pixel
  x_offset = x_dim[1] - k.centroid[0]
  w.writeln("// load the update stencil")
  w.writeln("int idx = x + {offset};".format(offset=x_offset))
  w.writeln("if (idx < IN_WIDTH) {")
  w.indent()

  # normal load
  w.writeln("#pragma frequency_hint FREQUENT")
  w.writeln("// not on X boundry, common case")
  w.writeln("")
  if (y_cond_string != ""):
      w.writeln("if ({cond}) {{".format(cond=y_cond_string))
      w.indent()
      w.writeln("#pragma frequency_hint FREQUENT")
      w.writeln("// not on Y boundry, use direct access")
      w.writeln("")

  for indices in dpdadag.expand_range(k.edges[startName].dim[1:]):
      sigName_x = "{0}_{1}".format(startName, x_dim[1])
      sigName = compile.mangle((sigName_x, indices))
      # HACK: work with multi-channel or single-channel images
      z_idx = 0
      if len(indices) == 2:
          z_idx = indices[1]
      
      w.writeln("{sig} = in_ptr[(y+{yoff})*IN_WIDTH*IN_CHANNELS + idx*IN_CHANNELS + {z}];".format(sig=sigName, yoff=(indices[0]-k.centroid[1]), z=z_idx))

  if (y_cond_string != ""):
      w.unindent()
      w.writeln("} else {")
      w.indent()
      
      # use function call to load data, which test boundry condition inside
      for indices in dpdadag.expand_range(k.edges[startName].dim[1:]):
          sigName_x = "{0}_{1}".format(startName, x_dim[1])
          sigName = compile.mangle((sigName_x, indices))
          # HACK: work with multi-channel or single-channel images
          z_idx = 0
          if len(indices) == 2:
              z_idx = indices[1]
      
          w.writeln("{sig} = in(idx, y+{yoff}, {z});".format(sig=sigName, yoff=(indices[0]-k.centroid[1]), z=z_idx))
      
      w.unindent()
      w.writeln("}")
      

  w.unindent()
  w.writeln("} else {")
  w.indent()

  # idx is out of range, then wrap around and do a shift
  for indices in dpdadag.expand_range(k.edges[startName].dim[1:]):
      sigName_x = "{0}_{1}".format(startName, x_dim[1])
      sigName = compile.mangle((sigName_x, indices))
      # HACK: work with multi-channel or single-channel images
      z_idx = 0
      if len(indices) == 2:
          z_idx = indices[1]
      
      #w.writeln("{sig} = in_ptr[(y+{yoff})*IN_WIDTH*IN_CHANNELS + (idx - IN_WIDTH)*IN_CHANNELS + {z}];".format(sig=sigName, yoff=(indices[0]-k.centroid[1]), z=z_idx))
      w.writeln("{sig} = in(idx - IN_WIDTH, y+{yoff}, {z});".format(sig=sigName, yoff=(indices[0]-k.centroid[1]), z=z_idx))
      w.writeln("{sig} = getr32_vv({sig});".format(sig=sigName))

  w.unindent()
  w.writeln("}")
  w.writeln("")
      

  w.writeln("// Start operation")
  # Create a list of (name, index) tuples representing the valid (i.e., evaluated) signal
  validRegs = [(startName, i) for i in dpdadag.expand_range(k.edges[startName].dim)]
  for tapName in k.rtapNames:
    validRegs += [(tapName, i) for i in dpdadag.expand_range(k.edges[tapName].dim)]
  validRegs += [(c[0], [0]) for c in k.constants]
  
  # Make a copy of the list of operations which we can remove stuff from
  unprocessed = dict(k.ops)
  
  # Process all the operations
  while len(unprocessed) > 0:
    progress = False
    for opKey in unprocessed:
      op = k.ops[opKey]
      # Find an operation that can be evaluated
      if compile.opOk(op, validRegs):
        dtype = k.edges[op.result[0]].dtype
        dtype = "vector32"
        # TODO: include integer/fraction width
  
        # TODO: error checking that we have the right number of operands - this should be done in the parser, actually
        # Evaluate it
        if op.name in ['max', 'min', "sum"]:
          write_complex_op_tie(w, op, dtype)
        elif op.name == "mv":
          w.writeln("{dtype} {dst} = {src};".format(dtype=dtype, dst=compile.mangle(op.result), src=compile.mangle(op.operands[0])))
        elif op.name == "add":
          w.writeln("{dtype} {dst} = add32_vv({src});".format(dtype=dtype, dst=compile.mangle(op.result), src=str.join(', ', compile.mangle(op.operands))))
        elif op.name == "sub":
          w.writeln("{dtype} {dst} = sub32_vv({src});".format(dtype=dtype, dst=compile.mangle(op.result), src=str.join(', ', compile.mangle(op.operands))))
        elif op.name == "mult":
          w.writeln("{dtype} {dst} = mult32_vv({src});".format(dtype=dtype, dst=compile.mangle(op.result), src=str.join(', ', compile.mangle(op.operands))))
        elif op.name == "lshift":
          w.writeln("{dtype} {dst} = lshift32_vv({op1}, {op2});".format(dtype=dtype, dst=compile.mangle(op.result), op1=compile.mangle(op.operands[0]), op2=compile.mangle(op.operands[1])))
        elif op.name == "rshift":
          w.writeln("{dtype} {dst} = rshift32_vv({op1}, {op2});".format(dtype=dtype, dst=compile.mangle(op.result), op1=compile.mangle(op.operands[0]), op2=compile.mangle(op.operands[1])))
        elif op.name == "and":
          w.writeln("{dtype} {dst} = and32_vv({op1}, {op2});".format(dtype=dtype, dst=compile.mangle(op.result), op1=compile.mangle(op.operands[0]), op2=compile.mangle(op.operands[1])))
        elif op.name == "or":
          w.writeln("{dtype} {dst} = or32_vv({op1}, {op2});".format(dtype=dtype, dst=compile.mangle(op.result), op1=compile.mangle(op.operands[0]), op2=compile.mangle(op.operands[1])))
        elif op.name == "lt":
          w.writeln("{dtype} {dst} = lt32_vv({op1}, {op2});".format(dtype=dtype, dst=compile.mangle(op.result), op1=compile.mangle(op.operands[0]), op2=compile.mangle(op.operands[1])))
        elif op.name == "lte":
          w.writeln("{dtype} {dst} = lte32_vv({op1}, {op2});".format(dtype=dtype, dst=compile.mangle(op.result), op1=compile.mangle(op.operands[0]), op2=compile.mangle(op.operands[1])))
        elif op.name == "gt":
          w.writeln("{dtype} {dst} = gt32_vv({op1}, {op2});".format(dtype=dtype, dst=compile.mangle(op.result), op1=compile.mangle(op.operands[0]), op2=compile.mangle(op.operands[1])))
        elif op.name == "gte":
          w.writeln("{dtype} {dst} = gte32_vv({op1}, {op2});".format(dtype=dtype, dst=compile.mangle(op.result), op1=compile.mangle(op.operands[0]), op2=compile.mangle(op.operands[1])))
        elif op.name == "inv":
          w.writeln("{dtype} {dst} = inv32_vv({src});".format(dtype=dtype, dst=compile.mangle(op.result), src=compile.mangle(op.operands[0])))

        elif op.name == "mux":
          w.writeln("{dtype} {dst} = mux32_vv({cond}, {op1}, {op2});".format(dtype=dtype, dst=compile.mangle(op.result), \
              cond=compile.mangle(op.operands[0]), op1=compile.mangle(op.operands[1]), op2=compile.mangle(op.operands[2])))
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
  
  for indices in dpdadag.expand_range(k.edges[k.sink].dim):
    #writeln('printf("result: %f\\n", {reg});'.format(reg=compile.mangle((k.sink, indices))))
    # TODO: make this handle depths other than 3
    w.writeln('out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + {z}] = {reg};'
              .format(z=indices[0], reg=compile.mangle((k.sink, indices))))

  w.unindent()
  w.writeln("}")
  w.unindent()
  w.writeln("}")
  w.writeln("")
  w.writeln("// End SAIF power toggle data capture")
  w.writeln("set_power_toggle(POWER_TOGGLE_OFF);")
  w.unindent()
  w.writeln("} // END %s" % k.name)
  w.writeln("\n")

def write_main_tie(w, dag):
  """
  Writes the main function using TIE which makes invocations to all the kernels.
  Arguments are the CodeWriter object to use, and the parsed top-level DAG.
  """
  w.writeln("int main(int argc, char* argv[])");
  w.writeln("{");
  w.indent()

  w.writeln("setup_power_toggle();")
  w.writeln()

  head = dag.head # Get the edge which points to the first kernel
  w.writeln("int width = 256;  // TODO change to match input image")
  w.writeln("int height = 256;  // TODO change to match input image")
  w.writeln("int channels = 3;  // TODO change to match input image")
  w.writeln("Image<int> %s_ref(width, height, channels, 0);" % head)
  w.writeln("%s_ref.load(argv[1]);  // load the input image from file" % head)
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
        for indices in dpdadag.expand_range(k.edges[tapName].dim):
          w.writeln("{type} {sig} = 0; \t// TODO change in value".format(type=tapType, sig=compile.mangle((tapName, indices))))

    # go to the next kernel
    head = k.sink

  w.writeln("")
  w.writeln("// Create a vector zero")
  w.writeln("vector32 zero_v = mv32_sv(0);")

  w.writeln("")
  w.writeln("// Create the input image in vector format")
  w.writeln("Image<vector32> {}_v(width/N, height, channels, zero_v);".format(dag.head))
  w.writeln("shuffle_s2v({0}_ref, {0}_v);".format(dag.head))
  w.writeln('{0}_v.dumpDAT("{0}_v.dat");'.format(dag.head))

  w.writeln("")
  w.writeln("// Construct the pipeline of kernels")
  head = dag.head # Get the edge which points to the first kernel
  while head != dag.tail:
    # Look up the kernel corresponding to the edge sink
    k = dag.kernels[dag.edges[head][1]]

    # Create an image for the output
    channels = len(dpdadag.expand_range(k.edges[k.sink].dim))
    w.writeln("Image<vector32> {0}_v(width/N, height, {1}, zero_v);".format(k.sink, channels))
    w.writeln("Image<int> {0}(width, height, {1}, 0);".format(k.sink, channels))

    # Invoke the kernel
    w.writeln("{k}({src}_v, {sink}_v".format(k=k.name, src=head, sink=k.sink))
    for tapName in k.rtapNames:
      for indices in dpdadag.expand_range(k.edges[tapName].dim):
        w.writeln("\t, {sig}".format(sig=compile.mangle((tapName, indices))))
    w.writeln(");")
    w.writeln("shuffle_v2s({0}_v, {0});".format(k.sink))
    w.writeln('//{0}.save("{0}.bmp");'.format(k.sink))
    w.writeln('{0}_v.dumpDAT("{0}_v.dat");'.format(k.sink))
    w.writeln("") 

    # go to the next kernel
    head = k.sink

  w.writeln("")
  w.writeln("// Create the output image in normal format")
  w.writeln('{}.save("result.bmp");'.format(k.sink))

  w.writeln("")
  w.writeln("// Construct the pipeline of reference kernels")
  head = dag.head # Get the edge which points to the first kernel
  while head != dag.tail:
    # Look up the kernel corresponding to the edge sink
    k = dag.kernels[dag.edges[head][1]]

    # Create an image for the output
    channels = len(dpdadag.expand_range(k.edges[k.sink].dim))
    w.writeln("Image<int> {0}_ref(width, height, {1}, 0);".format(k.sink, channels))

    # Invoke the kernel
    w.writeln("{k}({src}_ref, {sink}_ref".format(k=k.name, src=head, sink=k.sink))
    for tapName in k.rtapNames:
      for indices in dpdadag.expand_range(k.edges[tapName].dim):
        w.writeln("\t, {sig}".format(sig=compile.mangle((tapName, indices))))
    w.writeln(");")
    w.writeln("{0}_ref.equal({0});  // check results".format(k.sink))
    w.writeln("") 

    # go to the next kernel
    head = k.sink




  w.writeln("return 0;");
  w.unindent()
  w.writeln("}");



if __name__ == "__main__":
  import sys
  if len(sys.argv) < 2:
    print "Usage: dada2tie.py DPDA_FILE"
    exit()
  else:
    sourceFile = sys.argv[-1]

  dag = dpdadag.parse_dpda(sourceFile)

  w = compile.CodeWriter("./pipeline.h")
  w.writeln("#ifndef _PIPELINE_H_")
  w.writeln("#define _PIPELINE_H_")
  w.writeln()
  w.writeln("#include \"image.h\"")
  w.writeln("#include \"arch.h\"")
  w.writeln()
  for k in dag.kernels.values():
    write_kernel_tie(w, k, 'header')
  w.writeln("#endif")
  w.close()


  w = compile.CodeWriter("./pipeline.cpp")
  w.writeln("#include \"pipeline.h\"")
  w.writeln()
  w.writeln("#include <xtensa/sim.h>")
  w.writeln("#include <xtensa/hal.h>")
  w.writeln("#include <xtensa/config/core.h>")
  w.writeln("#include <xtensa/config/system.h>")
  w.writeln("#include <xtensa/xt_reftb.h>")
  w.writeln()
  for k in dag.kernels.values():
    write_kernel_tie(w, k, 'source')
  w.close()

  w = compile.CodeWriter("./test.cpp")
  w.writeln("#include <stdio.h>")
  w.writeln("#include <stdlib.h>")
  w.writeln("#include \"image.h\"")
  w.writeln("#include \"arch.h\"")
  w.writeln("#include \"helper.h\"")
  w.writeln("#include \"pipeline_ref.h\"")
  w.writeln("#include \"pipeline.h\"")
  w.writeln("#include <xtensa/sim.h>")
  w.writeln("#include <xtensa/hal.h>")
  w.writeln("#include <xtensa/config/core.h>")
  w.writeln("#include <xtensa/config/system.h>")
  w.writeln("#include <xtensa/xt_reftb.h>")

  write_main_tie(w, dag)
  w.close()
