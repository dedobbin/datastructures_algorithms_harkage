#include <iostream>
#include "graph.hpp"

int main(int argc, char* argv[])
{
	auto graph = Graph(100);
	graph.generate();
	graph.print();
}
