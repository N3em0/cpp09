#ifndef FIRST_SMALLER
#define FIRST_SMALLER

#include <utility>

struct FirstSmaller
{
  FirstSmaller();
  FirstSmaller(int target);
  FirstSmaller &operator=(const FirstSmaller &rhs);
  FirstSmaller(const FirstSmaller &src);

  bool operator()(const std::pair<int, int> &p, int value) const;

  ~FirstSmaller();
};

#endif
