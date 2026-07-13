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

  void downSort(T &arr);
  void upSort(T &big, T &small, T &rest);
  void sortPairs(T &unsorted, T &big, T &small, T &rest);
  T matchBigSmall(T &big, T &small);
  void matchBigId(T &big, T &small);
  void computeJacobSuits(T &small, std::vector<int> &jSuit);
  void computeJacobIndex(std::vector<int> &jIndex,
                         const std::vector<int> &jSuit);
  void binarySearch(T &big, T &small, const std::vector<int> &jIndex);

  ~PmergeMe();

  T arr_;
  T sorted_;
  int id_;

private:
};

#include "PmergeMe.tpp"

#endif
