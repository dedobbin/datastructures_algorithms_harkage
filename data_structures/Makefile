GCC=g++

all: main.cpp linked_list.hpp
	$(GCC) main.cpp linked_list.hpp -g
	
clean:
	rm -f *.gch;\
	rm -f *.o;\
	rm -f a.out;

.PHONY : all clean
.SILENT: clean