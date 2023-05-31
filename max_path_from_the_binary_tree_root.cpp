/*
You are given a binary tree.
Your task is to find a maximal sum 
from the root of this tree. 
*/

#include <iostream>

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int v) : value(v) {}
};

struct BinaryTree
{
    Node* root;
    BinaryTree(Node* n) : root(n) {}
};

// recursive solution
int maxSum(Node* n)
{
    // sum of empty node is 0
    if(n == nullptr) return 0;
    // in other case we calculate left and right sums below node
    int leftSum = maxSum(n->left);
    int rightSum = maxSum(n->right);

    // than choose the biggest and add the current node value
    return leftSum > rightSum ? n->value + leftSum : n->value + rightSum;
}

int main()
{
    Node n1(5);
    Node n2(2);
    Node n3(6);
    Node n4(1);
    Node n5(8);
    Node n6(3);
    Node n7(2);
    Node n8(3);
    Node n9(1);
    Node n10(9);

    n1.left = &n2;
    n1.right = &n3;

    n2.right = &n4;

    n3.left = &n5;
    n3.right = &n6;

    n4.left = &n7;

    n5.left = &n8;
    n5.right = &n9;

    n6.right = &n10;

    BinaryTree bt(&n1);

    std::cout << maxSum(bt.root) << std::endl;

    Node q1{1}, q2{2}, q3{5};
    q1.left = &q2;
    q1.right = &q3;

    BinaryTree bt2(&q1);
    std::cout << maxSum(&q1) << std::endl;
}

/*
            5
      /             \
    2                6
/      \         /         \
null    1       8           3
      /   \    / \         / \
     2    null 3  1    null   9      
*/