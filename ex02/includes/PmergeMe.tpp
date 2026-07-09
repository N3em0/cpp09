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

/* FAIRE L AJOUT DE L ID DANS LA PAIR */
template <typename T>
void PmergeMe<T>::sortPairs(T &unsorted, T &sorted, T &pend, T &rest)
{
  for (unsigned long i = 0; i < unsorted.size(); i++)
  {
    std::set<std::pair<int, int> > s;
    if ((i + 1) < unsorted.size())
    {
      s.insert(unsorted[i]);
      s.insert(unsorted[i + 1]);
      sorted.push_back(*(s.rbegin()));
      pend.push_back(*(s.begin()));
      s.clear();
      i++;
    }
    else
      rest.push_back(unsorted[i]);
  }
}

template <typename T>
void PmergeMe<T>::downSort(T arr)
{
  T sorted;
  T pend;
  while (arr.size() > 2)
  {
  }
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

#endif
