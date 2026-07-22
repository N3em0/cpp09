#include "SecondEqual.hpp"

SecondEqual::SecondEqual(int target) : target(target) {}

SecondEqual::SecondEqual() {}

SecondEqual::SecondEqual(const SecondEqual &src) : target(src.target) {}

SecondEqual &SecondEqual::operator=(const SecondEqual &rhs)
{
  if (this != &rhs)
  {
    this->target = rhs.target;
  }
  return (*this);
}

SecondEqual::~SecondEqual() {}

bool SecondEqual::operator()(const std::pair<int, int> &p) const
{
  return (target == p.second);
}
