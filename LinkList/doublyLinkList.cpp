#include <iostream>
using namespace std;

// Node class representing each element in the doubly linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node

    // Constructor to initialize the node with a value
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

class DoublyLinkedList
{
private:
    Node *head; // head (1st) pointer in the list

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(NULL) {}

    // Destructor to free all nodes
    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Function to check if the list is empty
    bool isEmpty()
    {
        return head == NULL;
    }

    // Function to insert a new node at a given index
    void insertNode(int index, int x)
    {
        if (index < 0)
        {
            cout << "Invalid index";
            return;
        }

        Node *newNode = new Node(x);
        if (index == 0)
        { // Insert at head
            newNode->next = head;
            if (head != NULL)
            {
                head->prev = newNode; // Link the previous head to new node
            }
            head = newNode;
            return;
        }

        int i = 0;
        Node *temp = head;

        while (temp != NULL && i < index - 1)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        { // Index out of bounds
            cout << "Index out of bounds";
            delete newNode;
            return;
        }
        // Link the new node
        newNode->next = temp->next;
        newNode->prev = temp; // Link new node to the previous node
        if (temp->next != NULL)
        {
            temp->next->prev = newNode; // Link the next node back to the new node
        }
        temp->next = newNode; // Insert the new node
    }

    // Function to insert a new node at the head of the list
    void insertAtHead(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode; // Link the previous head to new node
        }

        head = newNode;
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int x)
    {
        Node *newNode = new Node(x);
        if (head == NULL)
        {
            head = newNode; // If the list is empty
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next; // Traverse to the last node
            }
            temp->next = newNode; // Link the last node to the new node
            newNode->prev = temp; // Link the new node back to the last node
        }
    }

    // Function to delete a node at the head
    bool deleteFromStart()
    {
        if (isEmpty())
        {
            return false; // Return false if list is empty
        }
        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL; // Update previous pointer of the new head
        }
        delete temp; // Delete the old head
        return true;
    }

    // Function to delete a node at the end
    bool deleteFromEnd()
    {
        if (isEmpty())
        {
            return false; // Return false if list is empty
        }
        if (head->next == NULL)
        { // Only one node in the list
            delete head;
            head = NULL;
            return true;
        }

        Node *temp = head;
        while (temp->next != NULL)
        { // Traverse to the last node
            temp = temp->next;
        }
        temp->prev->next = NULL; // Update the second last node's next to NULL
        delete temp;             // Delete the last node
        return true;
    }

    // Function to delete all nodes with given value x
    bool deleteNode(int x)
    {
        if (isEmpty())
        {
            return false; // Return false if list is empty
        }
        bool deleted = false;

        // Loop to remove nodes from the head if they have the value x
        while (head != NULL && head->data == x)
        {
            Node *temp = head;
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL; // Update previous pointer of new head
            }
            delete temp;
            deleted = true;
        }
        // Pointer to traverse the list
        Node *current = head;
        while (current != NULL)
        {
            if (current->data == x)
            {
                Node *temp = current;
                if (current->prev != NULL)
                {
                    current->prev->next = current->next; // Bypass the node to be deleted
                }
                if (current->next != NULL)
                {
                    current->next->prev = current->prev; // Link the next node back to previous
                }
                current = current->next; // Move to the next node after deletion
                delete temp;             // Delete the node
                deleted = true;
            }
            else
            {
                current = current->next; // Move to the next node if no deletion occurred
            }
        }
        return deleted;
    }

    // Function to search for node with given value x
    bool findNode(int x)
    {
        if (isEmpty())
        {
            return false; // Return false if list is empty
        }
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to display the list
    void displayList()
    {
        Node *temp = head; // Start at head
        while (temp != NULL)
        {                                  // Go until end of list
            cout << temp->data << " <-> "; // Print the data of temp node
            temp = temp->next;             // Move to next node
        }
        cout << "null\n"; // End of list
    }

    // Function to display the list in reverse order
    void displayReverse()
    {
        if (isEmpty())
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        // Move to the end of the list
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Traverse backward
        while (temp != NULL)
        {
            cout << temp->data << " <-> "; // Print the data of temp node
            temp = temp->prev;             // Move to previous node
        }
        cout << "null\n"; // End of list
    }
};

int main()
{
    DoublyLinkedList doublyList;
    doublyList.insertAtEnd(10);
    doublyList.insertAtEnd(20);
    doublyList.insertAtEnd(30);
    doublyList.displayList(); // 10 <-> 20 <-> 30 <-> null

    doublyList.insertAtHead(5);
    doublyList.displayList(); // 5 <-> 10 <-> 20 <-> 30 <-> null

    doublyList.deleteFromStart();
    doublyList.displayList(); // 10 <-> 20 <-> 30 <-> null

    doublyList.deleteFromEnd();
    doublyList.displayList(); // 10 <-> 20 <-> null

    doublyList.insertNode(1, 15);
    doublyList.displayList(); // 10 <-> 15 <-> 20 <-> null

    doublyList.deleteNode(15);
    doublyList.displayList(); // 10 <-> 20 <-> null

    doublyList.displayReverse(); // 20 <-> 10 <-> null

    return 0;
}
