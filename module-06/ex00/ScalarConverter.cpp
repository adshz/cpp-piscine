#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& s) {
	return s.length() == 1 && !std::isdigit(s[0]);
}

static bool isInt(const std::string& s) {
	char* end;
	long val = std::strtol(s.c_str(), &end, 10);
	return *end == '\0' && end != s.c_str() &&
		   val >= std::numeric_limits<int>::min() &&
		   val <= std::numeric_limits<int>::max();
}

static bool isFloat(const std::string& s) {
	if (s == "-inff" || s == "+inff" || s == "nanf" || s == "inff")
		return true;
	if (s.empty() || s[s.length() - 1] != 'f')
		return false;
	char* end;
	std::strtof(s.c_str(), &end);
	return *end == 'f' && *(end + 1) == '\0';
}

static bool isDouble(const std::string& s) {
	if (s == "-inf" || s == "+inf" || s == "nan" || s == "inf")
		return true;
	if (s.find('.') == std::string::npos)
		return false;
	char* end;
	std::strtod(s.c_str(), &end);
	return *end == '\0' && end != s.c_str();
}

static void printFromDouble(double d) {
	// char
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

	// int
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) ||
		d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	// float
	std::cout << "float: " << std::fixed << std::setprecision(1)
			  << static_cast<float>(d) << "f" << std::endl;

	// double
	std::cout << "double: " << std::fixed << std::setprecision(1)
			  << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return;
	}

	if (isChar(literal)) {
		printFromDouble(static_cast<double>(literal[0]));
	}
	else if (isInt(literal)) {
		printFromDouble(static_cast<double>(std::strtol(literal.c_str(), NULL, 10)));
	}
	else if (isFloat(literal)) {
		printFromDouble(static_cast<double>(std::strtof(literal.c_str(), NULL)));
	}
	else if (isDouble(literal)) {
		printFromDouble(std::strtod(literal.c_str(), NULL));
	}
	else {
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	}
}
