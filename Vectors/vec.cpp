#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    // vec.push_back(4);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
}