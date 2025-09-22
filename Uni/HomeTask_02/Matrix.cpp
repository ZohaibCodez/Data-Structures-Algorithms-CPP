#include "Matrix.h"

Matrix::Matrix(int numRows, int numCols)
{
    rows = numRows;
    cols = numCols;
    if (rows > 0 && cols > 0)
    {
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
    }
    else
    {
        data = nullptr;
    }
}

Matrix::~Matrix()
{
    if (data != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
}

void Matrix::setValue(int row, int col, int value)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        data[row][col] = value;
    }
}

int Matrix::getValue(int row, int col) const
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        return data[row][col];
    }
    return 0;
}

void Matrix::display() const
{
    if (data == nullptr || rows == 0 || cols == 0)
    {
        cout << "Empty matrix" << endl;
        return;
    }
    cout << "Matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

// Overload [] operator
int *Matrix::operator[](int row)
{
    if (row >= 0 && row < rows)
    {
        return data[row];
    }
    return nullptr;
}

int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }
