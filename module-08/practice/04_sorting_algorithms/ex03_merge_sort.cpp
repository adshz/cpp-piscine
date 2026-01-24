/* ************************************************************************** */
/*                                                                            */
/*   Exercise 4.3: Merge Sort                                                 */
/*                                                                            */
/*   Goal: Implement a divide-and-conquer sorting algorithm                   */
/*                                                                            */
/*   CONCEPT:                                                                 */
/*   - Divide array into two halves                                           */
/*   - Recursively sort each half                                             */
/*   - Merge the two sorted halves                                            */
/*                                                                            */
/*   Time Complexity: O(n log n) - always!                                    */
/*   Space Complexity: O(n) - needs extra space for merging                   */
/*                                                                            */
/*   WHY IT'S IMPORTANT: Guaranteed O(n log n), stable sort                   */
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
** MERGE SORT ALGORITHM:
**
** For array [38, 27, 43, 3, 9, 82, 10]:
**
**                [38, 27, 43, 3, 9, 82, 10]
**                        /            \
**           [38, 27, 43, 3]    [9, 82, 10]        <- Divide
**             /        \          /      \
**       [38, 27]    [43, 3]   [9, 82]   [10]      <- Divide
**        /    \      /    \    /    \     |
**      [38]  [27]  [43]  [3] [9]  [82]  [10]      <- Base case (size 1)
**        \    /      \    /    \    /     |
**       [27, 38]    [3, 43]   [9, 82]   [10]      <- Merge pairs
**             \        /          \      /
**           [3, 27, 38, 43]    [9, 10, 82]        <- Merge
**                        \            /
**               [3, 9, 10, 27, 38, 43, 82]        <- Final merge
**
**
** THE MERGE OPERATION (the key part):
**
** Merge [27, 38] and [3, 43]:
**   Compare 27 and 3:  3 < 27, take 3   -> [3]
**   Compare 27 and 43: 27 < 43, take 27 -> [3, 27]
**   Compare 38 and 43: 38 < 43, take 38 -> [3, 27, 38]
**   Only 43 left, take 43               -> [3, 27, 38, 43]
*/

// Merge two sorted subarrays: vec[left..mid] and vec[mid+1..right]
void merge(std::vector<int>& vec, int left, int mid, int right)
{
    // TODO: Implement the merge operation
    //
    // Pseudocode:
    // 1. Create temporary arrays for left and right halves
    // 2. Copy data to temp arrays
    // 3. Merge temp arrays back into vec[left..right]
    //    - Compare elements from both halves
    //    - Take the smaller one
    // 4. Copy any remaining elements
    //
    // YOUR CODE HERE
}

void mergeSort(std::vector<int>& vec, int left, int right)
{
    // TODO: Implement merge sort recursively
    //
    // Pseudocode:
    // if left < right:
    //     mid = (left + right) / 2
    //     mergeSort(vec, left, mid)      // Sort left half
    //     mergeSort(vec, mid + 1, right) // Sort right half
    //     merge(vec, left, mid, right)   // Merge sorted halves
    //
    // YOUR CODE HERE
}

// Wrapper function
void mergeSort(std::vector<int>& vec)
{
    if (vec.size() > 1)
        mergeSort(vec, 0, vec.size() - 1);
}

int main()
{
    std::cout << "=== Exercise 4.3: Merge Sort ===" << std::endl;

    std::vector<int> vec;
    vec.push_back(38);
    vec.push_back(27);
    vec.push_back(43);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(82);
    vec.push_back(10);

    printVector(vec, "Original");

    mergeSort(vec);

    printVector(vec, "Sorted  ");

    // Test edge cases
    std::cout << "\n--- Edge cases ---" << std::endl;

    std::vector<int> empty;
    mergeSort(empty);
    std::cout << "Empty array: OK" << std::endl;

    std::vector<int> single;
    single.push_back(42);
    mergeSort(single);
    printVector(single, "Single element");

    return 0;
}

/*
Expected output:

=== Exercise 4.3: Merge Sort ===
Original: 38 27 43 3 9 82 10
Sorted  : 3 9 10 27 38 43 82

--- Edge cases ---
Empty array: OK
Single element: 42
*/
