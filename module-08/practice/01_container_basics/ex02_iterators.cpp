/* ************************************************************************** */
/*                                                                            */
/*   Exercise 1.2: Iterator Types                                             */
/*                                                                            */
/*   Goal: Understand different ways to iterate and modify containers         */
/*                                                                            */
/*   TODO:                                                                    */
/*   Create a std::vector<int> with values: 10, 20, 30, 40, 50                */
/*                                                                            */
/*   Print all elements using:                                                */
/*   1. Index-based loop (vec[i])                                             */
/*   2. Iterator loop (it != vec.end())                                       */
/*   3. Reverse iterator (rbegin, rend)                                       */
/*                                                                            */
/*   Then MODIFY each element (double it) using iterators                     */
/*   Print the modified vector                                                */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cout << "=== Exercise 1.2: Iterator Types ===" << std::endl;

    // Create vector with values 10, 20, 30, 40, 50
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    // ----- Part 1: Index-based loop -----
    std::cout << "\n1. Index-based: ";
    // TODO: Print using vec[i]
    // YOUR CODE HERE
    std::cout << std::endl;

    // ----- Part 2: Iterator loop -----
    std::cout << "2. Iterator: ";
    // TODO: Print using iterator (begin to end)
    // Hint: std::vector<int>::iterator it;
    // YOUR CODE HERE
    std::cout << std::endl;

    // ----- Part 3: Reverse iterator -----
    std::cout << "3. Reverse: ";
    // TODO: Print using reverse iterator (rbegin to rend)
    // Hint: std::vector<int>::reverse_iterator rit;
    // YOUR CODE HERE
    std::cout << std::endl;

    // ----- Part 4: Modify using iterators -----
    std::cout << "\n4. Doubling each element..." << std::endl;
    // TODO: Use iterator to double each element (*it = *it * 2)
    // YOUR CODE HERE

    // ----- Part 5: Print modified vector -----
    std::cout << "5. Modified: ";
    // TODO: Print the modified vector
    // YOUR CODE HERE
    std::cout << std::endl;

    return 0;
}

/*
Expected output:

=== Exercise 1.2: Iterator Types ===

1. Index-based: 10 20 30 40 50
2. Iterator: 10 20 30 40 50
3. Reverse: 50 40 30 20 10

4. Doubling each element...
5. Modified: 20 40 60 80 100
*/
