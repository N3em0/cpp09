#include "CompareSecond.hpp"

CompareSecond::CompareSecond(int target) : target(target) {}

CompareSecond::CompareSecond() {}

CompareSecond::CompareSecond(const CompareSecond &) {}

CompareSecond &CompareSecond::operator=(const CompareSecond &)
{
  return (*this);
}

CompareSecond::~CompareSecond() {}

bool CompareSecond::operator()(const std::pair<int, int> &p) const
{
  return target == p.second;
}
