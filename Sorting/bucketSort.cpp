#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<float> &bucket);
void bucketSort(float arr[], int num_of_buckets);

int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int num_of_buckets = sizeof(arr) / sizeof(arr[0]); // calculate length of float array

    // sizeof() returns the number of bytes of datatype passed to it. in this case float array is passed so it gives 24 as array contains 6 elements and float takes 4 bytes size so 6*4=24bytes

    // sizeof(arr[0]) gives bytes size of first element which is 4 so 24/4=6 which is length of float array
    bucketSort(arr, num_of_buckets);

    cout << "Bucket Sorted Array: \n";
    for (int i = 0; i < num_of_buckets; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void insertionSort(vector<float> &bucket)
{
    int n = bucket.size(); // calculate size of bucket
    for (int i = 1; i < n; i++)
    {
        float key = bucket[i]; // take first element as key to be inserted
        int j = i - 1;         // begin j behind i and move it in decrement
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key; // place key in correct place
    }
}

void bucketSort(float arr[], int num_of_buckets)
{
    vector<float> buckets[num_of_buckets]; // create buckets according to given number

    for (int i = 0; i < num_of_buckets; i++)
    {
        // for each element in input array, decide that in which bucket should it go, by calculating the bucket index
        int B_index = arr[i] * num_of_buckets;
        buckets[B_index].push_back(arr[i]);
    }

    for (int i = 0; i < num_of_buckets; i++)
    {
        if (!buckets[i].empty()) // sort only if bucket is not empty
        {
            // sort each bucket using insertion sort
            insertionSort(buckets[i]);
        }
    }
    int index = 0;
    // iterate over each bucket
    for (int i = 0; i < num_of_buckets; i++)
    {
        // iterate over each number in this i bucket
        for (float num : buckets[i])
        {
            // add this number to original array and then increment index to make sure that next element must be inserted ahead of it at next index
            arr[index++] = num;
        }
    }
}