date: 24/01/2026


## Question 1: Function implementation in header file
 
basically you are not allowed to write regular function implementations in
header files unless template functions are the exception

but we need to know why though

because we need to satisify compiler. you write those template defnition inside
the `.cpp`, the compiler wouldn't know how to generate code for you see
`easyfind<std:vector<int> >`


#### Header Independence
#include <algorithm>  for std::find 
#include <exception> for std::exception

if someone includes your header `easyfind.hpp`, it should work without including
any other headers files


#### Include Guards (Prevent Double Inclusion)

if we don't use include guards, compiler would complain `redeinition errors`

## what mandatory rules are

1. Compile with all tags
2. no using namespace <ns_name>
3. No friend keywords
4. no *printf(), *alloc(), free()
5. no C++11
6. No function implementations in headers
7. Must use include guards 
8. Classes must be in Orthodox Canonical form
9. No memory leaks
10. Module 8 specific: must use STL containers and algorithms


## Question4 : What are associative containers?


Definition of Associative containers is they can store elements in a way users
can look it up by keys, not positions, internally sorted by 
balanced trees


### Container type: Squence Container

Before we talk about associative container, we need to know a different type:
Sequence Container

`vector`, `list`, `deque` are containers storing elements in linear order,
accessed by position

### Container type: Associative Containers

`set`, `map`, `multiset`, `multimap` are containers 

### Comparasion

Squence Container
```c++
std::vector<int> v = {3, 1 , 4};
// this stays the same `[3, 1, 4]`
```

Associative container
// associative container - elements stored by key
std::set<int> s;
s.insert(3);
s.insert(1);
s.insert(4);

// then we can see  internally sorted {1, 3, 4}

std::map<std::string, int> m;
m["apple"] = 5 // key-value pair

### the reason for not associative containers

- `std::find` algorithm works on any iterator range, but `std::map`, `std::set`
would search by valye, not by keys when using std::find algorithm

## question 

- the `std::find` algorithm works on any iterator range, but for `std::map` and
  `std::set` it won't work efficiently because of O(log(n)) v.s. O(n)

then AI gave me a bunch of explanation


### How `std::find` works on Associative Containers?

```c++
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

int main() {
    // ==== std::set example =====
    std::set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);


    // ========O(log (n)) uses tree structure
    // set's own find() - searches BY VALUE - the key in a set
    std::set<int>::iterator it1 = s.find(20);

    // ========O(n) lear scan
    // use std::find - also searches by value, but IGNORES the tree structure
    std::set<int>::iterator its = std::find(s.begin(), s.end(), 20);

    // both find 20 but first one s.find() is much faster for large sets


    // =======std::map example - THIS IS WHERE IT GETS INTERESTING ======
    std::map<std::string, int> ages;
    /*

  std::map<string, int> ages:
  ┌─────────────────────────────┐
  │  Internal Tree Structure    │
  │         ("Bob", 30)         │  ←root
  │        /          \         │
  │ ("Alice", 25)  ("Charlie", 35)
  └─────────────────────────────┘
    */
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 35;

    /*

    */

    // use map's own find() -- searches BY KEY
    std::map<std::string, int>::iterator it3 = ages.find("Bob");
/*
        
ages.find("Charlie"):
    Step 1: 
    Compare "Charlie" with "Bob" → "Charlie" > "Bob" → go RIGHT
    Step 2: Found "Charlie"!
    Total: 2 comparisons (O(log n))

  std::find(ages.begin(), ages.end(), ???):
    What is ??? here? It must be a std::pair<string, int>!

    Step 1: Check ("Alice", 25) == ???
    Step 2: Check ("Bob", 30) == ???
    Step 3: Check ("Charlie", 35) == ???
    Total: Scans ALL elements (O(n))

  ---
*/



    // =======================
    // O(log n)
    // returns iterator to {"Bob", 30};



    // ===== entire pair
    // Must match entire pair, searches for a pair where BOTH key AND value
    match
    std::map<std::string, int>::iteator it4 = std::find(ages.begin(),
                                                        ages.end(),
                                                        std::make_pair(std::string("Bob"), 30);


    return (0);
}
```

