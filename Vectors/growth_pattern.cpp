// insert 100 integer into vector and observe growth pattern

#include <iostream>
#include <vector>
using namespace std;

void displayState(vector<int> &integers);

int main()
{
    vector<int> integers;
    for (int i = 0; i < 100; i++)
    {
        integers.push_back(i);
        displayState(integers);
    }
}

void displayState(vector<int> &integers)
{
    cout << "Size: " << integers.size() << endl;
    cout << "Capacity: " << integers.capacity() << endl;
    cout << endl;
}