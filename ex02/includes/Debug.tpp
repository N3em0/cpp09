#ifndef DEBUG_TPP
#define DEBUG_TPP

/* DEBUG */
#ifdef DEBUG_MODE

#include <iomanip>
#include <iostream>
#include <vector>
template <typename T>
static void printArr(T &big, T &small, T &rest)
{
	std::cout << "main value  : ";
	for (typename T::iterator it = big.begin(); it != big.end(); ++it)
		std::cout << "[" << std::right << std::setw(4) << it->first << "] ";
	std::cout << std::endl;
	std::cout << "main id     : ";
	for (typename T::iterator it = big.begin(); it != big.end(); ++it)
		std::cout << "[" << std::right << std::setw(4) << it->second << "] ";
	std::cout << std::endl;

	std::cout << "small value : ";
	for (typename T::iterator it = small.begin(); it != small.end(); ++it)
		std::cout << "(" << std::right << std::setw(4) << it->first << ") ";
	std::cout << std::endl;
	std::cout << "small id    : ";
	for (typename T::iterator it = small.begin(); it != small.end(); ++it)
		std::cout << "(" << std::right << std::setw(4) << it->second << ") ";
	std::cout << std::endl;

	if (!rest.empty())
	{
		std::cout << "rest value  : ";
		for (typename T::iterator it = rest.begin(); it != rest.end(); ++it)
			std::cout << "{" << std::right << std::setw(4) << it->first << "} ";
		std::cout << std::endl;
		std::cout << "rest id     : ";
		for (typename T::iterator it = rest.begin(); it != rest.end(); ++it)
			std::cout << "{" << std::right << std::setw(4) << it->second
					  << "} ";
		std::cout << std::endl;
	}
	std::cout << "------------" << std::endl;
}
template <typename T>
static void printArr(T &big, T &small)
{
	std::cout << "main value  : ";
	for (typename T::iterator it = big.begin(); it != big.end(); ++it)
		std::cout << "[" << std::right << std::setw(4) << it->first << "] ";
	std::cout << std::endl << "main id     : ";
	for (typename T::iterator it = big.begin(); it != big.end(); ++it)
		std::cout << "[" << std::right << std::setw(4) << it->second << "] ";
	std::cout << std::endl;

	std::cout << "small value : ";
	for (typename T::iterator it = small.begin(); it != small.end(); ++it)
		std::cout << "(" << std::right << std::setw(4) << it->first << ") ";
	std::cout << std::endl << "small id    : ";
	for (typename T::iterator it = small.begin(); it != small.end(); ++it)
		std::cout << "(" << std::right << std::setw(4) << it->second << ") ";
	std::cout << std::endl;
	std::cout << "------------" << std::endl;
}

static void printJacob(std::vector<int> &arr, std::string str)
{
	std::cout << str << "  : ";
	for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		std::cout << "|" << *it << "| ";
	}
	std::cout << std::endl;
}

#define D_ARR(big, small, rest) printArr(big, small, rest)
#define D_ARR2(big, small) printArr(big, small)
#define D_JACOB(arr, str) printJacob(arr, str)

#else

#define D_ARR(big, small, rest)
#define D_ARR2(big, small)
#define D_JACOB(arr, str)

#endif

#endif
/* DEBUG */
