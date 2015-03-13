SOURCES = datatypes.cpp qdbmp.c pipeline.cpp 
HEADERS = datatypes.h image.h qdbmp.h 
CXX = xt-xc++
#CXX = g++
CC = xt-xcc

ISS = xt-run

TDK_DIR = ../tie_out
#CFLAGS =  -g --xtensa-params=$(TDK_DIR) -fexceptions -Wl,-u -Wl,malloc -lferret
CFLAGS =  -O2 -g --xtensa-params=$(TDK_DIR) -fexceptions -keep_min

TARGET = pipeline
SIM_ARGS = --xtensa-params=$(TDK_DIR) --summary  \
	--memlimit=512 --turbo --client_cmds="isa_profile --disable"
#	--client_cmds="ferret --warn-unaligned"
TAR_ARGS = ./inp.bmp

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	xt-xc++ $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	$(ISS)  $(SIM_ARGS) $(TARGET)  $(TAR_ARGS) 

clean:
	rm -f $(TARGET)
	rm -f *.i *.ii *.s *.S

