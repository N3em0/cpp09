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
  void doOperation(const char &c);
  void processRpn(std::string str);

  ~Rpn();

private:
  std::stack<int> values_;
};

#endif
