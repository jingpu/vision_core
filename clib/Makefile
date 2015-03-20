# Default target 
default: all

# Tensilica compiler
CXX := xt-xc++
CC := xt-xcc
# Tensilica Instruction Set Simulator
ISS = xt-run

.PHONY: all clean run

TARGET = test
all: $(TARGET)

# Target files
SOURCES = datatypes.cpp qdbmp.c pipeline.cpp test.cpp test_hw.cpp
HEADERS = datatypes.h image.h qdbmp.h arch.h helper.h pipeline_ref.h pipeline.h

OBJECTS := $(SOURCES:.c=.o)
OBJECTS := $(OBJECTS:.cpp=.o)

#############################
# Build Flags
#############################

# Target program Linker Support Package
# See the LSP Reference Manual for more information
# Use "min-rt" LSP
#LSPFLAGS= -lhal -mlsp=min-rt

# Use simple "sim" LSP to run with ISS
LSPFLAGS= -lhal -mlsp=sim

TDK_DIR = ../tie_out_n16
#COREFLAGS= --xtensa-system=$(XTENSA_SYSTEM) --xtensa-core=$(XTENSA_CORE) 
COREFLAGS= --xtensa-params=$(TDK_DIR)

CFLAGS =  $(COREFLAGS) -O3 -fno-unroll-loops -g -fexceptions -keep_min
APP_CFLAGS = $(COREFLAGS) $(LSPFLAGS) -g -lreftb

##############################
# Simulation arguments
#############################
SIM_ARGS = --xtensa-params=$(TDK_DIR) \
	--memlimit=512  --turbo  --client_cmds="isa_profile --disable" --summary  
#	--client_cmds="ferret --warn-unaligned" 
TAR_ARGS = ./inp.bmp


# Make object
./%.o : ./%.c 
	$(CXX) -c $(CFLAGS) $< -o $@

./%.o : ./%.cpp 
	$(CXX) -c $(CFLAGS) $< -o $@

# Make executables
test: datatypes.o qdbmp.o pipeline.o test.o 
	$(CXX) $^  $(APP_CFLAGS) -o $@

test_hw: datatypes.o qdbmp.o pipeline.o test_hw.o
	$(CXX) $^  $(APP_CFLAGS) -o $@

run: $(TARGET)
	$(ISS)  $(SIM_ARGS) $(TARGET)  $(TAR_ARGS) 

clean:
	rm -f $(TARGET)
	rm -f *.i *.ii *.s *.S *.o

cleanall: clean
	rm -f *.dat

