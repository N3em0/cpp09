#include "PmergeMe.hpp"
#include <algorithm>
#include <bits/stdc++.h> //fixed(), setprecision()
#include <ctime>
#include <deque>
#include <exception>
#include <iomanip>
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
    clock_t start, end;
    start = clock();
    std::vector<std::pair<int, int> > arr;
    std::vector<std::pair<int, int> > sorted;
    std::vector<std::pair<int, int> > pend;
    std::vector<std::pair<int, int> > rest;
    arr.reserve(argc - 1);
    parseArgs(argc, argv, arr);
    PmergeMe<std::vector<std::pair<int, int> > > v(arr);
    v.downSort(v.arr_);
    for (std::vector<std::pair<int, int> >::iterator it = v.arr_.begin();
         it != v.arr_.end(); ++it)
    {
      std::cout << "v.arr_ : " << it->first << std::endl;
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << std::fixed << time_taken
              << std::setprecision(5);
    std::cout << " sec " << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    return (1);
  }
  try
  {
    clock_t start, end;
    start = clock();
    std::deque<std::pair<int, int> > arr;
    std::deque<std::pair<int, int> > sorted;
    std::deque<std::pair<int, int> > pend;
    std::deque<std::pair<int, int> > rest;
    parseArgs(argc, argv, arr);
    PmergeMe<std::deque<std::pair<int, int> > > d(arr);
    d.downSort(d.arr_);
    for (std::deque<std::pair<int, int> >::iterator it = d.arr_.begin();
         it != d.arr_.end(); ++it)
    {
      std::cout << "d.arr_ : " << it->first << std::endl;
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << std::fixed << time_taken
              << std::setprecision(5);
    std::cout << " sec " << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    return (1);
  }
}
