/**
 * @file SparseMatrix.cpp
 * @brief Implementation file for SparseMatrix class
 * 
 * This file contains the implementation of all methods declared in SparseMatrix.h
 * It demonstrates efficient storage and manipulation of sparse matrices
 */

#include "SparseMatrix.h"
#include "Matrix.h"

/**
 * @brief Constructor - Creates a sparse matrix with specified number of non-zero elements
 * @param non_zero Number of non-zero elements to allocate space for
 * 
 * Memory allocation process:
 * 1. If non_zero > 0: Allocate memory for storing non-zero elements
 * 2. If non_zero = 0: Set S_Mat to nullptr (no memory needed)
 * 3. Initialize all allocated elements to 0
 */
SparseMatrix::SparseMatrix(int non_zero)
{
    // Store the number of non-zero elements
    this->non_zero = non_zero;
    
    if (non_zero > 0)
    {
        // Allocate memory for array of row pointers (one for each non-zero element)
        S_Mat = new int *[non_zero];
        
        // For each non-zero element, allocate memory for 3 columns [row, col, value]
        for (int i = 0; i < non_zero; i++)
        {
            S_Mat[i] = new int[colms];  // colms = 3 (row, col, value)
            
            // Initialize all values to 0
            for (int j = 0; j < colms; j++)
            {
                S_Mat[i][j] = 0;
            }
        }
    }
    else
    {
        // No non-zero elements, so no memory needed
        S_Mat = nullptr;
    }
}

/**
 * @brief Destructor - Frees all allocated memory
 * 
 * Memory deallocation process:
 * 1. Delete each row's memory (array of 3 integers)
 * 2. Delete the array of row pointers
 * 
 * This prevents memory leaks when the object goes out of scope
 */
SparseMatrix::~SparseMatrix()
{
    // Delete each row's memory
    for (int i = 0; i < non_zero; i++)
    {
        delete[] S_Mat[i];  // Delete array of 3 integers for element i
    }
    
    // Delete the array of row pointers
    delete[] S_Mat;
}

/**
 * @brief Convert a regular Matrix to sparse format
 * @param mat Reference to the Matrix object to convert
 * 
 * Conversion process:
 * 1. Count non-zero elements in the input matrix
 * 2. Free existing memory if any
 * 3. Allocate new memory for the counted non-zero elements
 * 4. Store each non-zero element with its position and value
 * 
 * Storage format: Each row contains [row_index, col_index, value]
 */
void SparseMatrix::Read_SparseMatrix(const Matrix &mat)
{
    // Step 1: Count non-zero elements in the input matrix
    int count = 0;
    for (int i = 0; i < mat.getRows(); i++)
    {
        for (int j = 0; j < mat.getCols(); j++)
        {
            if (mat.getValue(i, j) != 0)
            {
                count++;
            }
        }
    }

    // Step 2: Free existing memory if any
    if (S_Mat != nullptr)
    {
        for (int i = 0; i < non_zero; i++)
        {
            delete[] S_Mat[i];
        }
        delete[] S_Mat;
    }

    // Step 3: Update non_zero count and allocate new memory
    non_zero = count;
    if (non_zero > 0)
    {
        // Allocate memory for the counted non-zero elements
        S_Mat = new int *[non_zero];
        for (int i = 0; i < non_zero; i++)
        {
            S_Mat[i] = new int[colms];  // 3 columns: [row, col, value]
        }

        // Step 4: Fill sparse matrix with non-zero elements
        int index = 0;  // Index for storing elements in sparse matrix
        for (int i = 0; i < mat.getRows(); i++)
        {
            for (int j = 0; j < mat.getCols(); j++)
            {
                if (mat.getValue(i, j) != 0)
                {
                    S_Mat[index][0] = i;                  // Store row index
                    S_Mat[index][1] = j;                  // Store column index
                    S_Mat[index][2] = mat.getValue(i, j); // Store value
                    index++;
                }
            }
        }
    }
}

/**
 * @brief Add two sparse matrices and return the result
 * @param B The sparse matrix to add to this matrix
 * @return A new SparseMatrix containing the sum
 * 
 * Addition algorithm (similar to merging two sorted arrays):
 * 1. Create temporary array to store all possible elements
 * 2. Use two pointers to traverse both matrices simultaneously
 * 3. Compare positions (row, col) and add elements accordingly:
 *    - If positions are different: copy the element with smaller position
 *    - If positions are same: add values and store if sum != 0
 * 4. Copy remaining elements from both matrices
 * 5. Create result matrix with actual non-zero elements
 * 6. Clean up temporary memory
 * 
 * Time Complexity: O(n + m) where n, m are non-zero elements in each matrix
 */
