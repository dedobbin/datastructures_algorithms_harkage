#include <time.h>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>
#include <string>
#include <limits>

#include "sort.h"

static std::string vector_to_string(std::vector<int> input) {
	std::string output = "";
	for (std::vector<int>::iterator it = input.begin(); it != input.end(); it++) {
		output += std::to_string(*it) + " ";
	}
	return output;
}

int main(int argc, char * argv) {
	std::vector<int> list(10);
	std::random_device seeder;
	std::mt19937 generator(seeder());
	std::uniform_int_distribution<> distribution(0, 10);
	for (std::vector<int>::iterator it = list.begin(); it < list.end(); it++) {
		*it = distribution(generator);
	}
	std::cout << "Original vector: " << vector_to_string(list) << std::endl;
	
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	//Sort::quick_sort(list.begin(), list.end());
	Sort::bubble_sort(list.begin(), list.end());
	std::chrono::duration<double> duration_seconds = std::chrono::system_clock::now() - start;

	std::cout << "Altered vector: " << vector_to_string(list) << std::endl;
	std::cout.precision(std::numeric_limits<double>::digits10);
	std::cout << "Took: " << duration_seconds.count() << " seconds" << std::endl;
	getchar();
	return 0;
}