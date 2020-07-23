#include <time.h>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>
#include <string>
#include <limits>

#include "sort.hpp"

static std::string vector_to_string(std::vector<int> input) 
{
	std::string output = "";
	for (std::vector<int>::iterator it = input.begin(); it != input.end(); it++) {
		output += std::to_string(*it) + " ";
	}
	return output;
}

float meassure(std::vector<int> list, sortCallback_t callback, bool print_output = false)
{
	auto start = std::chrono::system_clock::now();
	callback(list.begin(), list.end());
	auto duration = std::chrono::system_clock::now() - start;
	if (print_output){
		std::cout << "Input: " << vector_to_string(list) << std::endl;
	}
	return duration.count();
}

int main(int argc, char * argv[])
{
	int list_size = 20000000;
	std::cout << "Generating input with "<< list_size << " elements.. " << std::endl;
	std::vector<int> input = Sort::generate_list(50000000);
	//std::cout << "Input: " << vector_to_string(input) << std::endl;
	std::cout << std::endl;
	
	std::cout << "-- Quicksort --" << std::endl;
	float dur1 = meassure(input, Sort::quick_sort);
  	std::cout << "Took " << dur1 / 1000000000.0 << " seconds" << std::endl;

	std::cout << std::endl;

	std::cout << "-- Bubble sort --" << std::endl;
	float dur2 = meassure(input, Sort::quick_sort);
  	std::cout << "Took " << dur2 /1000000000.0 << " seconds" << std::endl;
}