#ifndef __SORT_H__
#define __SORT_H__

#include <vector>

class Sort {
public:
	static std::vector<int> generate_list(int amount = 10, int max = 100, int min= 0);
	static void quick_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	static void bubble_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif;