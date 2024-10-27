#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueue
{
private:
    queue<int> q1; // main queue for holding elements like stack
    queue<int> q2; // temporary queue for reversing q1 elements
public:
    void push(int value)
    {
        // enqueue new elements to q1
        q2.push(value);

        // untill q1 is not empty
        while (!q1.empty())
        {
            // push every front element of q1 to q2
            q2.push(q1.front());
            // pop the front element of q1 and move the front pointer to next element of q1 as it has been moved to q2
            q1.pop();
        }
        // when q1 is empty and q2 is full which is like a stack, swap their names so that q1 which is main queue, it behaves like a stack
        swap(q1, q2);
    }
    int pop()
    {
        if (q1.empty())
        {
            cout << "Stack empty\n";
            return -1; // Indicate the stack is empty
        }

        // Get the front element (top of stack)
        int topValue = q1.front();
        q1.pop();        // Pop it from q1
        return topValue; // Return the top value
    }

    int peek()
    {
        // check if q1 is empty
        if (q1.empty())
        {
            cout << "Stack empty";
            return -1;
        }

        // the front of q1 will be the top element like a stack
        return q1.front();
    }

    void display()
    {
        // check if q1 is empty
        if (q1.empty())
        {
            cout << "Stack empty";
            return;
        }
        // copy all q1 elements to a temp queue for displayin purpose
        queue<int> temp = q1;
        cout << "Stack Elements: \n";
        while (!temp.empty())
        {
            // keep showing the front element of q1
            cout << temp.front() << " ";
            // keep poping front element of q1 to keep moving the front pointer ahead
            temp.pop();
        }
        cout << endl;
    }
};
int main()
{
    StackUsingQueue stack;

    stack.display(); // Display initially

    stack.push(10);
    stack.display();

    stack.push(20);
    stack.display();

    stack.push(30);
    stack.display();

    cout << "Popped: " << stack.pop() << endl; // Should pop 30
    stack.display();                           // Display after pop

    cout << "Top element: " << stack.peek() << endl; // Should show 20
    stack.display();                                 // Display current stack

    return 0;
}
