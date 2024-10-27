#include <iostream>
using namespace std;

class Stack
{
private:
    // declaring constant size as static so that  it can be used inside class
    static const int size = 100;
    // make an array to store stack elements
    int stack[size];
    // pointer to keep track of top most element in stack
    int top;

public:
    // constructor initializes stack at -1 index by default which means stack is empty
    Stack() : top(-1) {}

    void push(int value)
    {
        // check if stack is already full
        if (top >= size - 1)
        {
            cout << "Stack Overflow";
            return;
        }
        // add element at the top pointer, then move top pointer one place ahead
        stack[++top] = value;
    }
    int pop()
    {
        // check if stack is already empty
        if (top < 0)
        {
            cout << "Stack Empty";
            return -1;
        }
        // return the value at top pointer, then move top one place behind
        return stack[top--];
    }
    int peek()
    {
        // check if stack is already empty
        if (top < 0)
        {
            cout << "Stack empty";
            return -1;
        }
        // return the value at top pointer
        return stack[top];
    }
    void displayStack()
    {
        // check if stack is already empty
        if (top < 0)
        {
            cout << "Stack empty";
            return;
        }
        // print stack elements one by one
        cout << "Stack elements: ";
        for (int i = top; i >= 0; --i)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;
    // driver calls to check functionalities
    stack.displayStack();
    cout << endl;

    stack.push(10);
    stack.displayStack();

    stack.push(20);
    stack.displayStack();

    stack.push(30);
    stack.displayStack();

    stack.pop();
    stack.displayStack();

    // cout << stack.peek();
    // stack.displayStack();
}