#include "Rpn.hpp"

Rpn::Rpn() : values_() {}

Rpn::Rpn(const Rpn &src) : values_(src.values_) {}

Rpn &Rpn::operator=(const Rpn &rhs)
{
  if (this != &rhs)
  {
    this->values_ = rhs.values_;
  }
  return (*this);
}

const std::stack<int> &Rpn::getValues() { return (this->values_); }

void Rpn::doOperation(const char &c)
{
  int a = this->values_.pop();
  int b = this->values_.pop();
  long result = 0;

  switch (c)
  {
    case ('+') : result = a + b; break;
    case ('-') : result = a - b; break;
    case ('*') : result = a * b; break;
    case ('/') : result = a / b; break;
    default:
      break;
  }
  this->values_.push(static_cast<int>(result));
  return ;
}

static bool isOperator(const char &c)
{
  return ((c == '+' ? true :
          (c == '-' ? true :
          (c == '/' ? true :
          (c == '*' ? true : false)))));
}

void Rpn::processRpn(std::string str)
{
  long result;
  for (size_t i = 0; i < str.size(); ++i)
  {
    if (std::isdigit(str[i]))
    {
      this->values_.push(std::atoi(str[i]));
      if (str[i + 1] && str[i + 1] != ' ')
        return;
    }
    else if (isOperator(str[i]) && this->values_.size() > 1)
    {

    }
  }
}

Rpn::~Rpn() {}
