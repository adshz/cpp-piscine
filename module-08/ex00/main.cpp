#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
	std::cout << "=== Testing with std::vector ===" << std::endl;
	{
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 2);

		try
		{
			std::vector<int>::iterator it = easyfind(vec, 6);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::vector<int>::iterator it = easyfind(vec, 42);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Testing with std::list ===" << std::endl;
	{
		std::list<int> lst;
		for (int i = 0; i < 5; i++)
			lst.push_back(i + 100);

		try
		{
			std::list<int>::iterator it = easyfind(lst, 102);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::list<int>::iterator it = easyfind(lst, 999);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Testing with std::deque ===" << std::endl;
	{
		std::deque<int> deq;
		deq.push_back(5);
		deq.push_back(10);
		deq.push_back(15);

		try
		{
			std::deque<int>::iterator it = easyfind(deq, 10);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Testing with empty container ===" << std::endl;
	{
		std::vector<int> empty;
		try
		{
			easyfind(empty, 1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
