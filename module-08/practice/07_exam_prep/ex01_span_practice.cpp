/* ************************************************************************** */
/*                                                                            */
/*   Exercise 7.1: Span Practice (Preparation for ex01)                       */
/*                                                                            */
/*   Goal: Practice calculating spans using STL algorithms                    */
/*                                                                            */
/*   This exercise prepares you for the Span class in ex01!                   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

/*
** SPAN CONCEPTS:
**
** Given numbers: [6, 3, 17, 9, 11]
**
** LONGEST SPAN: Difference between MAX and MIN
**   max = 17, min = 3
**   longest span = 17 - 3 = 14
**
** SHORTEST SPAN: Smallest difference between ANY two numbers
**   Approach: Sort first, then check adjacent pairs
**
**   Sorted: [3, 6, 9, 11, 17]
**
**   Differences between adjacent pairs:
**   6 - 3 = 3
**   9 - 6 = 3
**   11 - 9 = 2  <- SMALLEST
**   17 - 11 = 6
**
**   shortest span = 2
**
** WHY SORT? Because the shortest span MUST be between two numbers
** that are adjacent when sorted. (Think about it!)
*/

// Calculate longest span (easy version first)
int longestSpan(std::vector<int>& numbers)
{
    if (numbers.size() < 2)
        throw std::logic_error("Need at least 2 numbers");

    // TODO: Find max and min using std::min_element and std::max_element
    // Return max - min
    //
    // YOUR CODE HERE
    return 0;
}

// Calculate shortest span
int shortestSpan(std::vector<int>& numbers)
{
    if (numbers.size() < 2)
        throw std::logic_error("Need at least 2 numbers");

    // TODO:
    // 1. Create a COPY of the vector (don't modify original)
    // 2. Sort the copy
    // 3. Find minimum difference between adjacent elements
    //
    // Hint: Use std::sort(copy.begin(), copy.end())
    //
    // YOUR CODE HERE
    return 0;
}

int main()
{
    std::cout << "=== Exercise 7.1: Span Practice ===" << std::endl;

    std::vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(3);
    numbers.push_back(17);
    numbers.push_back(9);
    numbers.push_back(11);

    std::cout << "Numbers: 6, 3, 17, 9, 11" << std::endl;

    try
    {
        std::cout << "Shortest span: " << shortestSpan(numbers) << std::endl;
        std::cout << "Longest span:  " << longestSpan(numbers) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test edge cases
    std::cout << "\n--- Edge Cases ---" << std::endl;

    std::vector<int> single;
    single.push_back(42);
    try
    {
        shortestSpan(single);
    }
    catch (std::exception& e)
    {
        std::cout << "Single element: " << e.what() << " (CORRECT!)" << std::endl;
    }

    std::vector<int> empty;
    try
    {
        longestSpan(empty);
    }
    catch (std::exception& e)
    {
        std::cout << "Empty vector: " << e.what() << " (CORRECT!)" << std::endl;
    }

    // Test with larger dataset
    std::cout << "\n--- Large Dataset Test ---" << std::endl;
    std::vector<int> large;
    for (int i = 0; i < 10000; i++)
        large.push_back(i * 3);  // 0, 3, 6, 9, ...

    std::cout << "10000 numbers (0, 3, 6, ..., 29997)" << std::endl;
    std::cout << "Shortest span: " << shortestSpan(large) << " (expected: 3)" << std::endl;
    std::cout << "Longest span:  " << longestSpan(large) << " (expected: 29997)" << std::endl;

    return 0;
}

/*
Expected output:

=== Exercise 7.1: Span Practice ===
Numbers: 6, 3, 17, 9, 11
Shortest span: 2
Longest span:  14

--- Edge Cases ---
Single element: Need at least 2 numbers (CORRECT!)
Empty vector: Need at least 2 numbers (CORRECT!)

--- Large Dataset Test ---
10000 numbers (0, 3, 6, ..., 29997)
Shortest span: 3 (expected: 3)
Longest span:  29997 (expected: 29997)
*/
