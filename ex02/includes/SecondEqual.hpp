#ifndef SECOND_EQUAL
#define SECOND_EQUAL

#include <utility>

struct SecondEqual
{
	SecondEqual();
	SecondEqual(int target);
	SecondEqual(const SecondEqual &src);
	SecondEqual &operator=(const SecondEqual &rhs);

	bool operator()(const std::pair<int, int> &p) const;

	~SecondEqual();

	int target;
};

#endif
