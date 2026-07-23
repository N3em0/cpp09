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
	const long &getResult();
	void doOperation(const char &c);
	void processRpn(std::string str);

	class badCharException : public std::exception
	{
	  public:
		badCharException();
		virtual const char *what() const throw()
		{
			return ("Error: Wrong char input");
		}
	};

	class tooManyOp : public std::exception
	{
	  public:
		tooManyOp();
		virtual const char *what() const throw()
		{
			return ("Error: Too many operators\nValid operator count = "
					"digitCount - 1");
		}
	};

	class tooManyDigits : public std::exception
	{
	  public:
		tooManyDigits();
		virtual const char *what() const throw()
		{
			return ("Error: Too many digits\nValid digits count = "
					"operatorCount + 1");
		}
	};

	~Rpn();

  private:
	long result_;
	std::stack<int> values_;
};

#endif
