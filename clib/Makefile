# Default target 
default: all

# Tensilica compiler
CXX := xt-xc++
CC := xt-xcc
# Tensilica Instruction Set Simulator
ISS = xt-run

.PHONY: all clean run

TARGET = test  \
	test_NMS_10.iss		test_NMS_10.rtl		\
        test_downCast_13.iss	test_downCast_13.rtl	\
	test_downCast_15.iss   	test_downCast_15.rtl 	\
        test_Resp_5.iss   	test_Resp_5.rtl \
        test_lambda_arris_v3lua_line43_10.iss 	test_lambda_arris_v3lua_line43_10.rtl

RUN_TARGET =  	test_downCast_15.iss	
all: $(TARGET)

#############################
# Build Flags
#############################

TDK_DIR = ../tie_out_sn32
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
	--client_cmds="isa_profile --disable " \
	--mem_model --icsize=4K --dcsize=4K --dcways=1 
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

