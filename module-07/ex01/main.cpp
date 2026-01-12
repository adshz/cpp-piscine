#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
	x++;
}

int main(void)
{
	int intArr[] = {1, 2, 3, 4, 5};
	std::cout << "Int array:" << std::endl;
	::iter(intArr, 5, print<int>);

	std::cout << "\nAfter increment:" << std::endl;
	::iter(intArr, 5, increment<int>);
	::iter(intArr, 5, print<int>);

	std::string strArr[] = {"Hello", "World", "42"};
	std::cout << "\nString array:" << std::endl;
	::iter(strArr, 3, print<std::string>);

	double doubleArr[] = {1.1, 2.2, 3.3};
	std::cout << "\nDouble array:" << std::endl;
	::iter(doubleArr, 3, print<double>);

	return 0;
}
