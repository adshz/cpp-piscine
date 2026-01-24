/* ************************************************************************** */
/*                                                                            */
/*   Exercise 4.2: Insertion Sort                                             */
/*                                                                            */
/*   Goal: Implement sorting like sorting playing cards in your hand          */
/*                                                                            */
/*   CONCEPT:                                                                 */
/*   - Build sorted array one element at a time                               */
/*   - Take each element and INSERT it into correct position                  */
/*   - Like sorting cards: pick a card, slide others to make room             */
/*                                                                            */
/*   Time Complexity: O(n²) worst, O(n) best (already sorted)                 */
/*   Space Complexity: O(1) - in-place                                        */
/*                                                                            */
/*   WHY IT'S USEFUL: Very efficient for small arrays or nearly sorted data   */
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
** INSERTION SORT ALGORITHM:
**
** For array [5, 3, 8, 1, 2]:
**
** Start: [5] is "sorted" portion (first element alone)
**
** Step 1: Insert 3 into sorted portion [5]
**   3 < 5, so shift 5 right: [_, 5, 8, 1, 2]
**   Insert 3: [3, 5, 8, 1, 2]
**   Sorted portion: [3, 5]
**
** Step 2: Insert 8 into sorted portion [3, 5]
**   8 > 5, already in correct place
**   Sorted portion: [3, 5, 8]
**
** Step 3: Insert 1 into sorted portion [3, 5, 8]
**   1 < 8, shift 8: [3, 5, _, 8, 2]
**   1 < 5, shift 5: [3, _, 5, 8, 2]
**   1 < 3, shift 3: [_, 3, 5, 8, 2]
**   Insert 1: [1, 3, 5, 8, 2]
**   Sorted portion: [1, 3, 5, 8]
**
** Step 4: Insert 2 into sorted portion [1, 3, 5, 8]
**   2 < 8, shift 8: [1, 3, 5, _, 8]
**   2 < 5, shift 5: [1, 3, _, 5, 8]
**   2 < 3, shift 3: [1, _, 3, 5, 8]
**   2 > 1, stop
**   Insert 2: [1, 2, 3, 5, 8]
**
** Done!
*/

void insertionSort(std::vector<int>& vec)
{
    // TODO: Implement insertion sort
    //
    // Pseudocode:
    // for i from 1 to n-1:
    //     key = vec[i]           // element to insert
    //     j = i - 1              // start from element before key
    //
    //     // Shift elements greater than key to the right
    //     while j >= 0 AND vec[j] > key:
    //         vec[j + 1] = vec[j]
    //         j = j - 1
    //
    //     vec[j + 1] = key       // insert key in correct position
    //
    // YOUR CODE HERE
}

// BONUS: Add debug output to visualize each step
void insertionSortDebug(std::vector<int>& vec)
{
    // TODO: Same as above but print the array after each insertion
    // YOUR CODE HERE
}

int main()
{
    std::cout << "=== Exercise 4.2: Insertion Sort ===" << std::endl;

    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(8);
    vec.push_back(1);
    vec.push_back(2);

    printVector(vec, "Original");

    std::cout << "\n--- Sorting with debug ---" << std::endl;
    insertionSortDebug(vec);

    printVector(vec, "\nFinal   ");

    return 0;
}

/*
Expected output:

=== Exercise 4.2: Insertion Sort ===
Original: 5 3 8 1 2

--- Sorting with debug ---
Insert 3: [3, 5, 8, 1, 2]
Insert 8: [3, 5, 8, 1, 2]
Insert 1: [1, 3, 5, 8, 2]
Insert 2: [1, 2, 3, 5, 8]

Final   : 1 2 3 5 8
*/
