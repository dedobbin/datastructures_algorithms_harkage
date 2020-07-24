GCC=g++

all: main.cpp sort.o
	$(GCC) main.cpp sort.o

sort.o: sort.cpp sort.hpp
	$(GCC) -c sort.cpp 

clean:
	rm -f *.gch;\
	rm -f *.o;\
	rm -f a.out;

.PHONY : all clean
.SILENT: clean