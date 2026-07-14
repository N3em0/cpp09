#ifndef FIRST_SMALLER
#define FIRST_SMALLER

#include <utility>

struct FirstSmaller
{
public:
  FirstSmaller();
  FirstSmaller(int target);
  FirstSmaller &operator=(const FirstSmaller &rhs);
  FirstSmaller(const FirstSmaller &src);

  bool operator()(const std::pair<int, int> &p, int value) const;

  ~FirstSmaller();

private:
};

#endif
