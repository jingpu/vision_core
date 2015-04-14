#! /usr/bin/python

# dpdadag.py
# Read in a DPDA YAML file and create an internal representation
#
# Steven Bell <sebell@stanford.edu>
# May 2014

import yaml
import re
import numpy as np
from IPython import embed

class Dag:
  """
  Class representing a kernel DAG.  The DAG itself consists of a dictionary
  of kernels (indexed by name), and a dictionary of named edges.  This layout
  closely matches the actual DPDA, preserves names, and allows easy forward
  and reverse traversals.
  In the stencil DAG, all of the edges are implicit.  They are just named on
  both ends (although they have to be real signals underneath).

  The DAG class has a single head and tail (for now), which reference
  edges to kernels.
  """
  def __init__(self):
    self.head = None
    self.tail = None
    self.kernels = {}
    self.edges = {}

  def add_kernel(self, k):
    # Add the kernel, indexed by name
    self.kernels[k.name] = k

    # Add or complete its edges
    # Each edge is a list of two names, referring to the kernels it connects
    # The first is the edge source (kernel's sink), the second is the target
    if self.edges.has_key(k.src):
      self.edges[k.src][1] = k.name
    else:
      self.edges[k.src] = [None, k.name]

    if self.edges.has_key(k.sink):
      self.edges[k.sink][0] = k.name
    else:
      self.edges[k.sink] = [k.name, None]

class Kernel:
  """
  Class representing a single stencil kernel.

  Each kernel contains a DAG of DPDA ops which perform the map/reduce.
  These are explicit; the signals have to be named and typed beforehand.
  """
  def __init__(self):
    self.name = None
    self.src = None
    self.sink = None
    self.constants = [] # Tuple of (register name, value)
    self.specialRegs = [] # list of regist names

    #self.mapOps = {}
    #self.mapEdges = {}
    self.ops = {}
    self.edges = {}

  def __repr__(self):
    return self.name + " : " + self.src + " => " + self.sink

  def create_subarray(self, dim):
    # TODO: This really ought to be an edge method
    """
    Helper method for creating N-dimensional arrays of Signals.
    Recursively calls itself on successively smaller numbers of dimensions.
    """
    if len(dim) == 0:
      raise ValueError("Signal must have non-zero number of dimensions")

    n = abs(dim[0][0] - dim[0][1]) + 1 # Width of the first dimension
    if len(dim) == 1:
      return [Signal() for s in range(n)]
    else:
      return [self.create_subarray(dim[1:]) for d in range(n)]

  def add_declaration(self, decl):
    # TODO: This ought to be an edge method
    """
    Adds a new register declaration to the kernel.  This parses the declaration,
    adds the name to the declarations list, and creates the corresponding Edge
    object with the appropriate Signal array.
    """
    bits = decl.split()

    # Parse the data type description
    if bits[0] == 'bool':
      dtype = 'bool'
      intWidth = 1
      fracWidth = 0
    else:
      matches = re.search(r'(fix|ufix|float)_(\d+)_(\d+)', bits[0])
      if matches is not None:
        dtype = matches.group(1)
        intWidth = int(matches.group(2))
        fracWidth = int(matches.group(3))
      else:
        raise RuntimeError("Failed to parse signal declaration '%s'" % decl)

    # Create the signal matrix
    (name, dims) = parse_signal(bits[1])
    if len(dims) == 0:
      dims = [(0,0)] # Force singleton signals to have dimension 1

    s = self.create_subarray(dims)

    e = Edge()
    e.dtype = dtype
    e.intWidth = intWidth
    e.fracWidth = fracWidth
    e.dim = dims # Needed for decoding
    e.signals = s
    self.edges[name] = e # Name the edge, add it to the kernel

  def add_constant(self, decl):
    cName = "c_%s" % decl.replace('.', '_').replace('-', 'n').replace('+', '')
    # avoid adding the same constant
    if (cName, decl) in self.constants:
      return cName
    
    self.constants.append((cName, decl))
    # TODO: infer datatype and width
    e = Edge()
    e.dim = [(0,0)]
    s = Signal()
    s.src = decl
    e.signals = [s]
    self.edges[cName] = e
    return cName

class Op:
  """
  Class representing a single DPDA operation within a map/reduce tree.
  Result is a tuple (name, indices) with the name and signal index of the
  output edge.  operands is a list of such tuples representing the input edges.
  """
  def __init__(self, name=None):
    self.name = name
    self.operands = []
    self.result = None

  def __repr__(self):
    return self.name + "  " + str(self.result) + " <-- " + str(self.operands)

class Signal:
  """
  Class representing a single signal from one operation to another. In
  hardware, there will typically be registers on these edges.  In software sim,
  these are intermediate variables.
  """
  def __init__(self):
    self.src = None
    self.sinks = []

  def __repr__(self):
    return "{src} -> {sink}".format(src = self.src, sink=self.sinks)

