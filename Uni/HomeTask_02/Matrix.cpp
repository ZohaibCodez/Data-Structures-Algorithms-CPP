/**
 * @file Matrix.cpp
 * @brief Implementation file for Matrix class
 * 
 * This file contains the implementation of all methods declared in Matrix.h
 * It demonstrates proper dynamic memory management for 2D arrays in C++
 */

#include "Matrix.h"

/**
 * @brief Constructor - Creates a new matrix with specified dimensions
 * @param numRows Number of rows in the matrix
 * @param numCols Number of columns in the matrix
 * 
 * Memory allocation process:
 * 1. Allocate array of pointers (one for each row)
 * 2. For each row, allocate array of integers (columns)
 * 3. Initialize all elements to 0
 */
Matrix::Matrix(int numRows, int numCols)
{
    // Store dimensions
    rows = numRows;
    cols = numCols;

    // Step 1: Allocate memory for array of row pointers
    data = new int *[rows];
    
    // Step 2: For each row, allocate memory for columns
    for (int i = 0; i < rows; i++)
    {
        data[i] = new int[cols];
        
        // Step 3: Initialize all elements to 0
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = 0;
        }
    }
}

/**
 * @brief Destructor - Frees all allocated memory
 * 
 * Memory deallocation process (reverse of allocation):
 * 1. Delete each row's memory (array of integers)
 * 2. Delete the array of row pointers
 * 
 * This prevents memory leaks when the object goes out of scope
 */
Matrix::~Matrix()
{
    // Step 1: Delete each row's memory
    for (int i = 0; i < rows; i++)
    {
        delete[] data[i];  // Delete array of integers for row i
    }
    
    // Step 2: Delete the array of row pointers
    delete[] data;
}

/**
 * @brief Set value at specific position with bounds checking
 * @param row Row index (0-based)
 * @param col Column index (0-based)
 * @param value Value to store
 * 
 * Only sets the value if the position is within valid bounds
 * Silently ignores invalid positions (no error message)
 */
void Matrix::setValue(int row, int col, int value)
{
    // Check if position is within valid bounds
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        data[row][col] = value;
    }
    // If position is invalid, do nothing (silent failure)
}

/**
 * @brief Get value at specific position with bounds checking
 * @param row Row index (0-based)
 * @param col Column index (0-based)
 * @return Value at position (row, col) or 0 if position is invalid
 */
int Matrix::getValue(int row, int col) const
{
    // Check if position is within valid bounds
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        return data[row][col];
    }
    
    // Return 0 for invalid positions
    return 0;
}

/**
 * @brief Display the matrix in a formatted way
 * 
 * Output format:
 * Matrix (rows x cols):
 * [row 0 elements]
 * [row 1 elements]
 * ...
 * [empty line]
 */
void Matrix::display() const
{
    // Print matrix header with dimensions
    cout << "Matrix (" << rows << "x" << cols << "):" << endl;
    
    // Print each row
    for (int i = 0; i < rows; i++)
    {
        // Print each element in the row
        for (int j = 0; j < cols; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;  // New line after each row
    }
    cout << endl;  // Empty line after matrix
}

/**
 * @brief Array subscript operator - enables matrix[row] syntax
 * @param row Row index (0-based)
 * @return Pointer to the specified row
 * 
 * This allows for convenient access like: matrix[row][col]
 * Note: No bounds checking is performed here for performance
 */
int *Matrix::operator[](int row)
{
    return data[row];
}

/**
 * @brief Get number of rows in the matrix
 * @return Number of rows
 */
int Matrix::getRows() const { return rows; }

/**
 * @brief Get number of columns in the matrix
 * @return Number of columns
 */
int Matrix::getCols() const { return cols; }