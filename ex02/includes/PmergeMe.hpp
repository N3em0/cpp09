#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
	void computeJacobSuit(T &small, std::vector<int> &jSuit);
	void computeJacobIndex(std::vector<int> &jIndex, const std::vector<int> &jSuit);
	void binarySearch(T &big, T &small, const std::vector<int> &jIndex);

	class alreadySorted : public std::exception
	{
	  public:
		alreadySorted();
		virtual const char *what() const throw()
		{
			return ("Array is already sorted");
		}
	};

	class badInputException : public std::exception
	{
	  public:
		badInputException();
		virtual const char *what() const throw()
		{
			return ("Error: Wrong input. Positive integers only");
		}
	};
	~PmergeMe();

	T arr_;
	T sorted_;
	int id_;

  private:
};

#include "PmergeMe.tpp"

#endif
