#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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
  ~BitcoinExchange();
  std::map<std::string, float> csvData_;

private:
};

#endif
