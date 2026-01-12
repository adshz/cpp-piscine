#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main(void)
{
	std::cout << "=== Subject test ===" << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test with 10000 numbers ===" << std::endl;
	{
		Span sp(10000);
		srand(time(NULL));

		for (int i = 0; i < 10000; i++)
			sp.addNumber(rand());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test adding range of iterators ===" << std::endl;
	{
		Span sp(10);
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);

		sp.addNumber(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test exceptions ===" << std::endl;
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);

		try
		{
			sp.addNumber(4);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	{
		Span sp(5);
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	{
		Span sp(5);
		sp.addNumber(42);
		try
		{
			sp.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test copy constructor ===" << std::endl;
	{
		Span sp1(5);
		sp1.addNumber(1);
		sp1.addNumber(5);
		sp1.addNumber(10);

		Span sp2(sp1);
		std::cout << "Original shortest: " << sp1.shortestSpan() << std::endl;
		std::cout << "Copy shortest: " << sp2.shortestSpan() << std::endl;
	}

	return 0;
}
