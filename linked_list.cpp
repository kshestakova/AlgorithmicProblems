#include <iostream>

struct Node 
{
    int data;
    Node* next;

    Node(int data) 
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList 
{
    Node* head;
    Node* tail;

public:
    LinkedList() 
    {
        head = nullptr;
        tail = nullptr;
    }

    Node* getHead() 
    {
        return head;
    }

    Node* getTail() 
    {
        return tail;
    }

    // Adding element to the end of the list
    void addElement(int data) 
    {
        Node* newNode = new Node(data);
        if (head == nullptr) 
        {
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            // Now an old tail node has the next element
            tail->next = newNode;
            // And this element becomes the tail of the list
            tail = newNode;
        }
    }

    // Removing element at specified index
    void removeAtIndex(int index) 
    {
        // Empty list
        if (head == nullptr)
            return;
        
        // Deleting head
        if (index == 0) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 0; current != nullptr && i < index - 1; ++i) 
        {
            current = current->next;
        }

        // Can't delete a node out of the list
        if (current == nullptr || current->next == nullptr)
            return;

        // Next for the prevoius node becomes next to the current
        // In fact we're breaking links in the list
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Reversing the elements of the linked list
    void reverse() 
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        // Swapping next and previous nodes
        while (current != nullptr) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Deleting element by its pointer with O(1) complexity
    void deleteNodeByPointer(Node* ptr) 
    {
        // For empty node or empty list
        if (ptr == nullptr || head == nullptr)
            return;

        // If the node to delete is not the tail
        // Copying next node to the node to be deleted
        if (ptr->next != nullptr) 
        {
            Node* nextNode = ptr->next;
            ptr->data = nextNode->data;
            ptr->next = nextNode->next;
            delete nextNode;
            return;
        }

        // If the node to delete is the tail
        // This case doesn't have o(1) complexity, but it's just only one corner case
        // If it is critical, we can preserve also a node prev, for which prev->next == tail

        Node* current = head;
        while (current->next != ptr) 
        {
            current = current->next;
        }
        current->next = nullptr;
        delete ptr;
    }

    // Displaying the elements of the list
    void display() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;

    // Adding elements to the list
    list.addElement(1);
    list.addElement(2);
    list.addElement(3);
    list.addElement(4);
    list.addElement(5);

    std::cout << "Original list: ";
    list.display();

    // Removing element at index 2
    list.removeAtIndex(2);
    std::cout << "List after removing element at index 2: ";
    list.display();

    // Reversing the list
    list.reverse();
    std::cout << "Reversed list: ";
    list.display();

    // Deleting element by pointer
    Node* ptr = list.getHead()->next;
    list.deleteNodeByPointer(ptr);
    std::cout << "List after deleting element pointed by ptr - next after the head: ";
    list.display();

    return 0;
}
