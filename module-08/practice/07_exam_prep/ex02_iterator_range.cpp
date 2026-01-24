/* ************************************************************************** */
/*                                                                            */
/*   Exercise 7.2: Iterator Range Insertion (Preparation for ex01)            */
/*                                                                            */
/*   Goal: Learn to add multiple elements using iterator ranges               */
/*                                                                            */
/*   The Span class needs a method to add many numbers at once!               */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

/*
** ITERATOR RANGE CONCEPT:
**
** Instead of calling addNumber() 10000 times:
**   for (int i = 0; i < 10000; i++)
**       span.addNumber(i);  // 10000 function calls!
**
** We can add all at once using iterators:
**   int arr[] = {1, 2, 3, 4, 5};
**   span.addNumbers(arr, arr + 5);  // Single call!
**
** Or from another container:
**   std::vector<int> source = {...};
**   span.addNumbers(source.begin(), source.end());
**
**
** HOW IT WORKS:
**
** A range is defined by TWO iterators: [begin, end)
** - begin: Points to first element to include
** - end:   Points PAST the last element (not included)
**
** Example: Array [1, 2, 3, 4, 5]
**          Pointers: arr    arr+1  arr+2  arr+3  arr+4  arr+5
**          Values:    1      2      3      4      5     (past end)
**
** Range (arr, arr+5) includes: 1, 2, 3, 4, 5
** Range (arr+1, arr+3) includes: 2, 3
*/

class NumberStorage
{
private:
    std::vector<int>    _numbers;
    unsigned int        _maxSize;

public:
    NumberStorage(unsigned int maxSize) : _maxSize(maxSize) {}

    void addNumber(int n)
    {
        if (_numbers.size() >= _maxSize)
            throw std::runtime_error("Storage is full");
        _numbers.push_back(n);
    }

    // TODO: Implement addNumbers using iterator range
    //
    // This is a TEMPLATE method because we want to accept
    // iterators from ANY container (vector, list, array, etc.)
    //
    // template <typename Iterator>
    // void addNumbers(Iterator begin, Iterator end)
    // {
    //     // Calculate how many elements to add
    //     // Check if there's enough space
    //     // Add each element using addNumber() or direct insertion
    // }
    //
    // YOUR CODE HERE

    void print() const
    {
        std::cout << "Contents (" << _numbers.size() << "/" << _maxSize << "): ";
        for (size_t i = 0; i < _numbers.size(); i++)
            std::cout << _numbers[i] << " ";
        std::cout << std::endl;
    }

    size_t size() const { return _numbers.size(); }
};

int main()
{
    std::cout << "=== Exercise 7.2: Iterator Range Insertion ===" << std::endl;

    NumberStorage storage(20);

    // Method 1: Add from C-style array
    std::cout << "\n--- Adding from array ---" << std::endl;
    int arr[] = {10, 20, 30, 40, 50};

    // TODO: storage.addNumbers(arr, arr + 5);
    storage.print();

    // Method 2: Add from vector
    std::cout << "\n--- Adding from vector ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);

    // TODO: storage.addNumbers(vec.begin(), vec.end());
    storage.print();

    // Method 3: Add from list
    std::cout << "\n--- Adding from list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(1000);
    lst.push_back(2000);

    // TODO: storage.addNumbers(lst.begin(), lst.end());
    storage.print();

    // Method 4: Add partial range
    std::cout << "\n--- Adding partial range ---" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Add only 3, 4, 5, 6 (elements at index 2-5)

    // TODO: storage.addNumbers(numbers + 2, numbers + 6);
    storage.print();

    // Test overflow
    std::cout << "\n--- Testing overflow ---" << std::endl;
    int tooMany[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    try
    {
        // TODO: storage.addNumbers(tooMany, tooMany + 15);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    storage.print();

    return 0;
}

/*
Expected output:

=== Exercise 7.2: Iterator Range Insertion ===

--- Adding from array ---
Contents (5/20): 10 20 30 40 50

--- Adding from vector ---
Contents (8/20): 10 20 30 40 50 100 200 300

--- Adding from list ---
Contents (10/20): 10 20 30 40 50 100 200 300 1000 2000

--- Adding partial range ---
Contents (14/20): 10 20 30 40 50 100 200 300 1000 2000 3 4 5 6

--- Testing overflow ---
Exception caught: Storage is full
Contents (20/20): 10 20 30 40 50 100 200 300 1000 2000 3 4 5 6 1 2 3 4 5 6
*/
