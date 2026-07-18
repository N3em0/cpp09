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

#include "FirstEqual.hpp"
#include "FirstSmaller.hpp"
#include "PmergeMe.hpp"
#include "SecondEqual.hpp"
#include <algorithm>
#include <set>

template <typename T>
PmergeMe<T>::PmergeMe() : arr_(), sorted_(), id_(1)
{
}

template <typename T>
PmergeMe<T>::PmergeMe(T arr) : arr_(arr), sorted_(), id_(1)
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
void PmergeMe<T>::sortPairs(T &unsorted, T &big, T &small, T &rest)
{
  int id = 1;
  for (size_t i = 0; i < unsorted.size(); i++)
  {
    if ((i + 1) < unsorted.size())
    {
      unsorted[i].second = id;
      unsorted[i + 1].second = id;
      if (unsorted[i].first > unsorted[i + 1].first)
      {
        big.push_back(unsorted[i]);
        small.push_back(unsorted[i + 1]);
      }
      else
      {
        small.push_back(unsorted[i]);
        big.push_back(unsorted[i + 1]);
      }
      i++;
      id++;
    }
    else
      rest.push_back(unsorted[i]);
  }
}

template <typename T>
void PmergeMe<T>::binarySearch(T &big, T &small, const std::vector<int> &jIndex)
{
  big.insert(big.begin(), small[0]);
  for (std::vector<int>::const_iterator it = jIndex.begin(); it != jIndex.end();
       it++)
  {
    typename T::iterator fit;
    FirstEqual index(small[(*it) - 1].first);
    typename T::iterator idIt;
    idIt = std::find_if(big.begin(), big.end(), index);
    if (idIt != big.end())
      fit = std::lower_bound(big.begin(), idIt, small[(*it) - 1].first,
                             FirstSmaller());
    else
      fit = std::lower_bound(big.begin(), big.end(), small[(*it) - 1].first,
                             FirstSmaller());
    big.insert(fit, small[(*it) - 1]);
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
    if (val < small.size())
      jSuit.push_back(val);
    else
    {
      jSuit.push_back(small.size());
      break;
    }
  }
}

template <typename T>
void PmergeMe<T>::computeJacobIndex(std::vector<int> &jIndex,
                                    const std::vector<int> &jSuit)
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
}

template <typename T>
void PmergeMe<T>::matchBigId(T &big, T &save)
{
  for (typename T::iterator it = big.begin(); it != big.end(); ++it)
  {
    FirstEqual index(it->first);
    typename T::iterator fit;
    fit = std::find_if(save.begin(), save.end(), index);
    // std::cout << "ID it->first : " << it->first << std::endl;
    // std::cout << "ID it->second : " << it->second << std::endl;
    // std::cout << "ID fit->first : " << fit->first << std::endl;
    // std::cout << "ID fit->second : " << fit->second << std::endl;
    it->second = fit->second;
  }
  return;
}

template <typename T>
T PmergeMe<T>::matchBigSmall(T &big, T &small)
{
  T smallS;
  for (typename T::iterator it = big.begin(); it != big.end(); ++it)
  {
    SecondEqual index(it->second);
    typename T::iterator fit;
    fit = std::find_if(small.begin(), small.end(), index);
    smallS.push_back(*(fit));
  }
  return (smallS);
}

template <typename T>
void PmergeMe<T>::upSort(T &big, T &small, T &rest)
{
  std::vector<int> jSuit;
  // std::cout << "PrintArr upSort start" << std::endl;
  // printArr(big, small, rest);
  small = matchBigSmall(big, small);
  // std::cout << "PrintArr matchBigSmall after" << std::endl;
  if (!rest.empty())
    small.push_back(rest[0]);
  // printArr(big, small, rest);
  computeJacobSuits(small, jSuit);
  // for (std::vector<int>::iterator it = jSuit.begin(); it != jSuit.end();
  // ++it)
  // {
  //   std::cout << "val  jSuit : " << *it << std::endl;
  // }
  std::vector<int> jIndex;
  computeJacobIndex(jIndex, jSuit);
  binarySearch(big, small, jIndex);
  // for (std::vector<int>::iterator it = jIndex.begin(); it != jIndex.end();
  // ++it)
  // {
  //   std::cout << "val jIndex : " << *it << std::endl;
  // }
}

template <typename T>
void PmergeMe<T>::downSort(T &arr)
{
  T big;
  T save;
  T small;
  T rest;
  if (arr.size() > 1)
  {
    sortPairs(arr, big, small, rest);
    save = big;
    // printArr(big, small, rest);
    downSort(big);
    // std::cout << "-----------------" << std::endl;
    matchBigId(big, save);
    // std::cout << "=====================" << std::endl;
    upSort(big, small, rest);
    // std::cout << "=====================" << std::endl;
    arr = big;
  }
  return;
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

#endif
