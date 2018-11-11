#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include "sort.h";

void Sort::quick_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	//Grab pivot, last value.
	int pivot_value = *(end - 1);
	int wall_offset = 0;

	for (std::vector<int>::iterator it = begin; it < end; it++) {
		//If current value is smaller than pivot value, swamp it with element right next to 'the wall'
		//and move 'the wall' one to the right.
		if (*it < pivot_value) {
			int tmp = *it;
			*it = *(begin + wall_offset);
			*(begin + wall_offset) = tmp;
			wall_offset++;
		}
	}
	//Swap pivot value with element right next to 'the wall'
	*(end - 1) = *(begin + wall_offset);
	*(begin + wall_offset) = pivot_value;


	if (wall_offset == 0)
		return;

	Sort::quick_sort(begin, begin + wall_offset);
	Sort::quick_sort(begin + wall_offset, end);
	return;
}