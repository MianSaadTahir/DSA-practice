#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr);

int main()
{
    vector<int> arr = {4, 2, 8, 9, 1};
    bubbleSort(arr);

    cout << "Bubble Sorted Array: \n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    { // if empty input
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) // n-i-1 because we need to go upto 2nd last element as last element after first pass will already be sorted so no need to compare that
        // last i elements already sorted after each pass
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) // if no swaps in this pass,  array is already sorted
        {
            break; // terminate loop to save time
        }
    }
}