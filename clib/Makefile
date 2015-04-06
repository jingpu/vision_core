# Default target 
default: all

# Tensilica compiler
CXX := xt-xc++
CC := xt-xcc
# Tensilica Instruction Set Simulator
ISS = xt-run

.PHONY: all clean run

TARGET = test test_rtl test_iss \
	test_lambda.iss test_lambda.rtl \
	test_cast13.iss test_cast13.rtl \
	test_cast15.iss test_cast15.rtl \
	test_resp.iss   test_resp.rtl \
	test_nms.iss    test_nms.rtl
RUN_TARGET = test
all: $(TARGET)

#############################
# Build Flags
#############################

TDK_DIR = ../tie_out_n16
#COREFLAGS= --xtensa-system=$(XTENSA_SYSTEM) --xtensa-core=$(XTENSA_CORE) 
COREFLAGS= --xtensa-params=$(TDK_DIR)

CFLAGS =  $(COREFLAGS) -O3 -fno-unroll-loops -g -fexceptions -keep_min

ISS_LDFLAGS =  $(COREFLAGS) -g -lhal -mlsp=sim -lreftb 
RT_LDFLAGS  =   $(COREFLAGS)  -g -lhal -mlsp=min-rt -lreftb 


##############################
# Simulation arguments
#############################
SIM_ARGS = --xtensa-params=$(TDK_DIR) \
	--memlimit=512  --turbo  --summary  \
	--client_cmds="isa_profile --disable " 
#	--mem_model --icsize=4K --dcsize=4K --dcways=1 
#       --client_cmds="profile --dcmiss --cycles prof"
#	--client_cmds="trace --level=0 trace.log" 
TAR_ARGS = ./inp.bmp


# Make object
./%.o : ./%.c 
	$(CXX) -c $(CFLAGS) $< -o $@

./%.o : ./%.cpp 
	$(CXX) -c $(CFLAGS) $< -o $@

./test_rtl.o : test_hw.cpp 
	$(CXX) -c $(CFLAGS)  -DRTL_SIM $< -o $@

./%.rtl.o : ./%.cpp 
	$(CXX) -c $(CFLAGS)  -DRTL_SIM $< -o $@

# Make executables
test: datatypes.o qdbmp.o pipeline.o test.o 
	$(CXX) $^  $(ISS_LDFLAGS) -o $@

test_iss: datatypes.o qdbmp.o pipeline.o test_hw.o
	$(CXX) $^  $(ISS_LDFLAGS) -o $@

test_rtl: datatypes.o qdbmp.o pipeline.o test_rtl.o
	$(CXX) $^  $(RT_LDFLAGS) -o $@

./%.iss: datatypes.o qdbmp.o pipeline.o ./%.o
	$(CXX) $^  $(ISS_LDFLAGS) -o $@

./%.rtl: datatypes.o qdbmp.o pipeline.o ./%.rtl.o
	$(CXX) $^  $(RT_LDFLAGS) -o $@



run: $(RUN_TARGET)
	$(ISS)  $(SIM_ARGS) $(RUN_TARGET)  $(TAR_ARGS) 

clean:
	rm -f $(TARGET)
	rm -f *.i *.ii *.s *.S *.o
	rm -f trace.log prof.*

