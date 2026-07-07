#include "RPN.hpp"
#include <cstdlib>
#include <exception>

Rpn::Rpn() : result(0), values_() {}

Rpn::Rpn(const Rpn &src) : result(src.result), values_(src.values_) {}

Rpn &Rpn::operator=(const Rpn &rhs)
{
  if (this != &rhs)
  {
    result = rhs.result;
    this->values_ = rhs.values_;
  }
  return (*this);
}

const std::stack<int> &Rpn::getValues() { return (this->values_); }

long Rpn::doOperation(const char &c)
{
  int a = this->values_.top();
  this->values_.pop();
  int b = this->values_.top();
  this->values_.pop();
  long result = 0;

  switch (c)
  {
  case ('+'):
    result = b + a;
    break;
  case ('-'):
    result = b - a;
    break;
  case ('*'):
    result = b * a;
    break;
  case ('/'):
    result = b / a;
    break;
  default:
    break;
  }
  this->values_.push(static_cast<int>(result));
  return (result);
}

static bool isOperator(const char &c)
{
  return ((
      c == '+'
          ? true
          : (c == '-' ? true : (c == '/' ? true : (c == '*' ? true : false)))));
}

void Rpn::processRpn(std::string str)
{

  for (size_t i = 0; i < str.size(); ++i)
  {
    if (std::isdigit(str[i]))
    {
      this->values_.push(str[i] - 48);
      if (str[i + 1] && str[i + 1] != ' ')
        return;
    }
    else if (isOperator(str[i]))
    {
      if (this->values_.size() <= 1)
        throw std::exception();
      this->result = doOperation(str[i]);
    }
    else if (str[i] != ' ')
      throw std::exception();
  }
  if (this->values_.size() != 1)
    throw std::exception();
}

Rpn::~Rpn() {}
