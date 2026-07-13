#include "PmergeMe.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>
#include <utility> //std::pair, std::make_pair
#include <vector>

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
      throw std::exception();
    arr.push_back(std::make_pair(val, 0));
  }
  if (hasDuplicates(arr) == false)
    throw std::exception();
}

int main(int argc, char **argv)
{
  if (argc < 3)
    return (1);

  try
  {
    std::vector<std::pair<int, int> > arr;
    std::vector<std::pair<int, int> > sorted;
    std::vector<std::pair<int, int> > pend;
    std::vector<std::pair<int, int> > rest;
    arr.reserve(argc - 1);
    parseArgs(argc, argv, arr);
    PmergeMe<std::vector<std::pair<int, int> > > p(arr);
    p.downSort(p.arr_);
    for (std::vector<std::pair<int, int> >::iterator it = p.arr_.begin(); it != p.arr_.end(); ++it)
    {
      std::cout << "p.arr_ : " << it->first << std::endl;
    }
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    return (1);
  }
}
