#include "FirstEqual.hpp"

FirstEqual::FirstEqual(int target) : target(target) {}

FirstEqual::FirstEqual() {}

FirstEqual::FirstEqual(const FirstEqual &src) : target(src.target) {}

FirstEqual &FirstEqual::operator=(const FirstEqual &rhs)
{
	if (this != &rhs)
	{
		this->target = rhs.target;
	}
	return (*this);
}

FirstEqual::~FirstEqual() {}

bool FirstEqual::operator()(const std::pair<int, int> &p) const
{
	return (this->target == p.first);
}
