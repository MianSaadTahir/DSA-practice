// search for a specific integer

#include <iostream>
#include <vector>
using namespace std;

vector<int> integers = {2, 3, 7, 6, 1, 8};

int main()
{
    int input;
    cout << "Enter integer to search: ";
    cin >> input;
    bool found = false;
    for (int i = 0; i < integers.size(); i++)
    {
        if (input == integers[i])
        {
            cout << i;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Element not present";
    }
}