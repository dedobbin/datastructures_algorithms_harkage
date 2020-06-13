#ifndef __UTIL_H__
#define __UTIL_H__

#include <limits>
#include <random>
namespace Util {
  class Random {
  public:
    Random(int min = 0, int max = std::numeric_limits<unsigned>::max()/2);
    int generate();
  private:
    std::mt19937 generator;
    std::uniform_int_distribution<> distribution;
  };
}
#endif