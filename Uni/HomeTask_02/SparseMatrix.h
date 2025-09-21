/**
 * @file SparseMatrix.h
 * @brief Header file for SparseMatrix class - efficient storage for matrices with many zeros
 * 
 * A sparse matrix is a matrix in which most of the elements are zero.
 * Instead of storing all elements, we only store non-zero elements along with their positions.
 * This saves memory when dealing with large matrices that have many zeros.
 * 
 * Storage format:
 * Each non-zero element is stored as a row with 3 columns:
 * - Column 0: Row index in original matrix
 * - Column 1: Column index in original matrix  
 * - Column 2: Value of the element
 * 
 * Example: Matrix [0 3 0; 0 0 0; 1 0 0] becomes:
 * Row Col Value
 * 0   1   3
 * 2   0   1
 * 
 * @author Zohaib Khan
 * @course Data Structures and Algorithms
 */

#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H
#include <iostream>
#include "Matrix.h"  // Include Matrix class for conversion
using namespace std;

class SparseMatrix
{
private:
    int non_zero;           // Number of non-zero elements in the matrix
    const int colms{3};     // Fixed number of columns: [row, col, value]
    int **S_Mat;           // 2D array to store sparse matrix data

public:
    // Constructor: Creates a sparse matrix with specified number of non-zero elements
    // Default parameter: 0 non-zero elements (empty sparse matrix)
    SparseMatrix(int non_zero = 0);
    
    // Destructor: Frees all allocated memory
    ~SparseMatrix();
    
    // Convert a regular Matrix to sparse format
    // Counts non-zero elements and stores them with their positions
    void Read_SparseMatrix(const Matrix &mat);

    // Add two sparse matrices and return the result
    // Uses merge algorithm similar to merging two sorted arrays
    SparseMatrix AddSparseMatrix(SparseMatrix B);

    // Display the sparse matrix in a formatted way
    // Shows each non-zero element with its position and value
    void display() const;

    // Get the number of non-zero elements
    int getNonZero() const;
};

#endif
