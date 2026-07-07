#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class Rpn
{
public:
  Rpn();
  Rpn(const Rpn &src);
  Rpn &operator=(const Rpn &rhs);

  const std::stack<int> &getValues();
  long doOperation(const char &c);
  void processRpn(std::string str);
  long result;

  ~Rpn();

private:
  std::stack<int> values_;
};

#endif