SparseMatrix SparseMatrix::AddSparseMatrix(SparseMatrix B)
{
    // Step 1: Create temporary array to store all possible elements
    // Maximum possible elements = sum of non-zero elements from both matrices
    int maxElements = this->non_zero + B.non_zero;
    int **temp = new int *[maxElements];
    for (int i = 0; i < maxElements; i++)
    {
        temp[i] = new int[3];  // Each element has [row, col, value]
    }

    int resultCount = 0;  // Count of actual non-zero elements in result
    int i = 0, j = 0;     // Pointers for traversing both matrices

    // Step 2: Merge the two sparse matrices using two-pointer technique
    while (i < this->non_zero && j < B.non_zero)
    {
        // Get positions and values from both matrices
        int thisRow = this->S_Mat[i][0];
        int thisCol = this->S_Mat[i][1];
        int BRow = B.S_Mat[j][0];
        int BCol = B.S_Mat[j][1];

        // Compare positions (row first, then column)
        if (thisRow < BRow || (thisRow == BRow && thisCol < BCol))
        {
            // Current matrix has smaller position, copy its element
            temp[resultCount][0] = thisRow;
            temp[resultCount][1] = thisCol;
            temp[resultCount][2] = this->S_Mat[i][2];
            i++;
        }
        else if (thisRow > BRow || (thisRow == BRow && thisCol > BCol))
        {
            // Matrix B has smaller position, copy its element
            temp[resultCount][0] = BRow;
            temp[resultCount][1] = BCol;
            temp[resultCount][2] = B.S_Mat[j][2];
            j++;
        }
        else
        {
            // Same position - add the values
            int sum = this->S_Mat[i][2] + B.S_Mat[j][2];
            if (sum != 0)  // Only store if sum is non-zero
            {
                temp[resultCount][0] = thisRow;
                temp[resultCount][1] = thisCol;
                temp[resultCount][2] = sum;
            }
            i++;
            j++;
        }
        
        // Only increment resultCount if we stored a non-zero element
        if (temp[resultCount][2] != 0)
        {
            resultCount++;
        }
    }
    
    // Step 3: Copy remaining elements from current matrix
    while (i < this->non_zero)
    {
        temp[resultCount][0] = this->S_Mat[i][0];
        temp[resultCount][1] = this->S_Mat[i][1];
        temp[resultCount][2] = this->S_Mat[i][2];
        resultCount++;
        i++;
    }

    // Step 4: Copy remaining elements from matrix B
    while (j < B.non_zero)
    {
        temp[resultCount][0] = B.S_Mat[j][0];
        temp[resultCount][1] = B.S_Mat[j][1];
        temp[resultCount][2] = B.S_Mat[j][2];
        resultCount++;
        j++;
    }

    // Step 5: Create result sparse matrix with actual non-zero elements
    SparseMatrix result(resultCount);
    for (int k = 0; k < resultCount; k++)
    {
        result.S_Mat[k][0] = temp[k][0];  // Copy row index
        result.S_Mat[k][1] = temp[k][1];  // Copy column index
        result.S_Mat[k][2] = temp[k][2];  // Copy value
    }

    // Step 6: Clean up temporary array to prevent memory leaks
    for (int k = 0; k < maxElements; k++)
    {
        delete[] temp[k];
    }
    delete[] temp;

    return result;
}

/**
 * @brief Display the sparse matrix in a formatted way
 * 
 * Output format:
 * Sparse Matrix (Non-zero elements: X):
 * Row Col Value
 * [row] [col] [value]
 * ...
 * 
 * Shows each non-zero element with its position and value
 */
void SparseMatrix::display() const
{
    // Print header with number of non-zero elements
    cout << "Sparse Matrix (Non-zero elements: " << non_zero << "):" << endl;
    cout << "Row Col Value" << endl;
    
    // Print each non-zero element
    for (int i = 0; i < non_zero; i++)
    {
        cout << S_Mat[i][0] << "   " << S_Mat[i][1] << "   " << S_Mat[i][2] << endl;
    }
}

/**
 * @brief Get the number of non-zero elements in the sparse matrix
 * @return Number of non-zero elements
 */
int SparseMatrix::getNonZero() const { return non_zero; }