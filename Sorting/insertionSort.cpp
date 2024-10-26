#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr);

int main()
{
    vector<int> arr = {4, 2, 8, 9, 1};
    insertionSort(arr);

    cout << "Insertion Sorted Array: \n";

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    if (n == 0)
    { // if empty input
        return;
    }
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // element to be inserted, pick i in every iteration
        int j = i - 1;    // start behind i

        while (j >= 0 && arr[j] > key) // j>=0 means j doesnot go out of starting bounds of array and arr[j]>key means as long as values behind key are greater than key
        {
            arr[j + 1] = arr[j]; // keep shifting values before key one place forward
            j--;                 // keep moving j pointer backward uptill start of array
        }
        arr[j + 1] = key; // place key just ahead where j condition failed
    }
}