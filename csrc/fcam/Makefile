#include ../Makefile.build

TARGET = pipeline
CXX = g++
CFLAGS =  $(COREFLAGS) -I../lib -O -g


./%.o : ./%.cpp 
	$(CXX) -c $(CFLAGS) $< -o $@

./%.o : ../lib/%.cpp 
	$(CXX) -c $(CFLAGS) $< -o $@


$(TARGET): datatypes.o qdbmp.o pipeline.o
	$(CXX) $^  -o $@


run: $(TARGET)
	./$(TARGET) inp.jjm

clean:
	rm -f $(TARGET)
	rm -f *.i *.ii *.s *.S *.o
	rm -f trace.log prof.*
