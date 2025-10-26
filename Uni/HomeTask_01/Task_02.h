#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>

using namespace std;

class Array2D
{
private:
    int rows;
    int cols;
    int *data; // linear 1D array stored in column-major order

public:
    // constructor
    Array2D(int r, int c)
    {
        rows = r;
        cols = c;
        data = new int[rows * cols];
        for (int i = 0; i < rows * cols; i++)
        {
            *(data + i) = 0;
        }
    }
    // destructor
    ~Array2D()
    {
        delete[] data;
    }
    // copy constructor
    Array2D(const Array2D &other)
    {
        rows = other.rows;
        cols = other.cols;
        data = new int[rows * cols];
        for (int i = 0; i < rows * cols; i++)
        {
            *(data + i) = *(other.data + i);
        }
    }

    int getIndexValue(int i, int j) const
    {
        int index = i + j * rows;
        return data[index];
    }
    void setIndexValue(int i, int j, int val)
    {
        int index = i + j * rows;
        *(data + index) = val;
    }
    void printArray() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int index = i + j * rows;
                cout << *(data + index) << " ";
            }
            cout << endl;
        }
    }
    int addressOfIndex(int i, int j, int startIndex = 0) const
    {
        int indexAddress = startIndex + (j * rows + i);
        return indexAddress;
    }

    Array2D operator+(const Array2D &other) const
    {
        Array2D result(rows, cols);
        for (int i = 0; i < rows * cols; i++)
        {
            *(result.data + i) = *(other.data + i) + *(this->data + i);
        }
        return result;
    }

    void printSubArray(int r1, int r2, int c1, int c2) const
    {
        for (int i = r1; i < r2; i++)
        {
            for (int j = c1; j < c2; j++)
            {
                int index = j * rows + i;
                cout << *(data + index) << " ";
            }
            cout << endl;
        }
    }
    void clear(int m1, int m2, int n1, int n2)
    {
        for (int i = m1; i < m2; i++)
        {
            for (int j = n1; j < n2; j++)
            {
                int index = j * rows + i;
                *(data + index) = 0;
            }
            cout << endl;
        }
    }
};
#endif