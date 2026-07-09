#ifndef PMERGEME_HPP
#define PMERGEME_HPP

template <typename T> class PmergeMe
{
public:
  PmergeMe();
  PmergeMe(T arr);
  PmergeMe(const PmergeMe<T> &src);
  PmergeMe &operator=(const PmergeMe<T> &rhs);
  ~PmergeMe();

  T arr_;

private:
};

#include "PmergeMe.tpp"

#endif
