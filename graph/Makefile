GCC=g++

all: main.cpp graph.o util.o
	$(GCC) main.cpp graph.o util.o

graph.o: graph.cpp graph.hpp
	$(GCC) -c graph.cpp 

util.o: util.cpp util.hpp
	$(GCC) -c util.cpp 

clean:
	rm -f *.gch;\
	rm -f *.o;\
	rm -f a.out;

.PHONY : all clean
.SILENT: clean