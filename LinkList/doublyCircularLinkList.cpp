#include <iostream>
using namespace std;

// Node class representing each element in the doubly circular linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node

    // Constructor to initialize the node with a value
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

class DoublyCircularLinkedList
{
private:
    Node *head; // head (1st) pointer in the list

public:
    // Constructor to initialize an empty list
    DoublyCircularLinkedList() : head(NULL) {}

    // Destructor to free all nodes
    ~DoublyCircularLinkedList()
    {
        if (head == NULL)
            return; // Check if the list is empty

        Node *current = head;
        Node *temp;

        // Loop to delete all nodes in the circular list
        do
        {
            temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
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
            cout << "Invalid index\n";
            return;
        }

        Node *newNode = new Node(x);
        if (index == 0)
        {                     // Insert at head
            if (head == NULL) // If the list is empty
            {
                head = newNode;
                newNode->next = head;
                newNode->prev = head;
            }
            else
            {
                newNode->next = head;
                newNode->prev = head->prev;
                head->prev->next = newNode;
                head->prev = newNode;
                head = newNode;
            }
            return;
        }

        int i = 0;
        Node *temp = head;

        while (temp != NULL && i < index - 1)
        {
            temp = temp->next;
            i++;
            if (temp == head)
                break; // Stop if we looped around
        }
        // Link the new node
        newNode->next = temp->next;
        newNode->prev = temp;       // Link new node to the previous node
        temp->next->prev = newNode; // Link the next node back to the new node
        temp->next = newNode;       // Insert the new node
    }

    // Function to insert a new node at the head of the list
    void insertAtHead(int x)
    {
        insertNode(0, x);
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int x)
    {
        if (head == NULL)
        {
            insertAtHead(x);
        }
        else
        {
            Node *newNode = new Node(x);
            newNode->next = head;       // Point to head
            newNode->prev = head->prev; // Previous to last node
            head->prev->next = newNode; // Link last node to new node
            head->prev = newNode;       // Link new node to head
        }
    }

    // Function to delete a node at the head
    bool deleteFromStart()
    {
        if (isEmpty())
        {
            return false; // Return false if list is empty
        }
        if (head->next == head) // Only one node in the list
        {
            delete head;
            head = NULL;
            return true;
        }

        Node *temp = head;
        head->prev->next = head->next; // Link last node to the next of head
        head->next->prev = head->prev; // Link next node back to the last node
        head = head->next;             // Move head to the next node
        delete temp;                   // Delete the old head
        return true;
    }

    // Function to delete a node at the end
    bool deleteFromEnd()
    {
        if (isEmpty())
        {
            return false; // Return false if list is empty
        }
        if (head->next == head) // Only one node in the list
        {
            delete head;
            head = NULL;
            return true;
        }

        Node *temp = head->prev; // Last node
        temp->prev->next = head; // Link second last to head
        head->prev = temp->prev; // Link head back to second last
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
            if (head->next == head) // Only one node in the list
            {
                delete head;
                head = NULL;
                return true;
            }
            head->prev->next = head->next; // Link last node to the next of head
            head->next->prev = head->prev; // Link next node back to the last node
            head = head->next;             // Move head to the next node
            delete temp;
            deleted = true;
        }
        // Pointer to traverse the list
        Node *current = head;
        while (current != head)
        {
            if (current->data == x)
            {
                Node *temp = current;
                current->prev->next = current->next; // Bypass the node to be deleted
                current->next->prev = current->prev; // Link the next node back to previous
                current = current->next;             // Move to the next node after deletion
                delete temp;                         // Delete the node
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
        do
        {
            if (temp->data == x)
            {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Function to display the list
    void displayList()
    {
        if (isEmpty())
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head; // Start at head
        do
        {                                  // Go until we loop back to head
            cout << temp->data << " <-> "; // Print the data of temp node
            temp = temp->next;             // Move to next node
        } while (temp != head);
        cout << "...\n"; // Indicate circular nature
    }

    // Function to display the list in reverse order
    void displayReverse()
    {
        if (isEmpty())
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head->prev; // Start at the last node
        do
        {                                  // Go until we loop back to head
            cout << temp->data << " <-> "; // Print the data of temp node
            temp = temp->prev;             // Move to previous node
        } while (temp != head->prev);
        cout << "...\n"; // Indicate circular nature
    }
};

int main()
{
    DoublyCircularLinkedList circularList;
    circularList.insertAtEnd(10);
    circularList.insertAtEnd(20);
    circularList.insertAtEnd(30);
    circularList.displayList(); // 10 <-> 20 <-> 30 <-> ...

    circularList.insertAtHead(5);
    circularList.displayList(); // 5 <-> 10 <-> 20 <-> 30 <-> ...

    circularList.deleteFromStart();
    circularList.displayList(); // 10 <-> 20 <-> 30 <-> ...

    circularList.deleteFromEnd();
    circularList.displayList(); // 10 <-> 20 <-> ...

    circularList.insertNode(1, 15);
    circularList.displayList(); // 10 <-> 15 <-> 20 <-> ...

    circularList.deleteNode(15);
    circularList.displayList(); // 10 <-> 20 <-> ...

    circularList.displayReverse(); // 20 <-> 10 <-> ...

    return 0;
}
