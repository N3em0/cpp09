#include "CompareSecond.hpp"

CompareSecond::CompareSecond(int target) : target(target) {}

CompareSecond::CompareSecond() {}

CompareSecond::CompareSecond(const CompareSecond &src) : target(src.target) {}

CompareSecond &CompareSecond::operator=(const CompareSecond &rhs)
{
  if (this != &rhs)
  {
    this->target = rhs.target;
  }
  return (*this);
}

CompareSecond::~CompareSecond() {}

bool CompareSecond::operator()(const std::pair<int, int> &p) const
{
  return target == p.second;
}
