#ifndef SECOND_EQUAL
#define SECOND_EQUAL

#include <utility>

class SecondEqual
{
public:
  SecondEqual();
  SecondEqual(int target);
  SecondEqual &operator=(const SecondEqual &rhs);
  SecondEqual(const SecondEqual &src);

  bool operator()(const std::pair<int, int> &p) const;

  ~SecondEqual();

  int target;

private:
};

#endif
