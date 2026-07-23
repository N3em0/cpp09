#include "PmergeMe.hpp"
#include <algorithm>
#include <bits/stdc++.h> //fixed(), setprecision()
#include <ctime>		 //clock();
#include <deque>
#include <exception>
#include <iostream>
#include <sstream> //std::stringstream
#include <utility> //std::pair, std::make_pair
#include <vector>

template <typename T>
static bool isSorted(T arr)
{
	for (typename T::iterator it = arr.begin() + 1; it != arr.end(); ++it)
	{
		if (it->first < (it - 1)->first)
			return (false);
	}
	return (true);
}

template <typename T>
static bool hasDuplicates(T arr)
{
	std::sort(arr.begin(), arr.end());
	if (std::adjacent_find(arr.begin(), arr.end()) != arr.end())
		return (false);
	return (true);
}

template <typename T>
static void parseArgs(int argc, char **argv, T &arr)
{
	int val;
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		ss >> val;
		if (ss.fail() || val < 0)
			throw typename PmergeMe<T>::badInputException();
		arr.push_back(std::make_pair(val, 0));
	}
	if (hasDuplicates(arr) == false)
		throw typename PmergeMe<T>::badInputException();
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return (1);

	/* std::vector */
	std::cout << "\n++++++++++ STD::VECTOR ++++++++++\n"
			  << std::endl;
	try
	{
		clock_t start, end;
		start = clock();
		std::vector<std::pair<int, int> > arr;
		arr.reserve(argc - 1);

		parseArgs(argc, argv, arr);
		if (isSorted(arr))
			throw PmergeMe<std::vector<std::pair<int, int> > >::alreadySorted();

		PmergeMe<std::vector<std::pair<int, int> > > v(arr);

		std::cout << "Before : ";
		for (std::vector<std::pair<int, int> >::iterator it = v.arr_.begin(); it != v.arr_.end(); ++it)
			std::cout << it->first << " ";
		std::cout << std::endl
				  << std::endl;

		v.downSort(v.arr_);
		std::cout << "After : ";
		for (std::vector<std::pair<int, int> >::iterator it = v.arr_.begin(); it != v.arr_.end(); ++it)
			std::cout << it->first << " ";
		std::cout << std::endl
				  << std::endl;
		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
		std::cout << "Time taken for a vector of size " << v.arr_.size() << " is : " << std::fixed << time_taken << std::setprecision(5);
		std::cout << " sec " << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	/* std::deque */
	std::cout << "\n++++++++++ STD::DEQUE ++++++++++\n"
			  << std::endl;
	try
	{
		clock_t start, end;
		start = clock();
		std::deque<std::pair<int, int> > arr;

		parseArgs(argc, argv, arr);
		if (isSorted(arr))
			throw PmergeMe<std::deque<std::pair<int, int> > >::alreadySorted();

		PmergeMe<std::deque<std::pair<int, int> > > d(arr);

		std::cout << "Before : ";
		for (std::deque<std::pair<int, int> >::iterator it = d.arr_.begin(); it != d.arr_.end(); ++it)
			std::cout << it->first << " ";
		std::cout << std::endl
				  << std::endl;
		d.downSort(d.arr_);
		std::cout << "After : ";
		for (std::deque<std::pair<int, int> >::iterator it = d.arr_.begin(); it != d.arr_.end(); ++it)
			std::cout << it->first << " ";
		std::cout << std::endl
				  << std::endl;
		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
		std::cout << "Time taken for a deque of size " << d.arr_.size() << " is : " << std::fixed << time_taken << std::setprecision(5);
		std::cout << " sec " << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
