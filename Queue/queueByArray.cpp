#include <iostream>
using namespace std;

class Queue
{
private:
    // declaring constant size as static so that  it can be used inside class
    static const int size = 50;
    // make an array to store queue elements
    int queue[size];
    // pointers to keep track of start and end of queue
    int front, rear;

public:
    // constructor initializes queue at -1 index by default which means queue is empty
    Queue() : front(-1), rear(-1) {}

    void enqueue(int value)
    {
        // check if queue is already full

        if (rear >= size - 1)
        {
            cout << "Queue overflow";
            return;
        }

        // by default for empty queue , front is at -1 so move it to 0
        if (front == -1)
        {
            front = 0;
        }

        // add element at the rear pointer, then move rear pointer one place ahead
        queue[++rear] = value;
    }
    int dequeue()
    {
        // check if queue is already empty

        if (front == -1 || front > rear)
        {
            cout << "Queue underflow";
            return -1;
        }

        // return the value at front pointer, then move front one place forward
        return queue[front++];
    }
    int peek()
    {
        // check if queue is already empty
        if (front == -1 || front > rear)
        {
            cout << "Queue underflow";
            return -1;
        }

        // return the value at front pointer
        return queue[front];
    }

    void display()
    {
        // check if queue is already empty
        if (front == -1 || front > rear)
        {
            cout << "Queue empty";
            return;
        }
        // print queue elements one by one
        for (int i = front; i <= rear; ++i)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // driver calls to check functionalities

    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    cout << queue.peek();
    cout << endl;

    queue.dequeue();
    queue.display();
    queue.enqueue(50);
    queue.display();
}