/* ************************************************************************** */
/*                                                                            */
/*   Exercise 6.4: Tree Traversal                                             */
/*                                                                            */
/*   Goal: Learn the three main ways to traverse a tree                       */
/*                                                                            */
/*   Three traversal methods:                                                 */
/*   1. In-order:   Left, Root, Right  -> Gives SORTED output for BST!        */
/*   2. Pre-order:  Root, Left, Right  -> Useful for copying tree             */
/*   3. Post-order: Left, Right, Root  -> Useful for deleting tree            */
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
** TREE TRAVERSAL VISUALIZATION:
**
**              50
**            /    \
**          30      70
**         /  \    /
**       20   40  60
**
** IN-ORDER (Left, Root, Right):
**   Visit order: 20 -> 30 -> 40 -> 50 -> 60 -> 70
**   Output: 20 30 40 50 60 70 (SORTED!)
**
** PRE-ORDER (Root, Left, Right):
**   Visit order: 50 -> 30 -> 20 -> 40 -> 70 -> 60
**   Output: 50 30 20 40 70 60
**
** POST-ORDER (Left, Right, Root):
**   Visit order: 20 -> 40 -> 30 -> 60 -> 70 -> 50
**   Output: 20 40 30 60 70 50
**
**
** WHY EACH IS USEFUL:
** - In-order:   Get sorted elements from BST (like std::set iteration!)
** - Pre-order:  Serialize/copy a tree (root comes first)
** - Post-order: Delete tree safely (children deleted before parent)
*/

Node* buildTestTree()
{
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    return root;
}

// In-order traversal: Left, Root, Right
void inOrder(Node* node)
{
    // TODO: Implement in-order traversal
    //
    // Pseudocode:
    // if node == NULL:
    //     return
    // inOrder(node->left)      // 1. Visit left subtree
    // print node->value        // 2. Visit root
    // inOrder(node->right)     // 3. Visit right subtree
    //
    // YOUR CODE HERE
}

// Pre-order traversal: Root, Left, Right
void preOrder(Node* node)
{
    // TODO: Implement pre-order traversal
    //
    // Pseudocode:
    // if node == NULL:
    //     return
    // print node->value        // 1. Visit root
    // preOrder(node->left)     // 2. Visit left subtree
    // preOrder(node->right)    // 3. Visit right subtree
    //
    // YOUR CODE HERE
}

// Post-order traversal: Left, Right, Root
void postOrder(Node* node)
{
    // TODO: Implement post-order traversal
    //
    // Pseudocode:
    // if node == NULL:
    //     return
    // postOrder(node->left)    // 1. Visit left subtree
    // postOrder(node->right)   // 2. Visit right subtree
    // print node->value        // 3. Visit root
    //
    // YOUR CODE HERE
}

// BONUS: Count total nodes
int countNodes(Node* node)
{
    // TODO: Count all nodes in tree
    // Hint: Use any traversal method
    // YOUR CODE HERE
    return 0;
}

// BONUS: Calculate tree height
int treeHeight(Node* node)
{
    // TODO: Find the height (longest path from root to leaf)
    // Hint: height = 1 + max(height(left), height(right))
    // YOUR CODE HERE
    return 0;
}

// Free tree using post-order (safest way!)
void freeTree(Node* node)
{
    if (node == NULL) return;
    freeTree(node->left);    // Free left subtree
    freeTree(node->right);   // Free right subtree
    delete node;             // Then free this node
}

int main()
{
    std::cout << "=== Exercise 6.4: Tree Traversal ===" << std::endl;

    Node* root = buildTestTree();

    std::cout << "\nTree:" << std::endl;
    std::cout << "        50" << std::endl;
    std::cout << "       /  \\" << std::endl;
    std::cout << "      30   70" << std::endl;
    std::cout << "     / \\  /" << std::endl;
    std::cout << "    20 40 60" << std::endl;

    std::cout << "\n--- Traversals ---" << std::endl;

    std::cout << "In-order (sorted):  ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Pre-order:          ";
    preOrder(root);
    std::cout << std::endl;

    std::cout << "Post-order:         ";
    postOrder(root);
    std::cout << std::endl;

    std::cout << "\n--- Bonus ---" << std::endl;
    std::cout << "Total nodes: " << countNodes(root) << std::endl;
    std::cout << "Tree height: " << treeHeight(root) << std::endl;

    freeTree(root);
    return 0;
}

/*
Expected output:

=== Exercise 6.4: Tree Traversal ===

Tree:
        50
       /  \
      30   70
     / \  /
    20 40 60

--- Traversals ---
In-order (sorted):  20 30 40 50 60 70
Pre-order:          50 30 20 40 70 60
Post-order:         20 40 30 60 70 50

--- Bonus ---
Total nodes: 6
Tree height: 2
*/
