#include <iostream>
#include <vector>
using namespace std;

void addRow(vector<vector<int>> &matrix, const vector<int> &row)
{
    matrix.push_back(row);
}

void addColumn(vector<vector<int>> &matrix, const vector<int> &col)
{
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        if (i < col.size())
        {
            matrix[i].push_back(col[i]);
        }
        else
        {
            matrix[i].push_back(0); // Fill with 0 if the column has fewer elements
        }
    }
}

void displayMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> transpose(const vector<vector<int>> &matrix)
{
    vector<vector<int>> result(matrix[0].size(), vector<int>(matrix.size()));
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[0].size(); ++j)
        {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> newRow = {10, 11, 12};
    addRow(matrix, newRow);

    vector<int> newCol = {13, 14, 15, 16};
    addColumn(matrix, newCol);

    cout << "Original Matrix:" << endl;
    displayMatrix(matrix);

    vector<vector<int>> transposedMatrix = transpose(matrix);

    cout << "Transposed Matrix:" << endl;
    displayMatrix(transposedMatrix);

    return 0;
}