GCC=g++

all: main.cpp graph.o util.o
	$(GCC) main.cpp graph.o util.o

graph.o: graph.cpp graph.hpp
	$(GCC) -c graph.cpp 

util.o: util.cpp util.hpp
	$(GCC) -c util.cpp 