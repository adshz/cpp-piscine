/* ************************************************************************** */
/*                                                                            */
/*   Exercise 2.1: Finding Elements                                           */
/*                                                                            */
/*   Goal: Master std::find and std::find_if                                  */
/*                                                                            */
/*   IMPORTANT: This directly prepares you for ex00 (easyfind)!               */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>  // std::find, std::find_if

// TODO: Write a predicate function for find_if
// This function should return true if the number is greater than 20
// bool isGreaterThan20(int n) { ... }


int main()
{
    std::cout << "=== Exercise 2.1: Finding Elements ===" << std::endl;

    // Create vector with: 5, 12, 7, 23, 8, 15, 42, 3
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(12);
    vec.push_back(7);
    vec.push_back(23);
    vec.push_back(8);
    vec.push_back(15);
    vec.push_back(42);
    vec.push_back(3);

    // ----- Part 1: Find value 23 -----
    std::cout << "\n1. Finding 23..." << std::endl;
    // TODO: Use std::find to locate 23
    // If found, print its position (use std::distance(vec.begin(), it))
    // If not found (it == vec.end()), print "Not found"
    // YOUR CODE HERE


    // ----- Part 2: Find value 99 (doesn't exist) -----
    std::cout << "\n2. Finding 99..." << std::endl;
    // TODO: Use std::find to search for 99
    // Handle the "not found" case properly
    // YOUR CODE HERE


    // ----- Part 3: Find first number > 20 using find_if -----
    std::cout << "\n3. Finding first number > 20..." << std::endl;
    // TODO: Use std::find_if with your predicate function
    // Syntax: std::find_if(vec.begin(), vec.end(), isGreaterThan20)
    // YOUR CODE HERE


    // ----- BONUS Part 4: Find all numbers > 20 -----
    std::cout << "\n4. BONUS: All numbers > 20: ";
    // TODO: Loop using find_if repeatedly to find ALL numbers > 20
    // Hint: After finding one, start searching from (it + 1)
    // YOUR CODE HERE
    std::cout << std::endl;

    return 0;
}

/*
Expected output:

=== Exercise 2.1: Finding Elements ===

1. Finding 23...
Found 23 at position 3

2. Finding 99...
99 not found

3. Finding first number > 20...
First number > 20 is 23 at position 3

4. BONUS: All numbers > 20: 23 42
*/
