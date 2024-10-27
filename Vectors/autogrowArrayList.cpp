// a class ArrayList with different functionalities

#include <iostream>
using namespace std;

template <typename T>
class ArrayList
{
private:
    T *arr; // Pointer to the array where elements are stored
    int size, capacity;

    // resize function to increase array capacity when full
    void resize()
    {
        // resize by 1.5 factor and convert it back to integer
        capacity = static_cast<int>(capacity * 1.5);
        T *newArr = new T[capacity];
        // Create a new, larger array of size = capacity
        for (int i = 0; i < size; i++)
        { // Copy elements from the old array to the new one
            newArr[i] = arr[i];
        }
        // Delete the old array
        delete[] arr;
        // Point arr to the new array
        arr = newArr;
    }

public:
    // Constructor initializing size and capacity, and creating an initial array
    ArrayList() : size(0), capacity(1)
    {
        // Initialize array with the starting capacity
        arr = new T[capacity];
    }
    ~ArrayList()
    {
        // Destructor to deallocate the dynamically allocated array
        delete[] arr;
    }
    void PushBack(T value)
    {
        // Adds a new element at the end of the array
        if (size == capacity)
        {
            // Increase capacity if array is full
            resize();
        }
        // Place value at the end and increment size
        arr[size++] = value;
    }
    // Operator to access elements (read-only) at a given index
    T operator[](int index) const
    {
        if (index < 0 || index >= size)
        { // Error handling if index is invalid
            throw out_of_range("Index out of bounds");
        }
        return arr[index];
    }
    // Operator to access and modify elements at a given index
    T &operator[](int index)
    {
        if (index < 0 || index >= size)
        { // Error handling if index is invalid
            throw out_of_range("Index out of bounds");
        }
        return arr[index];
    }
    // Overloaded << operator to display elements using cout
    friend ostream &operator<<(ostream &out, const ArrayList &other)
    {
        for (int i = 0; i < other.size; i++)
        {
            out << other.arr[i] << " ";
        }
        return out;
    }
};

int main()
{
    ArrayList<int> arrList;

    arrList.PushBack(10);
    arrList.PushBack(20);
    arrList.PushBack(30);
    cout << arrList << endl;

    arrList[2] = 99;
    cout << arrList;
}