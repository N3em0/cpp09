
#include "FirstSmaller.hpp"

FirstSmaller::FirstSmaller() {}

FirstSmaller::FirstSmaller(const FirstSmaller &) {}

FirstSmaller &FirstSmaller::operator=(const FirstSmaller &) { return (*this); }

FirstSmaller::~FirstSmaller() {}

bool FirstSmaller::operator()(const std::pair<int, int> &p, int value) const
{
	return (p.first < value);
}
