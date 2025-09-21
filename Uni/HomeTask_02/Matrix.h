/**
 * @file Matrix.h
 * @brief Header file for Matrix class - represents a 2D matrix using dynamic memory allocation
 * 
 * This class implements a basic 2D matrix with the following features:
 * - Dynamic memory allocation for 2D array
 * - Constructor with default parameters (0x0 matrix by default)
 * - Destructor for proper memory cleanup
 * - Set/get individual matrix elements with bounds checking
 * - Display matrix in formatted output
 * - Array subscript operator for easy element access
 * - Getter methods for matrix dimensions
 * 
 * @author Zohaib Khan
 * @course Data Structures and Algorithms
 */

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

class Matrix
{
private:
    int **data;     // Pointer to pointer - represents 2D array (rows of columns)
    int rows, cols; // Dimensions of the matrix (number of rows and columns)

public:
    // Constructor: Creates a matrix with specified dimensions
    // Default parameters: 0 rows, 0 columns (empty matrix)
    Matrix(int numRows = 0, int numCols = 0);
    
    // Destructor: Frees all allocated memory to prevent memory leaks
    ~Matrix();

    // Set value at specific position (row, col) with bounds checking
    void setValue(int row, int col, int value);
    
    // Get value at specific position (row, col) with bounds checking
    // Returns 0 if position is out of bounds
    int getValue(int row, int col) const;
    
    // Display the entire matrix in a formatted way
    void display() const;

    // Array subscript operator: allows matrix[row] access
    // Returns pointer to the row, enabling matrix[row][col] syntax
    int *operator[](int row);

    // Getter methods for matrix dimensions
    int getRows() const;  // Returns number of rows
    int getCols() const;  // Returns number of columns
};

#endif
