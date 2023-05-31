/*
You are given a single-linked list.
Your task is to find its middle element.
If there are two elements, return the second one.
*/

#include <iostream>

struct Node
{
    int value;
    Node* next = nullptr;
    Node(int v): value(v) {}
};

// we create two iterators 
// slower one goes from one element to another in a row
// faster - jumps over one
// as a result when the faster one reaches the end of the list
// the slower one will be in the middle

Node* findMiddle(Node* first)
{
    auto slowIt = first, fastIt = first;
    // we should check both fastIt && fastIt->next
    // to avoid null pointer dereference
    while(fastIt && fastIt->next)
    {
        slowIt = slowIt->next;
        fastIt = fastIt->next->next;
    }
    return slowIt;
}

int main()
{
    Node n1{1}, n2{2}, n3{3}, n4{4}, n5{5};
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    std::cout << findMiddle(&n1)->value << std::endl;

    Node n6{6};
    n5.next = &n6;
    std::cout << findMiddle(&n1)->value << std::endl;
}