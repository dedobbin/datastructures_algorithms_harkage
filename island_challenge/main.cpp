#include <iostream>
#include "island_challenge.hpp"

int main(int argc, char * argv[]) {
	std::cout << "-- Island challenge --" << std::endl;
	islandChallenge::IslandMap * map = islandChallenge::buildMap();
	std::cout << std::endl << "-------------input" << std::endl;
	map->print();
	map->solve();
	std::cout << std::endl << "-------------output" << std::endl;
	map->print();
}