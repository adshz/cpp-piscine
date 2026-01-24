/* ************************************************************************** */
/*                                                                            */
/*   Exercise 2.3: Count and Accumulate                                       */
/*                                                                            */
/*   Goal: Use std::count, std::count_if, std::accumulate                     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>  // std::count, std::count_if
#include <numeric>    // std::accumulate

// TODO: Write a predicate function to check if a number is even
// bool isEven(int n) { ... }


int main()
{
    std::cout << "=== Exercise 2.3: Count and Accumulate ===" << std::endl;

    // Create vector with: 1, 2, 3, 2, 4, 2, 5, 2, 6
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(6);

    std::cout << "Vector: 1 2 3 2 4 2 5 2 6" << std::endl;

    // ----- Part 1: Count occurrences of 2 -----
    std::cout << "\n1. Counting 2s..." << std::endl;
    // TODO: Use std::count to count how many times 2 appears
    // Syntax: std::count(vec.begin(), vec.end(), value)
    // YOUR CODE HERE


    // ----- Part 2: Count even numbers -----
    std::cout << "\n2. Counting even numbers..." << std::endl;
    // TODO: Use std::count_if with your isEven predicate
    // Syntax: std::count_if(vec.begin(), vec.end(), isEven)
    // YOUR CODE HERE


    // ----- Part 3: Calculate sum -----
    std::cout << "\n3. Calculating sum..." << std::endl;
    // TODO: Use std::accumulate to sum all elements
    // Syntax: std::accumulate(vec.begin(), vec.end(), initial_value)
    // The initial value is typically 0 for sum
    // YOUR CODE HERE


    // ----- Part 4: Calculate product -----
    std::cout << "\n4. Calculating product..." << std::endl;
    // TODO: Use std::accumulate with a custom operation for product
    // Syntax: std::accumulate(vec.begin(), vec.end(), initial, operation)
    // For multiplication, initial should be 1
    // The operation can be std::multiplies<int>() from <functional>
    // YOUR CODE HERE

    return 0;
}

/*
Expected output:

=== Exercise 2.3: Count and Accumulate ===
Vector: 1 2 3 2 4 2 5 2 6

1. Counting 2s...
Count of 2: 4

2. Counting even numbers...
Even numbers: 6

3. Calculating sum...
Sum: 27

4. Calculating product...
Product: 5760
*/
