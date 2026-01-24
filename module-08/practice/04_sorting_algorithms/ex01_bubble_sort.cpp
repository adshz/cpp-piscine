/* ************************************************************************** */
/*                                                                            */
/*   Exercise 4.1: Bubble Sort                                                */
/*                                                                            */
/*   Goal: Implement the simplest sorting algorithm                           */
/*                                                                            */
/*   CONCEPT:                                                                 */
/*   - Compare adjacent elements and swap if out of order                     */
/*   - Repeat until no swaps needed                                           */
/*   - Like bubbles rising: largest "bubbles up" to the end each pass         */
/*                                                                            */
/*   Time Complexity: O(n²)                                                   */
/*   Space Complexity: O(1) - in-place                                        */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

void printVector(const std::vector<int>& vec, const std::string& label)
{
    std::cout << label << ": ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

/*
** BUBBLE SORT ALGORITHM:
**
** For array [5, 3, 8, 1, 2]:
**
** Pass 1: Compare adjacent pairs, swap if needed
**   [5, 3, 8, 1, 2]  ->  5 > 3? swap  ->  [3, 5, 8, 1, 2]
**   [3, 5, 8, 1, 2]  ->  5 > 8? no    ->  [3, 5, 8, 1, 2]
**   [3, 5, 8, 1, 2]  ->  8 > 1? swap  ->  [3, 5, 1, 8, 2]
**   [3, 5, 1, 8, 2]  ->  8 > 2? swap  ->  [3, 5, 1, 2, 8]
**   After Pass 1: 8 is in final position
**
** Pass 2: Repeat (ignoring last element)
**   [3, 5, 1, 2, 8]  ->  [3, 5, 1, 2, 8]  (3 < 5)
**   [3, 5, 1, 2, 8]  ->  [3, 1, 5, 2, 8]  (5 > 1, swap)
**   [3, 1, 5, 2, 8]  ->  [3, 1, 2, 5, 8]  (5 > 2, swap)
**   After Pass 2: 5 is in final position
**
** Continue until sorted...
*/

void bubbleSort(std::vector<int>& vec)
{
    // TODO: Implement bubble sort
    //
    // Pseudocode:
    // for i from 0 to n-1:
    //     for j from 0 to n-i-1:
    //         if vec[j] > vec[j+1]:
    //             swap vec[j] and vec[j+1]
    //
    // YOUR CODE HERE
}

// BONUS: Optimized version that stops early if already sorted
void bubbleSortOptimized(std::vector<int>& vec)
{
    // TODO: Add a flag to detect if any swaps happened
    // If no swaps in a pass, array is sorted - exit early
    //
    // YOUR CODE HERE
}

int main()
{
    std::cout << "=== Exercise 4.1: Bubble Sort ===" << std::endl;

    std::vector<int> vec;
    vec.push_back(64);
    vec.push_back(34);
    vec.push_back(25);
    vec.push_back(12);
    vec.push_back(22);
    vec.push_back(11);
    vec.push_back(90);

    printVector(vec, "Original");

    bubbleSort(vec);

    printVector(vec, "Sorted  ");

    // Test with already sorted array (for optimized version)
    std::cout << "\n--- Testing optimized version ---" << std::endl;
    std::vector<int> sorted;
    sorted.push_back(1);
    sorted.push_back(2);
    sorted.push_back(3);
    sorted.push_back(4);
    sorted.push_back(5);

    printVector(sorted, "Already sorted");
    bubbleSortOptimized(sorted);
    printVector(sorted, "After sort    ");

    return 0;
}

/*
Expected output:

=== Exercise 4.1: Bubble Sort ===
Original: 64 34 25 12 22 11 90
Sorted  : 11 12 22 25 34 64 90

--- Testing optimized version ---
Already sorted: 1 2 3 4 5
After sort    : 1 2 3 4 5
*/
