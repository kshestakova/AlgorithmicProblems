#include <iostream>

/** You need to find a path with the biggest sum in a binary tree.
 * This path should be started in the root of the tree 
 * and ended on one of the leaves with no leaves for it
 */

struct Node
{
    Node* left{nullptr};
    Node* right{nullptr};
    int value;

    Node(int v) : value(v) {}
};

struct BinaryTree
{
    Node* root;
    BinaryTree(Node* n) : root(n) {}
};

int countMaxOneWayPath(Node* n)
{
    if(!n) return 0;

    int leftSum = countMaxOneWayPath(n->left);
    int rightSum = countMaxOneWayPath(n->right);
    return leftSum > rightSum ? leftSum + n->value : rightSum + n->value;
}

int main()
{
    Node n1{1};

    BinaryTree bt{&n1};

    Node n2{-2}, n3{3}, n4{6}, n5{-5}, n6{3};
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
//  n3.left = &n6; - for another way test

    std::cout << countMaxOneWayPath(bt.root); 

}

/**
 *            ^ 1
 *          /      \
 *      ^ -2         3
 *       /   \     /
 *    ^ 6     -5  3
 * 
*/