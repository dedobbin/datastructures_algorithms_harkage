#ifndef __SORT_H__
#define __SORT_H__

#include <vector>

class Sort {
public:
	static void quick_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	static void bubble_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif;