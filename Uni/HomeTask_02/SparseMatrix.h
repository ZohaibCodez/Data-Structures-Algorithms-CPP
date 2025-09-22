#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H
#include <iostream>
#include "Matrix.h"
using namespace std;


class SparseMatrix
{
private:
    int non_zero;
    const int colms{3};
    int **S_Mat;

public:
    SparseMatrix(int non_zero = 0);
    SparseMatrix(const SparseMatrix& other); // Copy constructor
    ~SparseMatrix();
    
    SparseMatrix& operator=(const SparseMatrix& other); // Assignment operator
    
    void Read_SparseMatrix(const Matrix &mat);

    SparseMatrix AddSparseMatrix(SparseMatrix B);

    void display() const;

    int getNonZero() const;
};

#endif
