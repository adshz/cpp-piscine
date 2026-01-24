/* ************************************************************************** */
/*                                                                            */
/*   Exercise 3.1: Function Templates                                         */
/*                                                                            */
/*   Goal: Write templates that work with any container type                  */
/*                                                                            */
/*   This is DIRECTLY relevant to ex00 (easyfind)!                            */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>

/*
** TEMPLATE BASICS:
**
** Instead of writing separate functions for each type:
**   void printVector(std::vector<int>& v) { ... }
**   void printList(std::list<int>& l) { ... }
**
** We write ONE template:
**   template <typename T>
**   void printContainer(T& container) { ... }
**
** The compiler generates specific versions when needed!
*/

// TODO: Write a function template that prints any container
//
// template <typename T>
// void printContainer(const T& container)
// {
//     // Use typename T::const_iterator for the iterator type
//     // Iterate from container.begin() to container.end()
// }
//
// YOUR CODE HERE


// TODO: Write a function template that returns the sum of elements
//
// template <typename T>
// int sumContainer(const T& container)
// {
//     // Sum all elements and return total
// }
//
// YOUR CODE HERE


// TODO: Write a function template that finds an element
// This is similar to easyfind!
//
// template <typename T>
// typename T::const_iterator findElement(const T& container, int value)
// {
//     // Use std::find or manual loop
//     // Return iterator to found element, or container.end() if not found
// }
//
// YOUR CODE HERE


int main()
{
    std::cout << "=== Exercise 3.1: Function Templates ===" << std::endl;

    // Test with vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    // Test with list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    // Test with deque
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);

    std::cout << "\n--- printContainer ---" << std::endl;
    std::cout << "Vector: ";
    // TODO: printContainer(vec);
    std::cout << std::endl;

    std::cout << "List:   ";
    // TODO: printContainer(lst);
    std::cout << std::endl;

    std::cout << "Deque:  ";
    // TODO: printContainer(deq);
    std::cout << std::endl;

    std::cout << "\n--- sumContainer ---" << std::endl;
    // TODO: std::cout << "Vector sum: " << sumContainer(vec) << std::endl;
    // TODO: std::cout << "List sum:   " << sumContainer(lst) << std::endl;
    // TODO: std::cout << "Deque sum:  " << sumContainer(deq) << std::endl;

    std::cout << "\n--- findElement ---" << std::endl;
    // TODO: Test findElement with each container
    // std::vector<int>::const_iterator it = findElement(vec, 3);
    // if (it != vec.end())
    //     std::cout << "Found " << *it << " in vector" << std::endl;

    return 0;
}

/*
Expected output:

=== Exercise 3.1: Function Templates ===

--- printContainer ---
Vector: 1 2 3 4 5
List:   10 20 30
Deque:  100 200 300

--- sumContainer ---
Vector sum: 15
List sum:   60
Deque sum:  600

--- findElement ---
Found 3 in vector
Found 20 in list
Element 999 not found in deque
*/
