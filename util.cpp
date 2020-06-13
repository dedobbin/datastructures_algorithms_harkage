#include "util.h"

#include "iostream"

Util::Random::Random(int min, int max) {
  std::random_device seed;
  this->generator = std::mt19937(seed());
  this->distribution = std::uniform_int_distribution<>(min, max);
}

int Util::Random::generate() {
  return this->distribution(this->generator);
}

