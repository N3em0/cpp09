#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "Debug.tpp"
#include "FirstEqual.hpp"
#include "FirstSmaller.hpp"
#include "PmergeMe.hpp"
#include "SecondEqual.hpp"
#include <algorithm>

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
			if (unsorted[i].first >= unsorted[i + 1].first)
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
	D_ARR2(big, small);
	big.insert(big.begin(), small[0]);
	D_ARR2(big, small);
	for (std::vector<int>::const_iterator it = jIndex.begin();
		 it != jIndex.end(); it++)
	{
		typename T::iterator fit;
		SecondEqual matchingId(small[(*it) - 1].second);
		typename T::iterator idIt;
		idIt = std::find_if(big.begin(), big.end(), matchingId);
		if (idIt != big.end())
			fit = std::lower_bound(big.begin(), idIt, small[(*it) - 1].first,
								   FirstSmaller());
		else
			fit = std::lower_bound(big.begin(), big.end(),
								   small[(*it) - 1].first, FirstSmaller());
		big.insert(fit, small[(*it) - 1]);
		D_ARR2(big, small);
	}
}

template <typename T>
void PmergeMe<T>::computeJacobSuit(T &small, std::vector<int> &jSuit)
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
	std::vector<int> jIndex;

	small = matchBigSmall(big, small);
	D_ARR(big, small, rest);
	if (!rest.empty())
	{
		small.push_back(rest[0]);
		rest.clear();
	}
	computeJacobSuit(small, jSuit);
	computeJacobIndex(jIndex, jSuit);
	D_JACOB(jSuit, "jSuit");
	D_JACOB(jIndex, "jIndex");
	binarySearch(big, small, jIndex);
}

// #include <iostream>

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
		D_ARR(big, small, rest);
		downSort(big);
		matchBigId(big, save);
		D_ARR(big, small, rest);
		upSort(big, small, rest);
		D_ARR(big, small, rest);
		arr = big;
	}
	// std::cout << std::endl << "============" << std::endl;
	return;
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

template <typename T>
PmergeMe<T>::alreadySorted::alreadySorted()
{
}

template <typename T>
PmergeMe<T>::badInputException::badInputException()
{
}

#endif
