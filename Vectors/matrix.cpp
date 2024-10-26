#include <iostream>
#include <vector>
using namespace std;

void addRow(vector<vector<int>> &matrix, vector<int> &row)
{ // add row to the end of matrix just below last row
    matrix.push_back(row);
}

void addCol(vector<vector<int>> &matrix, vector<int> &col)
{
    // iterate over each row
    for (int i = 0; i < matrix.size(); i++)
    { // if col vector is not empty
        if (i < col.size())
        { // add the i index element of col vector to the last position of i row
            matrix[i].push_back(col[i]);
        }
        else
        { // if col vector is empty, then add 0 to the i index of row just to maintain symmetry of matrix not leave any empty space
            matrix[i].push_back(0);
        }
    }
}

void displayMatrix(vector<vector<int>> &matrix)
{
    // iterate over each row in matrix
    for (auto &row : matrix)
    {
        // iterate over each element in the i row
        for (auto element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    // displayMatrix(matrix);
    vector<int> row = {9, 9, 9};
    addRow(matrix, row);
    // displayMatrix(matrix);
    vector<int> col = {5, 5, 5};
    addCol(matrix, col);
    displayMatrix(matrix);
}