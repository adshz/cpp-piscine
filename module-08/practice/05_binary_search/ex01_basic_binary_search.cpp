/* ************************************************************************** */
/*                                                                            */
/*   Exercise 5.1: Basic Binary Search                                        */
/*                                                                            */
/*   Goal: Implement binary search - the foundation of O(log n) searching     */
/*                                                                            */
/*   CONCEPT:                                                                 */
/*   - REQUIRES sorted array                                                  */
/*   - Check middle element                                                   */
/*   - If target < middle, search left half                                   */
/*   - If target > middle, search right half                                  */
/*   - Repeat until found or no elements left                                 */
/*                                                                            */
/*   Time Complexity: O(log n)                                                */
/*   Space Complexity: O(1) iterative, O(log n) recursive                     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

/*
** BINARY SEARCH VISUALIZATION:
**
** Array: [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
** Target: 23
**
** Step 1: left=0, right=9, mid=4
**   [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
**    L           M                    R
**   vec[4]=16, 23 > 16, search RIGHT
**
** Step 2: left=5, right=9, mid=7
**   [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
**                     L       M       R
**   vec[7]=56, 23 < 56, search LEFT
**
** Step 3: left=5, right=6, mid=5
**   [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
**                     LM   R
**   vec[5]=23, FOUND!
**
** Total: 3 comparisons for 10 elements (log₂(10) ≈ 3.3)
*/

// Iterative version
int binarySearch(const std::vector<int>& vec, int target)
{
    // TODO: Implement iterative binary search
    //
    // Pseudocode:
    // left = 0
    // right = vec.size() - 1
    //
    // while left <= right:
    //     mid = (left + right) / 2
    //
    //     if vec[mid] == target:
    //         return mid
    //     else if vec[mid] < target:
    //         left = mid + 1
    //     else:
    //         right = mid - 1
    //
    // return -1  // not found
    //
    // YOUR CODE HERE
    return -1;
}

// Recursive version
int binarySearchRecursive(const std::vector<int>& vec, int target, int left, int right)
{
    // TODO: Implement recursive binary search
    //
    // Pseudocode:
    // if left > right:
    //     return -1  // base case: not found
    //
    // mid = (left + right) / 2
    //
    // if vec[mid] == target:
    //     return mid
    // else if vec[mid] < target:
    //     return binarySearchRecursive(vec, target, mid + 1, right)
    // else:
    //     return binarySearchRecursive(vec, target, left, mid - 1)
    //
    // YOUR CODE HERE
    return -1;
}

// Wrapper for recursive version
int binarySearchRecursive(const std::vector<int>& vec, int target)
{
    return binarySearchRecursive(vec, target, 0, vec.size() - 1);
}

// BONUS: Binary search with step-by-step output
int binarySearchDebug(const std::vector<int>& vec, int target)
{
    // TODO: Same as iterative but print each step
    // YOUR CODE HERE
    return -1;
}

int main()
{
    std::cout << "=== Exercise 5.1: Basic Binary Search ===" << std::endl;

    // Create sorted vector
    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(8);
    vec.push_back(12);
    vec.push_back(16);
    vec.push_back(23);
    vec.push_back(38);
    vec.push_back(56);
    vec.push_back(72);
    vec.push_back(91);

    std::cout << "Array: [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]" << std::endl;

    // Test iterative version
    std::cout << "\n--- Iterative Binary Search ---" << std::endl;
    int result = binarySearch(vec, 23);
    std::cout << "Search for 23: " << (result != -1 ? "Found at index " : "Not found");
    if (result != -1) std::cout << result;
    std::cout << std::endl;

    result = binarySearch(vec, 100);
    std::cout << "Search for 100: " << (result != -1 ? "Found at index " : "Not found");
    if (result != -1) std::cout << result;
    std::cout << std::endl;

    // Test recursive version
    std::cout << "\n--- Recursive Binary Search ---" << std::endl;
    result = binarySearchRecursive(vec, 8);
    std::cout << "Search for 8: " << (result != -1 ? "Found at index " : "Not found");
    if (result != -1) std::cout << result;
    std::cout << std::endl;

    // Debug version
    std::cout << "\n--- Debug Binary Search (find 38) ---" << std::endl;
    binarySearchDebug(vec, 38);

    return 0;
}

/*
Expected output:

=== Exercise 5.1: Basic Binary Search ===
Array: [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]

--- Iterative Binary Search ---
Search for 23: Found at index 5
Search for 100: Not found

--- Recursive Binary Search ---
Search for 8: Found at index 2

--- Debug Binary Search (find 38) ---
Step 1: left=0, right=9, mid=4, vec[4]=16, 38 > 16, go RIGHT
Step 2: left=5, right=9, mid=7, vec[7]=56, 38 < 56, go LEFT
Step 3: left=5, right=6, mid=5, vec[5]=23, 38 > 23, go RIGHT
Step 4: left=6, right=6, mid=6, vec[6]=38, FOUND!
*/
