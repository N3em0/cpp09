#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"
#include <set>

template <typename T>
PmergeMe<T>::PmergeMe() : arr_(), id_(1)
{
}

template <typename T>
PmergeMe<T>::PmergeMe(T arr) : arr_(arr), id_(1)
{
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
void PmergeMe<T>::sortPairs(T &unsorted, T &sorted, T &pend, T &rest)
{
  for (unsigned long i = 0; i < unsorted.size(); i++)
  {
    std::set<std::pair<int, int> > s;
    if ((i + 1) < unsorted.size())
    {
      unsorted[i].second = this->id_;
      unsorted[i + 1].second = this->id_;
      s.insert(unsorted[i]);
      s.insert(unsorted[i + 1]);
      sorted.push_back(*(s.rbegin()));
      pend.push_back(*(s.begin()));
      s.clear();
      i++;
      this->id_++;
    }
    else
      rest.push_back(unsorted[i]);
  }
}

#include <iostream>

template <typename T>
void PmergeMe<T>::downSort(T arr)
{
  T sorted;
  T pend;
  T rest;
  while (arr.size() > 1)
  {
    sortPairs(arr, sorted, pend, rest);
    // downSort(sorted);
    std::cout << "size : " << arr.size() << std::endl;
    for (typename T::iterator it = arr.begin(); it != arr.end(); ++it)
    {
      std::cout << "sorted->first  : " << it->first << std::endl;
      std::cout << "sorted->second : " << it->second << std::endl;
    }
    /* DEBUG */
  }
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

#endif
