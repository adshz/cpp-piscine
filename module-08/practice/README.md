# Module 08 Practice Exercises

## Folder Structure

```
practice/
├── 01_container_basics/     # STL containers: vector, list, deque
├── 02_stl_algorithms/       # std::find, std::sort, std::copy, etc.
├── 03_templates/            # Function and class templates
├── 04_sorting_algorithms/   # Implement sorting from scratch
├── 05_binary_search/        # Binary search variations
├── 06_tree_structures/      # BST, tree traversal
└── 07_exam_prep/            # Exercises mimicking ex00, ex01, ex02
```

## How to Practice

1. Each folder contains exercise files with TODO comments
2. Implement the required functions
3. Compile with: `c++ -Wall -Wextra -Werror -std=c++98 <file>.cpp -o <file>`
4. Run and verify output matches expected

---

# Study Guide: Keywords and Resources

## Books (Recommended)

| Book | Author | Best For |
|------|--------|----------|
| **Introduction to Algorithms (CLRS)** | Cormen, Leiserson, Rivest, Stein | Comprehensive theory, mathematical proofs |
| **Algorithms in C/C++** | Robert Sedgewick | Practical implementations, clear code |
| **The Algorithm Design Manual** | Steven Skiena | Problem-solving approach, real-world examples |
| **Data Structures and Algorithm Analysis in C++** | Mark Allen Weiss | C++ specific, good for interviews |

## Keywords to Search

### Sorting Algorithms
```
Search terms:
- "bubble sort algorithm"
- "selection sort algorithm"
- "insertion sort algorithm"
- "merge sort algorithm explained"
- "quicksort algorithm partition"
- "heap sort algorithm"
- "sorting algorithm visualization"
- "sorting algorithm time complexity comparison"
- "stable vs unstable sorting"
- "in-place sorting algorithm"
```

### Binary Search
```
Search terms:
- "binary search algorithm"
- "binary search iterative vs recursive"
- "binary search edge cases"
- "lower bound upper bound binary search"
- "binary search on answer"
- "binary search variations"
```

### Tree Data Structures
```
Search terms:
- "binary tree vs binary search tree"
- "BST insert delete search"
- "tree traversal inorder preorder postorder"
- "tree traversal visualization"
- "balanced binary search tree"
- "AVL tree rotations"
- "red-black tree explained"
- "why use self-balancing trees"
- "tree height and depth"
- "binary tree implementation C++"
```

### STL Containers (C++ Specific)
```
Search terms:
- "C++ STL containers overview"
- "C++ vector vs list vs deque"
- "C++ set map internal implementation"
- "C++ iterator types"
- "C++ iterator invalidation"
- "C++ STL algorithm header"
- "C++ std::find std::sort example"
```

### Big O Notation / Complexity
```
Search terms:
- "big O notation explained"
- "time complexity cheat sheet"
- "space complexity"
- "amortized analysis"
- "best case worst case average case"
```

## Online Resources

### Visualizations (Highly Recommended for Trees/Sorting)
- **VisuAlgo** (visualgo.net) - Animated algorithms
- **Algorithm Visualizer** - Step-by-step execution
- **USFCA Visualization** - Data structure animations

### Practice Platforms
- **LeetCode** - Search "Easy" tree/sorting problems
- **HackerRank** - Data structures track

### Quick References
- **cppreference.com** - C++ STL documentation
- **cplusplus.com** - Beginner-friendly C++ docs

---

## Complexity Cheat Sheet

### Sorting Algorithms
| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No |

### Data Structures
| Structure | Search | Insert | Delete | Space |
|-----------|--------|--------|--------|-------|
| Array (unsorted) | O(n) | O(1) | O(n) | O(n) |
| Array (sorted) | O(log n) | O(n) | O(n) | O(n) |
| Linked List | O(n) | O(1) | O(1)* | O(n) |
| Binary Search Tree | O(log n)** | O(log n)** | O(log n)** | O(n) |
| Hash Table | O(1)*** | O(1)*** | O(1)*** | O(n) |

*After finding the node
**Average case, worst case O(n) if unbalanced
***Average case, worst case O(n)

---

## Learning Path Suggestion

### Week 1: Foundations
1. Container basics (01_container_basics)
2. STL algorithms (02_stl_algorithms)
3. Understand iterators deeply

### Week 2: Core Algorithms
1. Implement sorting algorithms by hand (04_sorting_algorithms)
2. Master binary search (05_binary_search)

### Week 3: Trees
1. Understand BST concept (06_tree_structures)
2. Implement basic BST operations
3. Understand why std::set/std::map use trees

### Week 4: Integration & Exam Prep
1. Templates (03_templates)
2. Exam prep exercises (07_exam_prep)
3. Review your ex00, ex01, ex02 implementations
