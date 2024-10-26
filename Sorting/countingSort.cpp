#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int> &input);

int main()
{
    vector<int> input = {4, 2, 8, 9, 1};
    countingSort(input);

    cout << "Counting Sorted Array: \n";

    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    return 0;
}

void countingSort(vector<int> &input)
{
    int n = input.size(); // size of input vector
    if (n == 0)
    { // if empty input
        return;
    }
    int maxValue = input[0]; // initialize first value in input vector as maxValue value by default
    for (int i = 0; i < n; i++)
    {
        // find maxValue value in input vector and assign to maxValue
        if (input[i] > maxValue)
        {
            maxValue = input[i];
        }
    }
    vector<int> count(maxValue + 1, 0); // count vector of 0 elements of  size maxValue+1
    vector<int> output(n, 0);           // output vector of 0 elements of  size equal to length of input vec

    for (int i = 0; i < n; i++)
    { // counting occurences of each element in input vector and incrementing relevant count index
        count[input[i]]++;
    }
    // calculate cummulative counts of count vector
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    // populate output vector by traversing input vector in reverse direction for stable sort
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[input[i]] - 1] = input[i];
        count[input[i]]--; // decrement count to maintain stability and make sure that duplicates are placed in order
    }
    // copy output elements to original input vector for inplace sorting
    for (int i = 0; i < n; i++)
    {
        input[i] = output[i];
    }
}