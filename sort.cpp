#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <random>
#include "sort.h"

std::vector<int> Sort::generate_list(int amount, int max, int min) {
	std::vector<int> list(10);
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<> distribution(min, max);
	for (std::vector<int>::iterator it = list.begin(); it < list.end(); it++) {
		*it = distribution(generator);
	}
	return list;
}

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

void Sort::bubble_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	bool finished = false;
	do {
		//assume we are finished, if turns out to not be the case, this bool is flipped
		finished = true;
		for (std::vector<int>::iterator it = begin; it < end - 1; it++) {
			if (*it > *(it + 1)) {
				int tmp = *it;
				*it = *(it + 1);
				*(it + 1) = tmp;
				finished = false;
			}
		}
	} while (!finished);
}