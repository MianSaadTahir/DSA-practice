#include <iostream>
using namespace std;

// Node class representing each element in the linked list

class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node

    // Constructor to initialize the node with a value

    Node(int x) : data(x), next(NULL) {}
};

class LinkedList
{

private:
    Node *head; // head (1st) pointer in list

public:
    // Constructor to initialize an empty list
    LinkedList() : head(NULL) {}

    // Destructor to free all nodes
    ~LinkedList()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
    // Function to check if the list is empty, used in deleting nodes functions
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
        if (index == 0) // if index = 0 , insert new node at head
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        int i = 0;         // current index
        Node *temp = head; // start from head

        while (temp != NULL && i < index - 1)
        { // traverse to the node before insertion point
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        { // index too large that list was finished before finding right place
            cout << "index out of bounds";
            delete newNode;
            return;
        }
        // next pointer of newNode gets current value
        newNode->next = temp->next;
        // place newNode at the current place
        temp->next = newNode;
    }

    // Function to insert a new node at the head of the list
    void insertAtHead(int x)
    {
        Node *newNode = new Node(x); // Create a new node
        newNode->next = head;        // Point new node to the current head
        head = newNode;              // Update head to the new node
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int x)
    {
        Node *newNode = new Node(x);
        if (head == NULL) // If list is empty, insert new node at head
        {
            head = newNode;
        }
        else
        {
            Node *temp = head; // Start from the head
            while (temp->next != NULL)
            {
                // Traverse to the last node
                temp = temp->next;
            }
            // Link the last node to the new node
            temp->next = newNode;
        }
    }
    // Function to delete a  node at a head
    bool deleteFromStart()
    {
        if (isEmpty())
        {
            return false; // Return false if list is empty
        }
        Node *temp = head; // Store the head node in temp to delete
        head = head->next; // Update head to the next node
        delete temp;       // delete temp which is the previous head
        return true;
    }

    // Function to delete a  node at a end
    bool deleteFromEnd()
    {
        if (isEmpty())
        {
            return false; // Return false if list is empty
        }
        if (head->next == NULL) // only one node in list
        {
            delete head; // delete the only node
            head = NULL;
            return true;
        }

        Node *temp = head;
        while (temp->next->next != NULL) // traverse upto 2nd last element
        {
            temp = temp->next;
        }
        delete temp->next; // Delete the last node
        temp->next = NULL; // update end of the list
        return true;
    }

    // Function to delete all nodes with given value x
    bool deleteNode(int x)
    {
        if (isEmpty())
        {
            return false; // Return false if list is empty
        }
        bool deleted = false; // check if any node was deleted

        // Loop to remove nodes from the head if they have the value x
        while (head != NULL && head->data == x)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            deleted = true;
        }
        // Pointer to traverse the list starting from the new head
        Node *current = head;
        // Traverse the list to find and delete nodes with the value x
        while (current != NULL && current->next != NULL)
        {
            if (current->next->data == x)
            {
                Node *temp = current->next;          // Store the node to be deleted
                current->next = current->next->next; // Bypass the node to be deleted
                delete temp;                         // delete that node
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
    void displayList()
    {
        Node *temp = head;   // start at head
        while (temp != NULL) // go until end of list
        {
            cout << temp->data << "->"; // print the data of temp node
            temp = temp->next;          // update temp node to move to next node
        }
        cout << "null \n"; // end of list
    }
};

int main()
{
    LinkedList list;
    cout << endl;
    list.insertAtHead(1);
    list.displayList();

    list.insertAtEnd(2);
    list.displayList();

    list.insertAtEnd(3);
    list.displayList();

    list.insertAtEnd(4);
    list.displayList();

    list.insertNode(2, 9);
    list.displayList();

    list.deleteFromStart();
    list.displayList();

    list.deleteFromEnd();
    list.displayList();

    list.deleteNode(3);
    list.displayList();

    cout << (list.findNode(2) ? "found" : "not found") << endl;

    return 0;
}
