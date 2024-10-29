// add, remove and display strings in a vector

#include <iostream>
#include <vector>

using namespace std;

void displayState(vector<string> &str);

vector<string> str;
int main()
{
    int option;
    string input;

    do
    {
        cout << "1. Add\n";
        cout << "2. Remove\n";
        cout << "3. View\n";
        cout << "Enter Choice: ";
        cin >> option;
        if (option == 1)
        {
            cout << "enter text: ";
            cin >> input;
            str.push_back(input);
            displayState(str);
        }
        else if (option == 2)
        {
            cout << "enter text to remove: ";
            cin >> input;
            for (int i = 0; i < str.size(); i++)
            {
                if (input == str[i])
                {
                    str.erase(str.begin() + i);
                }
                displayState(str);
            }
        }
        else if (option == 3)
        {
            for (int i = 0; i < str.size(); i++)
            {
                cout << str[i] << endl;
            }
        }

    } while (option != 4);
}

void displayState(vector<string> &str)
{
    cout << "Size: " << str.size() << endl;
    cout << "Capacity: " << str.capacity() << endl;
}