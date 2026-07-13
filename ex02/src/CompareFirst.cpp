#include "CompareFirst.hpp"

CompareFirst::CompareFirst(int target) : target(target) {}

CompareFirst::CompareFirst() {}

CompareFirst::CompareFirst(const CompareFirst &src) : target(src.target) {}

CompareFirst &CompareFirst::operator=(const CompareFirst &rhs)
{
  if (this != &rhs)
  {
    this->target = rhs.target;
  }
  return (*this);
}

CompareFirst::~CompareFirst() {}

bool CompareFirst::operator()(const std::pair<int, int> &p) const
{
  return target == p.first;
}
