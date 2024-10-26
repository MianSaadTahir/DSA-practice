// reverse , sort and remove duplicates from an integers vector

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> integers = {4, 2, 3, 2, 1, 5, 4, 3};
    reverse(integers.begin(), integers.end());

    sort(integers.begin(), integers.end());

    integers.erase(unique(integers.begin(), integers.end()), integers.end()); // unique from begin to end moves all unique elements to left leaving duplicates on right, and returns a index indicating that from ahead of that index are duplicates so .erase() function moves from the index returned by unique uptill the end and remove the duplicates

    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << endl;
    }
}