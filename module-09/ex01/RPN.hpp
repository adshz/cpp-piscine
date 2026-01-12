#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	bool evaluate(const std::string& expression, int& result);

private:
	std::stack<int> _stack;

	bool isOperator(char c) const;
	bool isDigit(char c) const;
	bool performOperation(char op);
};

#endif
