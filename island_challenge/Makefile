GCC=g++

all: main.cpp island_challenge.o
	$(GCC) main.cpp island_challenge.o

island_challenge.o: island_challenge.cpp island_challenge.hpp
	$(GCC) -c island_challenge.cpp 

clean:
	rm -f *.gch;\
	rm -f *.o;\
	rm -f a.out;

.PHONY : all clean
.SILENT: clean