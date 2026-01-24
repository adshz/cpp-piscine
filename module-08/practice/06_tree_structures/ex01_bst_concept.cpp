/* ************************************************************************** */
/*                                                                            */
/*   Exercise 6.1: Binary Search Tree - Concept and Node Structure            */
/*                                                                            */
/*   Goal: Understand BST structure before implementing operations            */
/*                                                                            */
/*   A BST is a tree where for each node:                                     */
/*   - All values in LEFT subtree are SMALLER                                 */
/*   - All values in RIGHT subtree are LARGER                                 */
/*                                                                            */
/*   WHY TREES MATTER:                                                        */
/*   - std::set and std::map use trees internally                             */
/*   - O(log n) search, insert, delete (when balanced)                        */
/*   - Maintains sorted order without expensive array shifting                */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
** BINARY SEARCH TREE VISUALIZATION:
**
**              50              <- Root node
**            /    \
**          30      70          <- Children of 50
**         /  \    /  \
**       20   40  60   80       <- Grandchildren
**
**
** TERMINOLOGY:
** - Node: Contains a value and pointers to children
** - Root: The top node (50 in this example)
** - Leaf: A node with no children (20, 40, 60, 80)
** - Parent/Child: 50 is parent of 30 and 70; 30 is child of 50
** - Height: Longest path from root to leaf (here: 2)
**
**
** BST PROPERTY:
** Look at node 50:
**   - Left subtree (30, 20, 40): ALL values < 50 ✓
**   - Right subtree (70, 60, 80): ALL values > 50 ✓
**
** Look at node 30:
**   - Left child (20): 20 < 30 ✓
**   - Right child (40): 40 > 30 ✓
**
** This property must hold for EVERY node!
*/

// Node structure for BST
struct Node
{
    int     value;      // The data stored
    Node*   left;       // Pointer to left child (smaller values)
    Node*   right;      // Pointer to right child (larger values)

    // Constructor
    Node(int val) : value(val), left(NULL), right(NULL) {}
};

// Create a simple tree manually to understand the structure
int main()
{
    std::cout << "=== Exercise 6.1: BST Concept ===" << std::endl;

    // Create nodes
    Node* root = new Node(50);
    Node* n30 = new Node(30);
    Node* n70 = new Node(70);
    Node* n20 = new Node(20);
    Node* n40 = new Node(40);
    Node* n60 = new Node(60);
    Node* n80 = new Node(80);

    // TODO: Connect the nodes to form this tree:
    //
    //              50
    //            /    \
    //          30      70
    //         /  \    /  \
    //       20   40  60   80
    //
    // Hint: root->left = n30; root->right = n70; etc.
    //
    // YOUR CODE HERE


    // Verify the structure
    std::cout << "\nTree structure:" << std::endl;
    std::cout << "Root: " << root->value << std::endl;

    if (root->left && root->right)
    {
        std::cout << "Root's children: " << root->left->value
                  << " (left), " << root->right->value << " (right)" << std::endl;
    }

    // TODO: Print all leaf nodes (nodes with no children)
    std::cout << "\nLeaf nodes: ";
    // YOUR CODE HERE
    std::cout << std::endl;

    // TODO: Verify BST property
    // For each node, check: left child < node < right child
    std::cout << "\nVerifying BST property:" << std::endl;
    // YOUR CODE HERE


    // Clean up memory
    delete n20;
    delete n40;
    delete n60;
    delete n80;
    delete n30;
    delete n70;
    delete root;

    std::cout << "\nMemory cleaned up." << std::endl;

    return 0;
}

/*
Expected output:

=== Exercise 6.1: BST Concept ===

Tree structure:
Root: 50
Root's children: 30 (left), 70 (right)

Leaf nodes: 20 40 60 80

Verifying BST property:
Node 50: left(30) < 50 < right(70) ✓
Node 30: left(20) < 30 < right(40) ✓
Node 70: left(60) < 70 < right(80) ✓

Memory cleaned up.
*/