class Edge:
  """
  Class representing a data connection from one operation to another,
  consisting of one or more signals.
  """ 
  def __init__(self):
    self.dtype = ''
    self.intWidth = 0
    self.fracWidth = 0
    self.dim = None
    self.signals = None

  def __getitem__(self, index):
    """
    Returns a single signal indexed by a list of integer indices
    """
    if type(index) != list:
      raise TypeError("Input index must be list of indices")
    if len(index) != len(self.dim):
      raise IndexError("Attempted to look up %d-dimensional signal with %d dimensions" % \
                       (len(self.dim), len(index)) )
    s = self.signals
    i = 0
    while type(s) is list:
      s = s[index[i]] # TODO: account for definition direction here
      i += 1

    return s

  def __setitem__(self, index, item):
    raise NotImplementedError("wait for it....")

  def __repr__(self):
    return "{dt}_{iw}_{fw}  {dim}".format(dt=self.dtype, iw=self.intWidth, fw=self.fracWidth, dim=self.dim)

def parse_signal(sliceString):
  """
  Reads a signal definition or slice reference, and returns a tuple with the
  corresponding base signal name and slice dimensions.
  The slice dimensions are packaged as a list of tuples:
    [(start, end), (start, end)]
  """
  # Split into the base name and everything else
  match = re.search(r'(\w+)(.*)', sliceString)
  baseName = match.group(1)
  remainder = match.group(2)
  dimensions = []

  # Iterate through, grabbing the first slice each time
  while remainder is not '':
    indices = re.search(r'\[(\d+)(?:\:(\d+))?\](.*)', remainder)
    if indices.group(2) is not None:
      dimensions.append( (int(indices.group(1)), int(indices.group(2))) )
    else: # There isn't a second index; use the single index twice
      dimensions.append( (int(indices.group(1)), int(indices.group(1))) )
    remainder = indices.group(3)

  return (baseName, dimensions)
 
def expand_range(ranges):
  """
  Take a list of tuples containing ranges for each dimension, and return
  a list of lists of indices covering the range.  The last dimension forms
  the inner iteration.
  """
  if len(ranges) == 0:
    return [0]

  # Rip off the first range and compute the indices for it
  base = ranges[0]
  if base[0] <= base[1]:
    baseRange = range(base[0], base[1] + 1, 1)
  else:
    baseRange = range(base[0], base[1] - 1, -1)

  if len(ranges) == 1:
    return [[r] for r in baseRange]
  else:
    return [[i] + j for i in baseRange \
                    for j in expand_range(ranges[1:])]

def match_slices(a, b):
  """
  Check that the dimensions of two slices are the same.  Leading singleton
  dimensions are ignored.
  TODO: is this the right restriction?
  """
  # Calculate widths in each dimension
  a = [abs(dim[0] - dim[1]) + 1 for dim in a]
  b = [abs(dim[0] - dim[1]) + 1 for dim in b]

  # Remove leading singleton dimensions, but leave at least one dimension
  while len(a) > 1 and a[0] == 1:
    a.remove(1)
  while len(b) > 1 and b[0] == 1:
    b.remove(1)

  return a == b

