#include "BitcoinExchange.hpp"
#include <cctype>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() : csvData_() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
	: csvData_(src.csvData_)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->csvData_ = rhs.csvData_;
	}
	return (*this);
}

const std::map<std::string, float> &BitcoinExchange::getCsvData()
{
	return (this->csvData_);
}

void BitcoinExchange::processCsvData()
{
	std::ifstream inFile("data.csv");
	std::string str;
	if (!inFile.is_open())
	{
		throw std::invalid_argument("Wrong file");
		return;
	}
	std::getline(inFile, str);
	while (std::getline(inFile, str))
	{
		this->csvData_[str.substr(0, str.find(','))] =
			std::atof((str.substr(str.find(',') + 1)).c_str());
	}
}

#include <iostream>

static bool parseDate(std::string date)
{
	int year;
	int month;
	int day;
	char trait1;
	char trait2;
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::stringstream ss(date);

	if (!(ss >> year >> trait1 >> month >> trait2 >> day) || !ss.eof())
		return false;

	std::tm tBtc;
	std::memset(&tBtc, 0, sizeof(std::tm));
	time_t btcCreation;

	tBtc.tm_year = 2009 - 1900;
	tBtc.tm_mon = 1 - 1;
	tBtc.tm_mday = 2;
	btcCreation = std::mktime(&tBtc);

	std::tm tDate;
	std::memset(&tDate, 0, sizeof(std::tm));
	time_t result;

	tDate.tm_year = year - 1900;
	tDate.tm_mon = month - 1;
	tDate.tm_mday = day;
	result = std::mktime(&tDate);
	if (result == -1)
		return false;
	if ((year - 1900) != tDate.tm_year || (month - 1) != tDate.tm_mon ||
		day != tDate.tm_mday)
		return false;
	if (result < btcCreation)
		return (false);
	return (true);
}

static bool parseValue(std::string valueStr)
{
	if (valueStr.size() <= 1)
		return (false);
	if (!std::isdigit(valueStr[1]) && valueStr[1] != '-')
		return (false);
	if (valueStr.find_first_of("0123456789") == std::string::npos)
		return (false);
	std::stringstream ss(valueStr);
	float fvalueStr;

	ss >> fvalueStr;
	if (ss.eof())
		return (true);
	return (false);
}

void BitcoinExchange::processInData(char *file)
{
	std::ifstream inFile(file);
	std::string str;
	if (!inFile.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}
	std::getline(inFile, str);
	if (std::strcmp(str.c_str(), "date | value") != 0)
		throw BitcoinExchange::badInputHeader();
	while (std::getline(inFile, str))
	{
		std::string date = str.substr(0, str.find('|') - 1);
		std::string valueStr = str.substr(str.find('|') + 1);
		if (!parseDate(date))
		{
			std::cout << "Error: bad input => [" << date << "]" << std::endl;
			continue;
		}
		if (!parseValue(valueStr))
		{
			std::cout << "Error: bad input => [" << valueStr << "]"
					  << std::endl;
			continue;
		}
		float value = std::atof(valueStr.c_str());

		if (value < 0)
		{
			std::cout << "Error: not a positive number" << std::endl;
			continue;
		}

		else if (value > 1000)
		{
			std::cout << "Error: too large number" << std::endl;
			continue;
		}

		else
		{
			std::map<std::string, float>::iterator it;
			it = this->csvData_.find(date);
			if (it == this->csvData_.end())
			{
				it = this->csvData_.lower_bound(date);
				it--;
			}
			float result = value * it->second;
			std::cout << date << " => " << value << " = " << result
					  << std::endl;
		}
	}
}

BitcoinExchange::badInputHeader::badInputHeader() {}

BitcoinExchange::~BitcoinExchange() {}
