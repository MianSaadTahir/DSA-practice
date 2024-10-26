#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &arr, int low, int high);
int partition(vector<int> &arr, int low, int high);

int main()
{
    vector<int> arr = {4, 2, 8, 9, 1};
    quickSort(arr, 0, arr.size() - 1);

    cout << "Quick Sorted Array: \n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void quickSort(vector<int> &arr, int low, int high)
{
    int n = arr.size();
    if (n == 0)
    { // if empty input
        return;
    }
    if (low < high) // keep dividing until sub arrays have one element
    {
        int pivot = partition(arr, low, high); // find pivot to divide sub arrays around it

        // recursively sort left and right subarrays
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];           // 3rd case for quick select in which we choose last element as pivot by default
    int i = low - 1;                 // start i pointer before beginning of array
    for (int j = low; j < high; j++) // start j at beginning of array
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // move pivot to one place ahead of i and return that index (i+1)
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