def parse_kernel(name, blob):
  """
  Parses a single named kernel from the DPDA blob and returns a kernel object.
  """
  # Grab all the metadata for the kernel, and pull out useful bits
  kMeta = blob['top'][name]
  kConfig = blob[kMeta['Config']]
  kMap = blob[kConfig['Map']][0] # TODO: always a double-deep list?
  kReduce = blob[kConfig['Reduce']][0]

  # Create a kernel object
  kernel = Kernel()
  kernel.name = name
  kernel.src = kMeta['PixelIn'][0]
  kernel.sink = kMeta['PixelOut'][0]

  kernel.sizeIn = kConfig['StencilIn']
  kernel.sizeOut = kConfig['StencilOut']
  kernel.centroid = kConfig['Centroid']

  # grab the special register and input image singal names
  for line in kConfig['RPixelPart']:
    sigName = parse_signal(line.split()[1])[0]
    if sigName == "centroid_pos" or sigName == "pixel_out_pos":
      kernel.specialRegs.append(sigName)
    else:
      # HACK here assumes that 'RPixelPart' has only one input image element
      kernel.ppoutName = sigName

  # list of tap signal names used by reduce kernel
  kernel.rtapNames = [parse_signal(sig.split()[1])[0] for sig in kConfig['RTap'] ]

  # For the map, iterate through each line and build the op graph
  uniqueifier = 0
  for instruction in kReduce:
    if instruction is None:
      # Comment line that has been discarded, just carry on
      continue

    # Register declaration
    if instruction.startswith(('fix', 'ufix', 'float', 'bool')):
      kernel.add_declaration(instruction)
    # Operation
    else:
      bits = instruction.split()
      opcode = bits[0]
      uniqueId = "%s_%d" % (opcode, uniqueifier)
      uniqueifier += 1

      # Parse and expand the signal slice for the operation result
      (tName, tSlice) = parse_signal(bits[1])
      if tName not in kernel.edges:
        raise LookupError("Signal '%s' was not defined before use!" % tName)
      target = kernel.edges[tName]

      # Fill out any unspecified dimensions of the signal by concatenating
      # the full signal dimensions
      tSlice = tSlice + target.dim[len(tSlice):]
      tIndices = expand_range(tSlice)


      # Do the same for each of the operands
      sources = []
      sNames = []
      sIndices = []
      for bit in bits[2:]:
        # Can be a signal or constant, so handle both
        isConstant = bit.startswith(('-', '+', '.')) or bit[0].isdigit()
        if isConstant:
          sName = kernel.add_constant(bit) # TODO: what if it already exists?
          sSlice = [(0,0)] # Only one constant; it gets copied as many times as needed
        else:
          (sName, sSlice) = parse_signal(bit)

        if sName not in kernel.edges:
          raise LookupError("Signal '%s' was not defined before use!" % sName)
        sources.append(kernel.edges[sName])
        sNames.append(sName)
        sSlice = sSlice + sources[-1].dim[len(sSlice):]
        sIndices.append(expand_range(sSlice))

        # HACK: If we have a constant, make as many copies as we need
        # We don't do this with the sSlice size, because the constant is a scalar
        if isConstant:
          sIndices[-1] = sIndices[-1] * len(tIndices)
        
      # If this is a reduction operation
      if len(tIndices) == 1 and opcode in ['sum', 'min', 'max']:
        if len(sIndices) != 1: # Could also check len(sources)
          raise ParseError("Can't parse reduction with multiple operands")

        target[tIndices[0]].src = uniqueId
        # For each of the operand elements, add a sink
        # Assume reduction has a single source name
        for j in range(len(sIndices[0])):
          sources[0][sIndices[0][j]].sinks.append(uniqueId)

        # Create the DPDA operation object
        op = Op(opcode)
        op.result = (tName, tIndices[i]) # Package the name and index
        op.operands = [(sNames[0], si) for si in sIndices[0]] # Treat each reduction element as an operand

        #embed()
        # Add the operation data structure, indexed by unique id
        kernel.ops[uniqueId] = op

      # If this is a regular operation
      elif opcode in ['mv', 'add', 'sub', 'mult', 'div', 'inv', 'mux', 'gt', 'lt', 'clamp', 'lshift', 'rshift', 'gte', 'lte', 'and', 'or', 'eq', 'ne', 'not', 'abs']:
        for i in range(len(tIndices)):
          sliceId = "%s_%d" % (uniqueId, i)
          target[tIndices[i]].src = sliceId
          # For each of the operands, add a sink
          for j in range(len(sIndices)):
            sources[j][sIndices[j][i]].sinks.append(sliceId)

          # Create the DPDA operation object
          op = Op(opcode)
          op.result = (tName, tIndices[i]) # Package the name and index
          op.operands = [(sNames[j], sIndices[j][i]) for j in range(len(sIndices))]
          # Add the operation data structure, indexed by unique id
          kernel.ops[sliceId] = op


      else:
        raise NotImplementedError("Encountered unknown opcode '%s' in "
                                  "kernel \"%s\" instruction \"%s\"" 
                                  % (opcode, kernel.name, instruction))

  return kernel

def parse_dpda(filename):
  """
  Parses an entire DPDA file and returns the complete stencil path DAG object.
  """
  # Read the source file and parse the YAML
  # Comments automatically get stripped out here
  blob = yaml.load(open(filename, 'r'))
  
  # Grab the top-level module
  top = blob['top']
  
  # For now, the DPDA pipeline is guaranteed to be linear (although this
  # might change in the future).
  
  keywords = ['input_image', 'output_image', 'IfcCtl', 'MaximumDomainSize', 'MaximumTileSize']

  graph = Dag()
  graph.head = top['input_image'][0]
  graph.tail = top['output_image'][0]
  
  for k in top:
    # Everything in the top level that isn't a keyword must be a stencil
    if k in keywords:
      continue

    kernel = parse_kernel(k, blob)
  
    # Add it to the graph.  This also creates the edges.
    graph.add_kernel(kernel)
  return graph

if __name__ == "__main__":
  import sys
  if len(sys.argv) < 2:
    print "Specify a file to parse on the command line"
    exit()

  sourceFile = sys.argv[1]
  graph = parse_dpda(sourceFile)

  print graph.kernels
  print graph.edges
