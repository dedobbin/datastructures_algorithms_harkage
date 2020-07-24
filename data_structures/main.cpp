#include "linked_list.hpp"

int main (int argv, char* argc[])
{
	auto list = new LinkedList<int>();
	list->insert(1);
	list->insert(2);
	list->insert(3);
	std::cout << *list << std::endl;
	delete(list);
}