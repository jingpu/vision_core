#include ../Makefile.build

TARGET = main
CXX = g++
CFLAGS =  $(COREFLAGS) -I../lib -O -g


./%.o : ./%.cpp 
	$(CXX) -c $(CFLAGS) $< -o $@

./%.o : ../lib/%.cpp 
	$(CXX) -c $(CFLAGS) $< -o $@


$(TARGET): datatypes.o qdbmp.o pipeline_ref.o main.o
	$(CXX) $^  -o $@


run: $(TARGET)
	./$(TARGET) raw_256_256_1.jjm



clean:
	rm -f $(TARGET)
	rm -f *.i *.ii *.s *.S *.o
	rm -f trace.log prof.*
