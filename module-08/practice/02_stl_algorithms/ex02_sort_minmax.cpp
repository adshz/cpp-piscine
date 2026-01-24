/* ************************************************************************** */
/*                                                                            */
/*   Exercise 2.2: Sorting and Min/Max                                        */
/*                                                                            */
/*   Goal: Use std::sort, std::min_element, std::max_element                  */
/*                                                                            */
/*   IMPORTANT: These are useful for ex01 (Span)!                             */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>  // std::sort, std::min_element, std::max_element
#include <functional> // std::greater (for descending sort)

// Helper function to print vector
void printVector(const std::vector<int>& vec)
{
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main()
{
    std::cout << "=== Exercise 2.2: Sorting and Min/Max ===" << std::endl;

    // Create vector with: 64, 25, 12, 22, 11, 90, 45
    std::vector<int> vec;
    vec.push_back(64);
    vec.push_back(25);
    vec.push_back(12);
    vec.push_back(22);
    vec.push_back(11);
    vec.push_back(90);
    vec.push_back(45);

    std::cout << "Original: ";
    printVector(vec);

    // ----- Part 1: Find minimum (without sorting) -----
    std::cout << "\n1. Finding min/max WITHOUT sorting..." << std::endl;
    // TODO: Use std::min_element to find the minimum
    // It returns an iterator, so dereference it to get the value
    // Syntax: std::min_element(vec.begin(), vec.end())
    // YOUR CODE HERE


    // ----- Part 2: Find maximum (without sorting) -----
    // TODO: Use std::max_element to find the maximum
    // YOUR CODE HERE


    // ----- Part 3: Sort ascending -----
    std::cout << "\n2. Sorting..." << std::endl;
    // TODO: Use std::sort to sort in ASCENDING order (default)
    // Syntax: std::sort(vec.begin(), vec.end())
    // YOUR CODE HERE
    std::cout << "Ascending: ";
    printVector(vec);

    // ----- Part 4: Sort descending -----
    // TODO: Use std::sort with std::greater<int>() for DESCENDING
    // Syntax: std::sort(vec.begin(), vec.end(), std::greater<int>())
    // YOUR CODE HERE
    std::cout << "Descending: ";
    printVector(vec);


    // ----- BONUS: Calculate span (max - min) -----
    std::cout << "\n3. BONUS: Calculating span..." << std::endl;
    // TODO: Calculate the difference between max and min
    // This is exactly what longestSpan() does in ex01!
    // YOUR CODE HERE

    return 0;
}

/*
Expected output:

=== Exercise 2.2: Sorting and Min/Max ===
Original: 64 25 12 22 11 90 45

1. Finding min/max WITHOUT sorting...
Min: 11
Max: 90

2. Sorting...
Ascending: 11 12 22 25 45 64 90
Descending: 90 64 45 25 22 12 11

3. BONUS: Calculating span...
Span (max - min): 79
*/
