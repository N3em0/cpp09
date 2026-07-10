#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <vector>

template <typename T>
class PmergeMe
{
public:
  PmergeMe();
  PmergeMe(T arr);
  PmergeMe(const PmergeMe<T> &src);
  PmergeMe &operator=(const PmergeMe<T> &rhs);

  T &downSort(T &arr);
  T &upSort(T &big, T &small, T &rest);
  void sortPairs(T &unsorted, T &big, T &small, T &rest);
  T matchBigSmall(T &big, T &small);
  void computeJacobSuits(T &small, std::vector<int> &jacobSuit);
  void computeJacobIndex(std::vector<int> &jacobIndex,
                         const std::vector<int> &jacobSuit, size_t size,
                         bool empty);

  ~PmergeMe();

  T arr_;
  T sorted_;
  int id_;

private:
};

#include "PmergeMe.tpp"

#endif
