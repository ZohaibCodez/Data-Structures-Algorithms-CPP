#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

class Matrix
{
private:
    int **data;
    int rows, cols;

public:
    Matrix(int numRows = 0, int numCols = 0);
    ~Matrix();

    void setValue(int row, int col, int value);
    int getValue(int row, int col) const;
    void display() const;

    int *operator[](int row);

    int getRows() const;
    int getCols() const;
};

#endif
