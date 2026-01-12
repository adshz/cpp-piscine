#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main(void)
{
	std::cout << "=== Subject test with MutantStack ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n=== Same test with std::list ===" << std::endl;
	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n=== Additional tests ===" << std::endl;
	{
		MutantStack<int> mstack;
		for (int i = 0; i < 10; i++)
			mstack.push(i);

		std::cout << "Forward iteration: ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "Reverse iteration: ";
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== Test copy constructor ===" << std::endl;
	{
		MutantStack<int> original;
		original.push(1);
		original.push(2);
		original.push(3);

		MutantStack<int> copy(original);
		std::cout << "Original top: " << original.top() << std::endl;
		std::cout << "Copy top: " << copy.top() << std::endl;

		copy.push(100);
		std::cout << "After modifying copy - Original top: " << original.top() << std::endl;
		std::cout << "After modifying copy - Copy top: " << copy.top() << std::endl;
	}

	std::cout << "\n=== Test assignment operator ===" << std::endl;
	{
		MutantStack<int> original;
		original.push(10);
		original.push(20);

		MutantStack<int> assigned;
		assigned = original;

		std::cout << "Original: ";
		for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "Assigned: ";
		for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== Test with strings ===" << std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("Hello");
		mstack.push("World");
		mstack.push("42");

		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << std::endl;
	}

	return 0;
}
