/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:37:10 by szhong            #+#    #+#             */
/*   Updated: 2026/02/07 13:37:11 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

	// Cleaner version helpers
	bool printError(const std::string& msg) const;
	bool processLine(const std::string& line);
};

#endif
