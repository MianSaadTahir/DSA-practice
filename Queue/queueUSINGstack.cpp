#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStack
{
private:
    stack<int> s1; // for enqueue
    stack<int> s2; // for dequeue

public:
    void enqueue(int value)
    {
        s1.push(value);
    }

    int dequeue()
    {
        if (s2.empty())
        {
            // if s1 is not empty, copy its elements to s2
            while (!s1.empty())
            {
                s2.push(s1.top());
                // keep removing the copied elements from s1 so that top pointer keeps decrementing
                s1.pop();
            }
        }
        // check if queue is still empty
        if (s2.empty())
        {
            cout << "Queue empty";
            return -1;
        }
        // return  top element from s2
        int value = s2.top();
        // then keep moving top pointer behind
        s2.pop();
        return value;
    }
    int peek()
    {
        if (s2.empty())
        {
            // if s1 is not empty, copy its elements to s2
            while (!s1.empty())
            {
                s2.push(s1.top());
                // keep removing the copied elements from s1 so that top pointer keeps decrementing
                s1.pop();
            }
        }
        // check if queue is still empty
        if (s2.empty())
        {
            cout << "Queue empty";
            return -1;
        }
        // return top element from s2
        return s2.top();
    }
    void display()
    {
        stack<int> temp = s2;

        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }

        temp = s1;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    QueueUsingStack queue;

    queue.display();

    queue.enqueue(10);
    queue.display();

    queue.enqueue(20);
    queue.display();

    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.display();

    queue.enqueue(50);
    queue.display();

    queue.dequeue();
    queue.display();
}