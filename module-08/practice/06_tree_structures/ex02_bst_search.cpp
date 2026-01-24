/* ************************************************************************** */
/*                                                                            */
/*   Exercise 6.2: BST Search Operation                                       */
/*                                                                            */
/*   Goal: Implement searching in a BST - understand why it's O(log n)        */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Node
{
    int     value;
    Node*   left;
    Node*   right;

    Node(int val) : value(val), left(NULL), right(NULL) {}
};

/*
** SEARCH IN BST:
**
** Find 40 in this tree:
**
**              50
**            /    \
**          30      70
**         /  \    /  \
**       20   40  60   80
**
** Step 1: Start at root (50)
**         40 < 50? YES, go LEFT
**
** Step 2: At node 30
**         40 < 30? NO
**         40 > 30? YES, go RIGHT
**
** Step 3: At node 40
**         40 == 40? YES, FOUND!
**
** Total: 3 comparisons (not 7 like linear search!)
**
**
** Find 35 (doesn't exist):
**
** Step 1: 35 < 50, go LEFT
** Step 2: 35 > 30, go RIGHT
** Step 3: At node 40, 35 < 40, go LEFT
** Step 4: 40's left is NULL -> NOT FOUND
*/

// Helper to build our test tree
Node* buildTestTree()
{
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    return root;
}

// Helper to free tree memory
void freeTree(Node* node)
{
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

// Iterative search
Node* searchBST(Node* root, int target)
{
    // TODO: Implement iterative BST search
    //
    // Pseudocode:
    // current = root
    // while current != NULL:
    //     if target == current->value:
    //         return current
    //     else if target < current->value:
    //         current = current->left
    //     else:
    //         current = current->right
    // return NULL  // not found
    //
    // YOUR CODE HERE
    return NULL;
}

// Recursive search
Node* searchBSTRecursive(Node* node, int target)
{
    // TODO: Implement recursive BST search
    //
    // Pseudocode:
    // if node == NULL:
    //     return NULL  // not found
    //
    // if target == node->value:
    //     return node
    // else if target < node->value:
    //     return searchBSTRecursive(node->left, target)
    // else:
    //     return searchBSTRecursive(node->right, target)
    //
    // YOUR CODE HERE
    return NULL;
}

// BONUS: Search with path tracing (shows the search path)
Node* searchBSTWithPath(Node* root, int target)
{
    // TODO: Print each node visited during search
    std::cout << "  Search path: ";
    // YOUR CODE HERE
    std::cout << std::endl;
    return NULL;
}

int main()
{
    std::cout << "=== Exercise 6.2: BST Search ===" << std::endl;

    Node* root = buildTestTree();

    std::cout << "\nTree:" << std::endl;
    std::cout << "        50" << std::endl;
    std::cout << "       /  \\" << std::endl;
    std::cout << "      30   70" << std::endl;
    std::cout << "     / \\  / \\" << std::endl;
    std::cout << "    20 40 60 80" << std::endl;

    // Test iterative search
    std::cout << "\n--- Iterative Search ---" << std::endl;
    Node* result;

    result = searchBST(root, 40);
    std::cout << "Search 40: " << (result ? "Found" : "Not found") << std::endl;

    result = searchBST(root, 35);
    std::cout << "Search 35: " << (result ? "Found" : "Not found") << std::endl;

    result = searchBST(root, 80);
    std::cout << "Search 80: " << (result ? "Found" : "Not found") << std::endl;

    // Test recursive search
    std::cout << "\n--- Recursive Search ---" << std::endl;
    result = searchBSTRecursive(root, 60);
    std::cout << "Search 60: " << (result ? "Found" : "Not found") << std::endl;

    // Test search with path
    std::cout << "\n--- Search with Path ---" << std::endl;
    std::cout << "Finding 40:" << std::endl;
    searchBSTWithPath(root, 40);

    std::cout << "Finding 35:" << std::endl;
    searchBSTWithPath(root, 35);

    freeTree(root);
    return 0;
}

/*
Expected output:

=== Exercise 6.2: BST Search ===

Tree:
        50
       /  \
      30   70
     / \  / \
    20 40 60 80

--- Iterative Search ---
Search 40: Found
Search 35: Not found
Search 80: Found

--- Recursive Search ---
Search 60: Found

--- Search with Path ---
Finding 40:
  Search path: 50 -> 30 -> 40 (FOUND)
Finding 35:
  Search path: 50 -> 30 -> 40 -> NULL (NOT FOUND)
*/
