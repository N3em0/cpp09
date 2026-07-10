#ifndef COMPARE_SECOND
#define COMPARE_SECOND

#include <utility>

class CompareSecond
{
public:
  CompareSecond();
  CompareSecond(int target);
  CompareSecond &operator=(const CompareSecond &rhs);
  CompareSecond(const CompareSecond &src);

  bool operator()(const std::pair<int, int> &p) const;

  ~CompareSecond();

  int target;

private:
};

#endif
