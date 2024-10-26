#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr);

int main()
{
    vector<int> arr = {4, 2, 8, 9, 1};
    selectionSort(arr);

    cout << "Selection Sorted Array: \n";

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    { // if empty input
        return;
    }
    for (int i = 0; i < n - 1; i++) // last element will be sorted after first pass so no need to go to last element
    {
        int min_index = i;              // by default take each i as minimum value index
        for (int j = i + 1; j < n; j++) // start ahead of i
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j; // keep updating minimum index to the smallest element found at j
            }
        }
        if (min_index != i) // swap only if minimum index has been updated meaning that i is not the minimum index anymore. just to avoid unnecessary swaps
        {
            swap(arr[i], arr[min_index]);
        }
    }
}