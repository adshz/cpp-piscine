#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

public:
	Span();
	Span(unsigned int n);
	Span(Span const &src);
	~Span();

	Span &operator=(Span const &rhs);

	void addNumber(int number);

	template <typename Iterator>
	void addNumber(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			addNumber(*begin);
			++begin;
		}
	}

	int shortestSpan() const;
	int longestSpan() const;

	class SpanFullException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif
