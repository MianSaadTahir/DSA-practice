// a class autogrowarray with different functionalities

#include <iostream>
using namespace std;

template <typename T>
class AutoGrowingArray
{
private:
    T *arr; // Pointer to the array where elements are stored
    int size;
    int capacity;

    // growing function to increase array capacity when full
    void grow()
    {
        capacity++;
        T *newArray = new T[capacity]; // Create a new, larger array of size = capacity
        for (int i = 0; i < size; i++)
        {
            newArray[i] = arr[i]; // Copy elements from the old array to the new one
        }
        delete[] arr;   // Delete the old array
        arr = newArray; // Point arr to the new array
    }

public:
    // Constructor initializing size and capacity, and creating an initial array
    AutoGrowingArray() : size(0), capacity(1)
    {
        arr = new T[capacity]; // Initialize array with the starting capacity
    }

    // Destructor to deallocate the dynamically allocated array
    ~AutoGrowingArray()
    {
        delete[] arr;
    }

    // Adds a new element at the end of the array
    void PushBack(T value)
    {
        if (size == capacity)
        {
            grow(); // Increase capacity if array is full
        }
        arr[size++] = value; // Place value at the end and increment size
    }

    // Operator to access elements (read-only) at a given index
    T operator[](int index) const
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        throw out_of_range("Index out of bounds"); // Error handling if index is invalid
    }

    // Operator to access and modify elements at a given index
    T &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        throw out_of_range("Index out of bounds"); // Error handling if index is invalid
    }

    // Overloaded << operator to display elements using cout
    friend ostream &operator<<(ostream &out, const AutoGrowingArray &other)
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
    AutoGrowingArray<int> arr;

    arr.PushBack(10);
    arr.PushBack(20);
    arr.PushBack(30);

    cout << arr << endl;
    cout << "Element at index 1: " << arr[1] << endl;

    arr[1] = 40; // Modify the element at index 1
    cout << "After modification: " << arr << endl;

    return 0;
}
