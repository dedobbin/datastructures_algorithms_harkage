#ifndef __islandChallenge_H__
#define __islandChallenge_H__

#include <vector>

/**
* A fictional assignement. 
* When given a map (2D array), find the different islands.
* 0 = water
* 1 = land
**/

namespace islandChallenge {
  class IslandMap;
  IslandMap* buildMap();
}



class islandChallenge::IslandMap {
public:
  IslandMap(int w, int h, int map[10][10]);
  ~IslandMap();
  void print();
  void solve();
  const int h, w;
private:
  std::vector<std::pair<int, int>> mark(int x, int y, int marker);
  int** grid;
};

#endif