`std::map` stores `std::pair<const Key, Value>`



#### Part 2 - O(n), O(log n)

##### Example 1 - Big-O 

how the number of operation grows as the input size (n) increase


Notation O(1) - named as "Constant" 
- Growth Pattern: same time regardless of n
```
n : 8;
O(log n ) operations : 3
O(n) operations: 8
Differences: 2.7x faster
```

n: 64
O(log n) operations: 6
O(n) operations: 64
Difference: 10.7x faster

n (elements): 1,024
  O(log n) operations: 10
  O(n) operations: 1,024
  Difference: 102x faster
  ────────────────────────────────────────
  n (elements): 10,000
  O(log n) operations: ~13
  O(n) operations: 10,000
  Difference: 769x faster
  ────────────────────────────────────────
  n (elements): 1,000,000
  O(log n) operations: ~20
  O(n) operations: 1,000,000
  Difference: 50,000x faster



Notation O(log n)  - named as Logarithmic
- Growth Pattern: Doubles input -> adds 1 operation

Notation O(n) - named as Linear
- Growth Pattern: Doubles input -> doubles operations 

Notation: O(n²) - named Quadratic
- Growht Oattern: Doubles input -> quadruples operations




#### Example 1: Linear Search O(n) - Like looking Through A phone book page by
page

// O(n) - linear search
// int linearSearch(std::vector<int>& vec, int target) {
    for (size_t i = 0; i < vec.size(); i++) {
        if(vec[i] == target) {
            return i;
        }
    }
    return (-1);
}
```

  // Example: Find 7 in [1, 3, 5, 7, 9, 11, 13, 15]
  //   Check 1? No
  //   Check 3? No
  //   Check 5? No
  //   Check 7? YES! Found at index 3
  // Took 4 comparisons. Worst case would be 8 (checking all
  elements)
```
#### Example 2: Binary Search O(log n) - liking looking in a dictionary

```

  // O(log n) - Binary Search (requires SORTED data)
  // Eliminates HALF the remaining elements each step
  int binarySearch(std::vector<int>& sorted, int target)
  {
      int left = 0;
      int right = sorted.size() - 1;

      while (left <= right)
      {
          int mid = (left + right) / 2;

          if (sorted[mid] == target)
              return mid;
          else if (sorted[mid] < target)
              left = mid + 1;   // Eliminate left half
          else
              right = mid - 1;  // Eliminate right half
      }
      return -1;
  }
```



```
Visual: Binary Search for 7 in [1, 3, 5, 7, 9, 11, 13, 15]

  Step 1: Array has 8 elements
  [1, 3, 5, 7, 9, 11, 13, 15]
            ↑ mid = index 3, value = 7
  Compare: 7 == 7? YES! Found!

  Total: 1 comparison (got lucky - was in middle)

  ─────────────────────────────────────────

  Let's try finding 13:

  Step 1: [1, 3, 5, 7, 9, 11, 13, 15]
                   ↑ mid = 7
           7 < 13, so search RIGHT half

  Step 2: [9, 11, 13, 15]  (indices 4-7)
               ↑ mid = 11
           11 < 13, so search RIGHT half

  Step 3: [13, 15]  (indices 6-7)
           ↑ mid = 13
           13 == 13? Found!

  Total: 3 comparisons for 8 elements
         log₂(8) = 3 ✓
```


#### Example 3 - Searching 1 Million Elements

```cpp

 #include <vector>
  #include <set>
  #include <algorithm>

  int main()
  {
      // Create 1,000,000 elements
      std::vector<int> vec;
      std::set<int> s;

      for (int i = 0; i < 1000000; i++)
      {
          vec.push_back(i);
          s.insert(i);
      }

      int target = 999999;  // Worst case: last element

      // Using std::find on vector - O(n)
      // Checks: 0, 1, 2, 3, ... 999,999
      // Total: ~1,000,000 comparisons!
      std::find(vec.begin(), vec.end(), target);

      // Using set's find() - O(log n)
      // Uses binary tree structure
      // Total: ~20 comparisons! (log₂(1,000,000) ≈ 20)
      s.find(target);

      return 0;
  }
```


