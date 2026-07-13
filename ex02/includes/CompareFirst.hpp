#ifndef COMPARE_FIRST
#define COMPARE_FIRST

#include <utility>

class CompareFirst
{
public:
  CompareFirst();
  CompareFirst(int target);
  CompareFirst &operator=(const CompareFirst &rhs);
  CompareFirst(const CompareFirst &src);

  bool operator()(const std::pair<int, int> &p) const;

  ~CompareFirst();

  int target;

private:
};

#endif
