#ifndef FIRST_EQUAL
#define FIRST_EQUAL

#include <utility>

struct FirstEqual
{
  FirstEqual();
  FirstEqual(int target);
  FirstEqual &operator=(const FirstEqual &rhs);
  FirstEqual(const FirstEqual &src);

  bool operator()(const std::pair<int, int> &p) const;

  ~FirstEqual();

  int target;
};

#endif
