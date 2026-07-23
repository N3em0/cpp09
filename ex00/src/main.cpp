#include "BitcoinExchange.hpp"
#include <bits/stdc++.h>

// static void print_map(BitcoinExchange be)
// {
//   for (std::map<std::string, float>::iterator it = be.csvData_.begin();
//        it != be.csvData_.end(); it++)
//   {
//     std::cout << "[" << it->first << "]" << std::endl;
//     std::cout << "[" << it->second << "]" << std::endl;
//   }
// }

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange be;

		be.processCsvData();
		be.processInData(argv[1]);
		return (0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
}
