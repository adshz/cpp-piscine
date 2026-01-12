#include "RPN.hpp"
#include <sstream>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isDigit(char c) const {
	return c >= '0' && c <= '9';
}

bool RPN::performOperation(char op) {
	if (_stack.size() < 2)
		return false;

	int b = _stack.top();
	_stack.pop();
	int a = _stack.top();
	_stack.pop();

	int result;
	switch (op) {
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			if (b == 0)
				return false;
			result = a / b;
			break;
		default:
			return false;
	}

	_stack.push(result);
	return true;
}

bool RPN::evaluate(const std::string& expression, int& result) {
	while (!_stack.empty())
		_stack.pop();

	for (size_t i = 0; i < expression.length(); i++) {
		char c = expression[i];

		if (c == ' ')
			continue;

		if (isDigit(c)) {
			_stack.push(c - '0');
		} else if (isOperator(c)) {
			if (!performOperation(c))
				return false;
		} else {
			return false;
		}
	}

	if (_stack.size() != 1)
		return false;

	result = _stack.top();
	return true;
}
