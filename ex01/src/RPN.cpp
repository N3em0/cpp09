#include "RPN.hpp"
#include <cstdlib>
#include <exception>

Rpn::Rpn() : result_(0), values_() {}

Rpn::Rpn(const Rpn &src) : result_(src.result_), values_(src.values_) {}

Rpn &Rpn::operator=(const Rpn &rhs)
{
  if (this != &rhs)
  {
    result_ = rhs.result_;
    this->values_ = rhs.values_;
  }
  return (*this);
}

const std::stack<int> &Rpn::getValues() { return (this->values_); }

const long &Rpn::getResult() { return (this->result_); }

#include <iostream>

void Rpn::doOperation(const char &c)
{
  if (this->values_.size() < 2)
    throw Rpn::tooManyOp();
  int a = this->values_.top();
  this->values_.pop();
  int b = this->values_.top();
  this->values_.pop();

  switch (c)
  {
  case ('+'):
    this->result_ = b + a;
    break;
  case ('-'):
    this->result_= b - a;
    break;
  case ('*'):
    this->result_ = b * a;
    break;
  case ('/'):
    this->result_ = b / a;
    break;
  }
  this->values_.push(static_cast<int>(this->result_));
  return ;
}

static bool isOperator(const char &c)
{
  switch(c)
  {
  case ('+'):
    return (true);
  case ('-'):
    return (true);
  case ('*'):
    return (true);
  case ('/'):
    return (true);
  case (' '):
    return (false);
  default:
      throw Rpn::badCharException();
  }
}

void Rpn::processRpn(std::string str)
{

  for (size_t i = 0; i < str.size(); ++i)
  {
    if (std::isdigit(str[i]))
      this->values_.push(str[i] - 48);
    else if (isOperator(str[i]))
      doOperation(str[i]);
  }
  if (this->values_.size() != 1)
    throw Rpn::tooManyDigits();
}

Rpn::badCharException::badCharException() {}
Rpn::tooManyOp::tooManyOp() {}
Rpn::tooManyDigits::tooManyDigits() {}

Rpn::~Rpn() {}
