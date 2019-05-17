#include <stdlib.h>
#include <iostream>
#include "islandChallenge.h"

islandChallenge::IslandMap* islandChallenge::buildMap() {
  int grid[10][10] = { 
    {1,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,1,0,0},
    {1,1,0,0,0,0,1,1,0,0},
    {0,1,1,0,0,0,0,1,0,0},
    {0,0,0,0,1,1,0,0,0,0},
    {0,0,1,1,1,1,0,0,0,0},
    {0,0,1,1,1,1,0,0,0,0},
    {0,0,0,0,1,0,0,1,1,1},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0}
  };
  int w = 10, h = 10;
  IslandMap * map = new IslandMap(w, h, grid);
  return map;
}

islandChallenge::IslandMap::IslandMap(int _w, int _h, int _grid[10][10]) : w(_w), h(_h) {
  grid = (int**)malloc(h * sizeof(int*));  
  for (int y = 0; y < h; y++) {
    grid[y] = (int*)malloc(w * sizeof(int*));
    for (int x = 0; x < w; x++) {
      grid[y][x] = _grid[y][x];
    }
  }
}

islandChallenge::IslandMap::~IslandMap() {
  for (int i = 0; i < w; i++) {
    free(grid[i]);
  }
}

void islandChallenge::IslandMap::print() {
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      std::cout << grid[y][x] << " ";
    }
    std::cout << std::endl;
  }

}

void islandChallenge::IslandMap::solve(){
  int uniqueMark = 2;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (grid[y][x] == 1) {
        mark(x, y, uniqueMark);
        uniqueMark++;
      }
    }
  }
}

//nonpublic function to find neighbours of tlie
std::vector<std::pair<int, int>> islandChallenge::IslandMap::mark(int x, int y, int marker) {
  std::vector <std::pair<int, int>> neighbours;

  grid[y][x] = marker;
  //left
  if (x - 1 >= 0 && (grid[y][x - 1] > marker || grid[y][x - 1] == 1))
    neighbours.push_back(std::pair<int, int>(x - 1, y));
  //up
  if (y - 1 >= 0 && (grid[y - 1][x] > marker || grid[y - 1][x] == 1))
    neighbours.push_back(std::pair<int, int>(x, y - 1));
  //right
  if (x + 1 < w && (grid[y][x + 1] > marker || grid[y][x + 1] == 1))
    neighbours.push_back(std::pair<int, int>(x + 1, y));
  //down
  if (y + 1 < h && (grid[y + 1][x] > marker || grid[y + 1][x] == 1))
    neighbours.push_back(std::pair<int, int>(x, y + 1));
  
  //upperleft
  if (y - 1 >= 0 && x - 1 >= 0 && (grid[y - 1][x - 1] > marker || grid[y - 1][x - 1] == 1))
    neighbours.push_back(std::pair<int, int>(x - 1, y - 1));
  //upperright
  if (y - 1 >= 0 && x + 1 < w && (grid[y - 1][x + 1] > marker || grid[y - 1][x + 1] == 1))
    neighbours.push_back(std::pair<int, int>(x + 1, y - 1));
  //downleft
  if (y + 1 < h && x - 1 >= 0 && (grid[y + 1][x - 1] > marker || grid[y + 1][x - 1] == 1))
    neighbours.push_back(std::pair<int, int>(x - 1, y + 1));
  //downright
  if (y + 1 < h && x + 1 < w && (grid[y + 1][x + 1] > marker || grid[y + 1][x + 1] == 1))
    neighbours.push_back(std::pair<int, int>(x + 1, y + 1));

  for (auto it = neighbours.begin(); it != neighbours.end(); it++) {
    if (it->first == 8 && it->second == 2)
      int debug = true;
    mark(it->first, it->second, marker);
  }
  
  return neighbours;
}