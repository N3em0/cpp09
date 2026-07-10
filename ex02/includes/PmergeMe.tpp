#ifndef PMERGEME_TPP
#define PMERGEME_TPP

/* DEBUG */
#include <iostream>
template <typename T>
static void printArr(T &big, T &small, T &rest)
{
  std::cout << "big size : " << big.size() << std::endl;
  for (typename T::iterator it = big.begin(); it != big.end(); ++it)
  {
    std::cout << "big->first  : " << it->first << std::endl;
    std::cout << "big->second : " << it->second << std::endl;
  }
  std::cout << "small size : " << small.size() << std::endl;
  for (typename T::iterator it = small.begin(); it != small.end(); ++it)
  {
    std::cout << "small->first  : " << it->first << std::endl;
    std::cout << "small->second : " << it->second << std::endl;
  }
  std::cout << "rest size : " << rest.size() << std::endl;
  for (typename T::iterator it = rest.begin(); it != rest.end(); ++it)
  {
    std::cout << "rest->first  : " << it->first << std::endl;
    std::cout << "rest->second : " << it->second << std::endl;
  }
}
/* DEBUG */

#include "CompareSecond.hpp"
#include "PmergeMe.hpp"
#include <algorithm>
#include <set>

template <typename T>
PmergeMe<T>::PmergeMe() : arr_(), sorted_(), id_(1)
{
}

template <typename T>
PmergeMe<T>::PmergeMe(T arr) : arr_(arr), sorted_(), id_(1)
{
  sorted_.reserve(this->arr_.size());
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T> &)
{
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe<T> &)
{
  return (*this);
}

template <typename T>
void PmergeMe<T>::sortPairs(T &unsorted, T &big, T &small, T &rest)
{
  for (size_t i = 0; i < unsorted.size(); i++)
  {
    std::set<std::pair<int, int> > s;
    if ((i + 1) < unsorted.size())
    {
      unsorted[i].second = this->id_;
      unsorted[i + 1].second = this->id_;
      s.insert(unsorted[i]);
      s.insert(unsorted[i + 1]);
      big.push_back(*(s.rbegin()));
      small.push_back(*(s.begin()));
      s.clear();
      i++;
      this->id_++;
    }
    else
      rest.push_back(unsorted[i]);
  }
}

template <typename T>
void PmergeMe<T>::computeJacobSuits(T &small, std::vector<int> &jSuit)
{
  int nMinus1 = 1;
  int nMinus2 = 1;
  size_t val = 1;
  while (val < small.size())
  {
    val = nMinus1 + (2 * nMinus2);
    nMinus2 = nMinus1;
    nMinus1 = val;
    jSuit.push_back(val);
  }
}

template <typename T>
void PmergeMe<T>::computeJacobIndex(std::vector<int> &jIndex,
                                    const std::vector<int> &jSuit, size_t size,
                                    bool empty)
{
  typedef std::vector<int>::const_iterator cit;
  int previous = 1;
  for (cit it = jSuit.begin(); it != jSuit.end(); it++)
  {
    int val = *it;
    while (val > previous)
    {
      jIndex.push_back(val);
      val--;
    }
    previous = *it;
  }
  (void)size;
  (void)empty;
  // if (!empty)
  // {
  //   jIndex.push_back(size + 2);
  // }
}

template <typename T>
T PmergeMe<T>::matchBigSmall(T &big, T &small)
{
  T smallS;
  smallS.reserve(small.size());
  for (typename T::iterator it = big.begin(); it != big.end(); ++it)
  {
    CompareSecond index(it->second);
    typename T::iterator fit;
    fit = std::find_if(small.begin(), small.end(), index);
    smallS.push_back(*(fit));
  }
  return (smallS);
}

template <typename T>
T &PmergeMe<T>::upSort(T &big, T &small, T &rest)
{
  std::vector<int> jSuit;
  small = matchBigSmall(big, small);
  computeJacobSuits(small, jSuit);
  for (std::vector<int>::iterator it = jSuit.begin(); it != jSuit.end(); ++it)
  {
    std::cout << "val  jSuit : " << *it << std::endl;
  }
  std::vector<int> jIndex;
  computeJacobIndex(jIndex, jSuit, small.size(), rest.empty());
  for (std::vector<int>::iterator it = jIndex.begin(); it != jIndex.end(); ++it)
  {
    std::cout << "val jIndex : " << *it << std::endl;
  }
  return (big);
}

template <typename T>
T &PmergeMe<T>::downSort(T &arr)
{
  T big;
  T small;
  T rest;
  if (arr.size() > 1)
  {
    sortPairs(arr, big, small, rest);
    printArr(big, small, rest);
    big = downSort(big);
  }
  printArr(big, small, rest);
  return (upSort(big, small, rest));
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

#endif
