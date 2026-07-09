#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() : arr_() {}

template <typename T>
PmergeMe<T>::PmergeMe(T arr) : arr_(arr) {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T> &) {}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe<T> &)
{
  return (*this);
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

#endif
