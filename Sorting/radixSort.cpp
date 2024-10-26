#include <iostream>
#include <vector>
using namespace std;

void radixSort(vector<int> &input);
void countingSort(vector<int> &input, int exp);

int main()
{
    vector<int> input = {4, 2, 8, 9, 1};
    radixSort(input);

    cout << "Radix Sorted Array: \n";
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    return 0;
}

void radixSort(vector<int> &input)
{
    // by default take first value in input vector as max value
    int maxValue = input[0];
    for (int i = 0; i < input.size(); i++)
    {
        // find max element and assign to maxValue
        if (input[i] > maxValue)
        {
            maxValue = input[i];
        }
    }
    // apply counting sort on each digit by increasing exponent in each iteration uptil all digits of maxValue are iterated
    for (int exp = 1; maxValue / exp > 0; exp *= 10)
    {
        countingSort(input, exp);
    }
}

void countingSort(vector<int> &input, int exp)
{
    int n = input.size();
    if (n == 0)
    { // if empty input
        return;
    }
    vector<int> output(n, 0);
    vector<int> count(10, 0); // count array of digits 0-9

    // counting occurrences of each element in input vector and incrementing relevant count index
    for (int i = 0; i < n; i++)
    {
        // calculate index according to the exponent digit
        int index = (input[i] / exp) % 10;
        count[index]++;
    }
    // calculate cumulative counts of count vector
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    // populate output vector by traversing input vector in reverse direction for stable sort
    for (int i = n - 1; i >= 0; i--)
    {
        int index = (input[i] / exp) % 10;
        output[count[index] - 1] = input[i];
        count[index]--; // decrement count to maintain stability and make sure duplicates are placed in order
    }
    // copy output elements to original input vector for inplace sorting
    for (int i = 0; i < n; i++)
    {
        input[i] = output[i];
    }
}