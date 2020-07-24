#include "linked_list.hpp"

int main (int argv, char* argc[])
{
	auto list = new LinkedList<int>();
	list->insert(1);
	list->insert(2);
	list->insert(3);
	std::cout << *list << std::endl;

	auto list2 = new LinkedList<std::string>();
	list2->insert("one");
	list2->insert("two");
	list2->insert("three");
	std::cout << *list2 << std::endl;


	delete(list);
	delete(list2);
}