#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	bool loadDatabase(const std::string& filename);
	void processInputFile(const std::string& filename);

private:
	std::map<std::string, double> _database;

	bool isValidDate(const std::string& date) const;
	bool isValidValue(const std::string& value, double& result) const;
	double getExchangeRate(const std::string& date) const;
	std::string trim(const std::string& str) const;
};

#endif
