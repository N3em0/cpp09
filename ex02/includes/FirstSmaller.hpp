#ifndef FIRST_SMALLER
#define FIRST_SMALLER

#include <utility>

struct FirstSmaller
{
	FirstSmaller();
	FirstSmaller(const FirstSmaller &src);
	FirstSmaller &operator=(const FirstSmaller &rhs);

	bool operator()(const std::pair<int, int> &p, int value) const;

	~FirstSmaller();
};

#endif
