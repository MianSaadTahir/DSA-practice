// implemented circular queue

#include <iostream>
using namespace std;

class CircularQueue
{
private:
    // Declaring a constant size for the circular queue
    static const int size = 50;
    // Array to store queue elements
    int queue[size];
    // Pointers to keep track of the front and rear of the queue
    int front, rear;

public:
    // Constructor initializes the queue as empty
    CircularQueue() : front(-1), rear(-1) {}

    // Function to add an element to the queue
    void enqueue(int value)
    {
        // Check if the queue is already full using circular condition
        if ((rear + 1) % size == front)
        {
            cout << "Queue overflow" << endl;
            return;
        }

        // If the queue is empty, set front to 0
        if (front == -1)
        {
            front = 0;
        }

        // Update the rear pointer to add the new value
        rear = (rear + 1) % size;
        queue[rear] = value; // Add the new value at the rear
    }

    // Function to remove an element from the queue
    int dequeue()
    {
        // Check if the queue is already empty
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        // Store the value at the front to return later
        int value = queue[front];

        // Check if the queue becomes empty after removal
        if (front == rear)
        {
            front = rear = -1; // Reset the queue
        }
        else
        {
            // Move front pointer to the next position in circular manner
            front = (front + 1) % size;
        }
        return value; // Return the dequeued value
    }

    // Function to get the front element of the queue without removing it
    int peek()
    {
        // Check if the queue is empty
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        // Return the value at the front pointer
        return queue[front];
    }

    // Function to display all elements in the queue
    void display()
    {
        // Check if the queue is empty
        if (front == -1)
        {
            cout << "Queue empty" << endl;
            return;
        }
        // Print queue elements one by one in circular manner
        int i = front;
        while (true)
        {
            cout << queue[i] << " "; // Print current element
            if (i == rear)
            {
                break; // Exit if we've reached the rear
            }
            i = (i + 1) % size; // Move to the next element
        }

        cout << endl; // New line after printing all elements
    }
};

int main()
{
    // Driver code to test the functionalities of CircularQueue
    CircularQueue queue;

    // Enqueue elements into the queue
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display current queue elements
    queue.display(); // Should display 10 20 30

    // Peek at the front element
    cout << "Peek: " << queue.peek() << endl; // Should display 10

    // Dequeue an element
    queue.dequeue();
    queue.display(); // Should display 20 30

    // Enqueue more elements
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60); // Queue should still accept new elements

    // Display updated queue elements
    queue.display(); // Should display 20 30 40 50 60

    // Dequeue two elements
    queue.dequeue(); // Remove 20
    queue.dequeue(); // Remove 30

    // Display final queue state
    queue.display(); // Should display 40 50 60

    return 0; // End of the program
}
