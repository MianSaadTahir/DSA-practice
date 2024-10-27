#include <iostream>
#include <limits>

using namespace std;

// Structure for elements in the priority queue
struct Item
{
    int value;
    int priority;
};

// Store the elements of the priority queue
Item prQueue[10000]; // Maximum queueSize of the priority queue
int queueSize = 0;   // Current queueSize initialized to 0

// Function to insert a new element into the priority queue
void enqueue(int value, int priority)
{
    if (queueSize >= 10000)
    {
        cout << "Priority queue is full!" << endl;
        return;
    }
    prQueue[queueSize].value = value;
    prQueue[queueSize].priority = priority;
    queueSize++;
}

// Function to check the top element (highest priority)
int peek()
{
    if (queueSize == 0)
    {
        cout << "Priority queue is empty!" << endl;
        return -1; // Indicate empty queue
    }

    int highestPriorityIndex = 0; // Set highest priority index to 0

    for (int i = 1; i < queueSize; i++)
    {
        // Update highestPriorityIndex if a higher priority element is found
        if (prQueue[i].priority > prQueue[highestPriorityIndex].priority ||
            (prQueue[i].priority == prQueue[highestPriorityIndex].priority &&
             prQueue[i].value > prQueue[highestPriorityIndex].value))
        {
            highestPriorityIndex = i;
        }
    }
    return highestPriorityIndex; // Return index of the highest priority element
}

// Function to remove the element with the highest priority
void dequeue()
{
    int index = peek(); // Get index of the highest priority element
    if (index == -1)
        return; // Check if the queue is empty

    // Shift elements to remove the one with the highest priority
    for (int i = index; i < queueSize - 1; i++)
    {
        prQueue[i] = prQueue[i + 1];
    }
    queueSize--; // Decrease the queueSize of the priority queue
}

// Driver Code
int main()
{
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);

    // Display the top element
    int ind = peek();
    if (ind != -1)
    {
        cout << "Top element: " << prQueue[ind].value << " (Priority: " << prQueue[ind].priority << ")" << endl;
    }

    dequeue(); // Remove top element

    // Display the new top element
    ind = peek();
    if (ind != -1)
    {
        cout << "New top element: " << prQueue[ind].value << " (Priority: " << prQueue[ind].priority << ")" << endl;
    }

    dequeue(); // Remove next top element

    // Display the new top element
    ind = peek();
    if (ind != -1)
    {
        cout << "Next top element: " << prQueue[ind].value << " (Priority: " << prQueue[ind].priority << ")" << endl;
    }

    return 0;
}
