#include <iostream>

struct Node
{
    int value;
    Node* left;
    Node* right;
    Node(int v = 0) : value(v), left(nullptr), right(nullptr) {}
    friend std::ostream& operator<<(std::ostream& stream, Node const& n);
};

std::ostream& operator<<(std::ostream& stream, Node* const& n)
{
    stream << n->value << std::endl;
    return stream;
}

struct BinaryTree 
{
    Node* root;
    BinaryTree() : root(nullptr) {}

    void PreorderTraversal();
    void InorderTraversal();
    void PostorderTraversal();
};

void BinaryTree::PreorderTraversal()
{
    // root - then left subtree - then right subtree
    if(root) 
    {
        std::cout << root;
        if(root->left)
        {
            BinaryTree left;
            left.root = root->left;
            left.PreorderTraversal();
        }
        if(root->right)
        {
            BinaryTree right;
            right.root = root->right;
            right.PreorderTraversal();
        }
    }
}

void BinaryTree::InorderTraversal()
{
    // left subtree - then root - then right subtree
    if(root) 
    {
        if(root->left)
        {
            BinaryTree left;
            left.root = root->left;
            left.InorderTraversal();
        }
        std::cout << root;
        if(root->right)
        {
            BinaryTree right;
            right.root = root->right;
            right.InorderTraversal();
        }
    }
}

void BinaryTree::PostorderTraversal()
{
    // left subtree - then right subtree - then root
    if(root) 
    {
        if(root->left)
        {
            BinaryTree left;
            left.root = root->left;
            left.PostorderTraversal();
        }
        if(root->right)
        {
            BinaryTree right;
            right.root = root->right;
            right.PostorderTraversal();
        }
        std::cout << root;
    }
}

int main()
{
    Node n1{1};
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);
    Node n7(7);
    Node n8(8);
    Node n9(9);
    Node n10(10);

    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;
    n2.right = &n5;

    n3.left = &n6;
    n3.right = &n7;

    n4.left = &n8;
    n4.right = &n9;

    n8.left = &n10;

    BinaryTree bt;
    bt.root = &n1;

    std::cout << "PreorderTraversal\n";
    bt.PreorderTraversal();
    std::cout << "InorderTraversal\n";
    bt.InorderTraversal();
    std::cout << "PostorderTraversal\n";
    bt.PostorderTraversal();

}