#ifndef PMERGEME_HPP
#define PMERGEME_HPP

template <typename T>
class PmergeMe
{
public:
  PmergeMe();
  PmergeMe(T arr);
  PmergeMe(const PmergeMe<T> &src);
  PmergeMe &operator=(const PmergeMe<T> &rhs);

  void downSort(T arr);
  void sortPairs(T &unsorted, T &sorted, T &pend, T &rest);

  ~PmergeMe();

  T arr_;
  int id_;

private:
};

#include "PmergeMe.tpp"

#endif
