#include <time.h>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>
#include <string>
#include <limits>

#include "islandChallenge.h"
#include "sort.h"

/**
* Messing arround with algorithms to get more used to cpp
**/

static std::string vector_to_string(std::vector<int> input) {
	std::string output = "";
	for (std::vector<int>::iterator it = input.begin(); it != input.end(); it++) {
		output += std::to_string(*it) + " ";
	}
	return output;
}

int main(int argc, char * argv[]) {
  
  /*** island challenge ***/
  std::cout << "-- Island challenge --" << std::endl;
  islandChallenge::IslandMap * map = islandChallenge::buildMap();
  std::cout << "------------input:" << std::endl;
  map->print();
  map->solve();
  std::cout << "------------output:" << std::endl;
  map->print();
  std::cout << std::endl;


  /*** sorting ***/
  std::cout << "-- Sorting --" << std::endl;
	std::vector<int> list = Sort::generate_list();
	std::cout << "Original vector: " << vector_to_string(list) << std::endl;
	
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	//Sort::bubble_sort(list.begin(), list.end());
	Sort::quick_sort(list.begin(), list.end());
	std::chrono::duration<double> duration_seconds = std::chrono::system_clock::now() - start;

	std::cout << "Altered vector: " << vector_to_string(list) << std::endl;
	std::cout.precision(std::numeric_limits<double>::digits10);
	std::cout << "Sorting took: " << duration_seconds.count() << " seconds" << std::endl;
	getchar();
	return 0;
}