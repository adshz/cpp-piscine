#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_database = other._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) const {
	size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeapYear)
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(const std::string& value, double& result) const {
	if (value.empty())
		return false;

	char* endptr;
	result = std::strtod(value.c_str(), &endptr);

	if (*endptr != '\0')
		return false;

	return true;
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}

	std::string line;
	bool isFirstLine = true;

	while (std::getline(file, line)) {
		if (isFirstLine) {
			isFirstLine = false;
			continue;
		}

		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		std::string date = trim(line.substr(0, commaPos));
		std::string rateStr = trim(line.substr(commaPos + 1));

		double rate;
		if (isValidDate(date) && isValidValue(rateStr, rate)) {
			_database[date] = rate;
		}
	}

	file.close();
	return !_database.empty();
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = _database.find(date);
	if (it != _database.end())
		return it->second;

	it = _database.upper_bound(date);
	if (it == _database.begin())
		return -1;

	--it;
	return it->second;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool isFirstLine = true;

	while (std::getline(file, line)) {
		if (isFirstLine) {
			isFirstLine = false;
			if (line.find("date") != std::string::npos && line.find("value") != std::string::npos)
				continue;
		}

		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		double value;
		if (!isValidValue(valueStr, value)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		double rate = getExchangeRate(date);
		if (rate < 0) {
			std::cerr << "Error: date is before database start." << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}

	file.close();
}
