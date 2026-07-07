#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    return (1);
  }
  try
  {
    Rpn a;

    a.processRpn(argv[1]);
    std::cout << a.getResult() << std::endl;
    return (0);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    return (1);
  }
}
