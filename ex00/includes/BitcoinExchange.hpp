#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <string>

class BitcoinExchange
{
  public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void processCsvData();
	void processInData(char *file);
	const std::map<std::string, float> &getCsvData();

	~BitcoinExchange();

	class badInputHeader : public std::exception
	{
	  public:
		badInputHeader();
		virtual const char *what() const throw()
		{
			return ("Error: bad input.txt header");
		}
	};

  private:
	std::map<std::string, float> csvData_;
};

#endif
