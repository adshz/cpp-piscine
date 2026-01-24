/* ************************************************************************** */
/*                                                                            */
/*   Exercise 7.3: Exposing Iterators (Preparation for ex02)                  */
/*                                                                            */
/*   Goal: Learn how to make your class iterable                              */
/*                                                                            */
/*   This is EXACTLY what MutantStack needs to do!                            */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

/*
** THE PROBLEM:
**
** std::stack doesn't have iterators, so you can't do:
**   for (it = stack.begin(); it != stack.end(); ++it)  // ERROR!
**
** THE SOLUTION:
**
** std::stack internally uses another container (default: std::deque)
** That container HAS iterators!
**
** We can EXPOSE those iterators by:
** 1. Inheriting from std::stack
** 2. Providing begin() and end() methods
** 3. Creating iterator typedefs
**
**
** HOW TYPEDEF WORKS:
**
** typedef existing_type new_name;
**
** Example:
**   typedef std::vector<int>::iterator VecIterator;
**   VecIterator it;  // Same as std::vector<int>::iterator it;
*/

// A simple wrapper around std::vector that exposes iterators
class MyContainer
{
private:
    std::vector<int> _data;

public:
    // Create typedef for iterator types
    // This lets users write: MyContainer::iterator it;
    typedef std::vector<int>::iterator          iterator;
    typedef std::vector<int>::const_iterator    const_iterator;

    // Container operations
    void add(int n) { _data.push_back(n); }
    void remove() { if (!_data.empty()) _data.pop_back(); }
    int top() const { return _data.back(); }
    size_t size() const { return _data.size(); }
    bool empty() const { return _data.empty(); }

    // Iterator access - THIS IS THE KEY PART!
    iterator begin() { return _data.begin(); }
    iterator end() { return _data.end(); }
    const_iterator begin() const { return _data.begin(); }
    const_iterator end() const { return _data.end(); }
};


// TODO: Create a class similar to MutantStack
// Use std::list as the underlying container
//
// class IterableStack
// {
// private:
//     std::list<int> _container;
//
// public:
//     // Typedefs for iterators
//     // typedef ...
//
//     // Stack operations: push, pop, top, size, empty
//
//     // Iterator access: begin, end
// };
//
// YOUR CODE HERE


int main()
{
    std::cout << "=== Exercise 7.3: Exposing Iterators ===" << std::endl;

    // Test MyContainer
    std::cout << "\n--- MyContainer (vector-based) ---" << std::endl;
    MyContainer mc;
    mc.add(10);
    mc.add(20);
    mc.add(30);
    mc.add(40);

    std::cout << "Contents: ";
    for (MyContainer::iterator it = mc.begin(); it != mc.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Top element: " << mc.top() << std::endl;
    mc.remove();
    std::cout << "After remove, top: " << mc.top() << std::endl;

    // TODO: Test your IterableStack
    std::cout << "\n--- IterableStack (list-based) ---" << std::endl;

    // IterableStack stack;
    // stack.push(5);
    // stack.push(17);
    // stack.push(3);
    // stack.push(737);
    //
    // std::cout << "Top: " << stack.top() << std::endl;
    // stack.pop();
    // std::cout << "After pop, size: " << stack.size() << std::endl;
    //
    // std::cout << "Iterating: ";
    // for (IterableStack::iterator it = stack.begin(); it != stack.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << std::endl;

    return 0;
}

/*
Expected output:

=== Exercise 7.3: Exposing Iterators ===

--- MyContainer (vector-based) ---
Contents: 10 20 30 40
Top element: 40
After remove, top: 30

--- IterableStack (list-based) ---
Top: 737
After pop, size: 3
Iterating: 5 17 3
*/
