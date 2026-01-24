/* ************************************************************************** */
/*                                                                            */
/*   Exercise 1.1: Container Operations                                       */
/*                                                                            */
/*   Goal: Get comfortable with basic STL container methods                   */
/*                                                                            */
/*   TODO:                                                                    */
/*   1. Create a std::vector<int> and add numbers 1-10 using push_back        */
/*   2. Create a std::list<std::string> and add 5 names                       */
/*   3. Create a std::deque<double> and add numbers at BOTH ends              */
/*      (use push_front and push_back)                                        */
/*                                                                            */
/*   For each container, print:                                               */
/*   - Size                                                                   */
/*   - First element (front)                                                  */
/*   - Last element (back)                                                    */
/*   - All elements using iterators                                           */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>

int main()
{
    std::cout << "=== Exercise 1.1: Container Operations ===" << std::endl;

    // ----- Part 1: std::vector<int> -----
    std::cout << "\n--- std::vector<int> ---" << std::endl;

    // TODO: Create vector and add numbers 1-10
    std::vector<int> vec;
    // YOUR CODE HERE

    // TODO: Print size, front, back
    // YOUR CODE HERE

    // TODO: Print all elements using iterators
    // YOUR CODE HERE


    // ----- Part 2: std::list<std::string> -----
    std::cout << "\n--- std::list<std::string> ---" << std::endl;

    // TODO: Create list and add 5 names
    std::list<std::string> names;
    // YOUR CODE HERE

    // TODO: Print size, front, back
    // YOUR CODE HERE

    // TODO: Print all elements using iterators
    // YOUR CODE HERE


    // ----- Part 3: std::deque<double> -----
    std::cout << "\n--- std::deque<double> ---" << std::endl;

    // TODO: Create deque and add numbers at BOTH ends
    // Use push_front for: 1.1, 2.2, 3.3
    // Use push_back for: 7.7, 8.8, 9.9
    std::deque<double> deq;
    // YOUR CODE HERE

    // TODO: Print size, front, back
    // YOUR CODE HERE

    // TODO: Print all elements using iterators
    // YOUR CODE HERE


    return 0;
}

/*
Expected output (example):

=== Exercise 1.1: Container Operations ===

--- std::vector<int> ---
Size: 10
Front: 1
Back: 10
Elements: 1 2 3 4 5 6 7 8 9 10

--- std::list<std::string> ---
Size: 5
Front: Alice
Back: Eve
Elements: Alice Bob Charlie David Eve

--- std::deque<double> ---
Size: 6
Front: 3.3
Back: 9.9
Elements: 3.3 2.2 1.1 7.7 8.8 9.9
*/
