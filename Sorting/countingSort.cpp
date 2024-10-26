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
    int n = input.size(); // size of input vec
    if (n == 0)
    { // if empty input
        return;
    }
    int m = 0; // declare max value
    for (int i = 0; i < n; i++)
    {
        m = max(m, input[i]); // find max value in input and assign to m
    }
    vector<int> count(m + 1, 0); // count vec of 0 elements of  size max+1
    vector<int> output(n, 0);    // output vec of 0 elements of  size equal to length of input vec

    for (int i = 0; i < n; i++)
    { // counting occurences from input vec and incrementing relevant count index
        count[input[i]]++;
    }
    // calculate cummulative counts of count vector
    for (int i = 1; i <= m; i++)
    {
        count[i] += count[i - 1];
    }
    // populate output vector by traversing input vec in reverse direction for stable sort
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[input[i]] - 1] = input[i];
        count[input[i]]--; // decrease count from input element index to maintain stability
    }
    // copy output elements to original input vector for inplace sorting
    for (int i = 0; i < n; i++)
    {
        input[i] = output[i];
    }
}