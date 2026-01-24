/* ************************************************************************** */
/*                                                                            */
/*   Exercise 6.3: BST Insert Operation                                       */
/*                                                                            */
/*   Goal: Implement insertion - understand why it's O(log n)                 */
/*                                                                            */
/*   This is the KEY advantage of trees over sorted arrays!                   */
/*   - Sorted array insert: O(n) - must shift elements                        */
/*   - BST insert: O(log n) - just add a new node                             */
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
** INSERT INTO BST:
**
** Insert 35 into this tree:
**
**              50
**            /    \
**          30      70
**         /  \
**       20   40
**
** Step 1: 35 < 50, go LEFT
** Step 2: 35 > 30, go RIGHT
** Step 3: 35 < 40, go LEFT
** Step 4: 40's left is NULL, INSERT HERE!
**
** Result:
**              50
**            /    \
**          30      70
**         /  \
**       20   40
**           /
**          35   <- New node!
**
** No shifting required! Just created a new node and linked it.
*/

// Helper to free tree memory
void freeTree(Node* node)
{
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

// Print tree in-order (gives sorted output!)
void printInOrder(Node* node)
{
    if (node == NULL) return;
    printInOrder(node->left);
    std::cout << node->value << " ";
    printInOrder(node->right);
}

// Iterative insert
Node* insertBST(Node* root, int value)
{
    // TODO: Implement iterative BST insert
    //
    // Pseudocode:
    // newNode = create new Node(value)
    //
    // if root == NULL:
    //     return newNode  // tree was empty
    //
    // current = root
    // while true:
    //     if value < current->value:
    //         if current->left == NULL:
    //             current->left = newNode
    //             break
    //         current = current->left
    //     else:
    //         if current->right == NULL:
    //             current->right = newNode
    //             break
    //         current = current->right
    //
    // return root
    //
    // YOUR CODE HERE
    return root;
}

// Recursive insert (more elegant!)
Node* insertBSTRecursive(Node* node, int value)
{
    // TODO: Implement recursive BST insert
    //
    // Pseudocode:
    // if node == NULL:
    //     return new Node(value)  // base case
    //
    // if value < node->value:
    //     node->left = insertBSTRecursive(node->left, value)
    // else:
    //     node->right = insertBSTRecursive(node->right, value)
    //
    // return node
    //
    // YOUR CODE HERE
    return node;
}

int main()
{
    std::cout << "=== Exercise 6.3: BST Insert ===" << std::endl;

    // Build tree by inserting elements
    std::cout << "\nBuilding tree with: 50, 30, 70, 20, 40, 60, 80" << std::endl;

    Node* root = NULL;

    // TODO: Use your insert function to build the tree
    // root = insertBST(root, 50);
    // root = insertBST(root, 30);
    // ... etc
    //
    // YOUR CODE HERE

    std::cout << "In-order traversal (should be sorted): ";
    printInOrder(root);
    std::cout << std::endl;

    // Insert more elements
    std::cout << "\nInserting: 35, 65, 25" << std::endl;
    // TODO: Insert these values
    // YOUR CODE HERE

    std::cout << "In-order traversal: ";
    printInOrder(root);
    std::cout << std::endl;

    // Visualize the final tree
    std::cout << "\nFinal tree structure:" << std::endl;
    std::cout << "            50" << std::endl;
    std::cout << "          /    \\" << std::endl;
    std::cout << "        30      70" << std::endl;
    std::cout << "       /  \\    /  \\" << std::endl;
    std::cout << "      20  40  60  80" << std::endl;
    std::cout << "       \\  /    \\" << std::endl;
    std::cout << "       25 35   65" << std::endl;

    freeTree(root);
    return 0;
}

/*
Expected output:

=== Exercise 6.3: BST Insert ===

Building tree with: 50, 30, 70, 20, 40, 60, 80
In-order traversal (should be sorted): 20 30 40 50 60 70 80

Inserting: 35, 65, 25
In-order traversal: 20 25 30 35 40 50 60 65 70 80

Final tree structure:
            50
          /    \
        30      70
       /  \    /  \
      20  40  60  80
       \  /    \
       25 35   65
*/
