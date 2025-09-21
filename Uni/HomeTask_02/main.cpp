/**
 * @file main.cpp
 * @brief Main program demonstrating Matrix and SparseMatrix classes
 * 
 * This program demonstrates:
 * 1. Creating matrices from text files
 * 2. Converting regular matrices to sparse format
 * 3. Adding sparse matrices efficiently
 * 4. Displaying results in both formats
 * 
 * The program creates sample matrix files, reads them, converts to sparse format,
 * performs addition, and shows the results.
 * 
 * @author Zohaib Khan
 * @course Data Structures and Algorithms
 */

#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "SparseMatrix.h"
using namespace std;

/**
 * @brief Read a matrix from a text file
 * @param filename Name of the file containing matrix data
 * @return Matrix object created from file data
 * 
 * File format: Each line represents a row, elements separated by spaces
 * Example:
 * 0 3 0
 * 0 0 0
 * 1 0 0
 * 
 * Process:
 * 1. First pass: Count rows and columns
 * 2. Second pass: Read actual values and store in matrix
 * 
 * @return Matrix(0,0) if file cannot be opened
 */
Matrix readMatrixFromFile(const char *filename)
{
    // Open file for reading
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Cannot open file " << filename << endl;
        return Matrix(0, 0);  // Return empty matrix on error
    }

    // Step 1: Count rows and columns
    int rows = 0, cols = 0;
    string line;
    
    // Count rows by reading each line
    while (getline(file, line))
    {
        if (!line.empty())  // Skip empty lines
        {
            rows++;
            if (cols == 0)  // Count columns only from first non-empty line
            {
                // Count elements in first row by counting space-separated tokens
                for (int i = 0; i < line.length(); i++)
                {
                    if (line[i] != ' ' && line[i] != '\t')  // Found start of a number
                    {
                        cols++;
                        // Skip to next space to avoid counting digits separately
                        while (i < line.length() && line[i] != ' ' && line[i] != '\t')
                        {
                            i++;
                        }
                    }
                }
            }
        }
    }

    // Close and reopen file for reading values
    file.close();
    file.open(filename);

    // Step 2: Create matrix and read values
    Matrix mat(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int value;
            file >> value;  // Read integer value
            mat.setValue(i, j, value);  // Store in matrix
        }
    }

    file.close();
    return mat;
}

/**
 * @brief Main function demonstrating Matrix and SparseMatrix operations
 * 
 * Program flow:
 * 1. Create sample matrix files for testing
 * 2. Read matrices from files
 * 3. Display original matrices
 * 4. Convert to sparse format
 * 5. Display sparse matrices
 * 6. Add sparse matrices
 * 7. Display result and summary
 * 
 * @return 0 on successful execution
 */
int main()
{
    // Step 1: Create sample matrix files for testing
    // These files contain matrices with many zeros to demonstrate sparse storage benefits
    
    // Create matrix1.txt: 3x3 matrix with 2 non-zero elements
    ofstream file1("matrix1.txt");
    file1 << "0 3 0\n";  // Row 0: 0, 3, 0
    file1 << "0 0 0\n";  // Row 1: 0, 0, 0
    file1 << "1 0 0\n";  // Row 2: 1, 0, 0
    file1.close();

    // Create matrix2.txt: 3x3 matrix with 3 non-zero elements
    ofstream file2("matrix2.txt");
    file2 << "1 0 2\n";  // Row 0: 1, 0, 2
    file2 << "0 4 0\n";  // Row 1: 0, 4, 0
    file2 << "0 0 5\n";  // Row 2: 0, 0, 5
    file2.close();

    // Display program header
    cout << "=== Sparse Matrix Implementation Demo ===" << endl
         << endl;

    // Step 2: Read matrices from files
    Matrix mat1 = readMatrixFromFile("matrix1.txt");
    Matrix mat2 = readMatrixFromFile("matrix2.txt");

    // Step 3: Display original matrices
    cout << "Original Matrix 1:" << endl;
    mat1.display();
    cout << endl;

    cout << "Original Matrix 2:" << endl;
    mat2.display();
    cout << endl;

    // Step 4: Create sparse matrices and convert from regular matrices
    SparseMatrix sp_A;  // Sparse version of matrix 1
    SparseMatrix sp_B;  // Sparse version of matrix 2

    // Convert regular matrices to sparse format
    // This will count non-zero elements and store them efficiently
    sp_A.Read_SparseMatrix(mat1);
    sp_B.Read_SparseMatrix(mat2);

    // Step 5: Display sparse matrices
    cout << "Sparse Matrix A:" << endl;
    sp_A.display();
    cout << endl;

    cout << "Sparse Matrix B:" << endl;
    sp_B.display();
    cout << endl;

    // Step 6: Add sparse matrices using efficient algorithm
    // This demonstrates the power of sparse matrix operations
    SparseMatrix result = sp_A.AddSparseMatrix(sp_B);

    // Step 7: Display result and summary
    cout << "Result of Sparse Matrix Addition (A + B):" << endl;
    result.display();
    cout << endl;

    // Display summary statistics
    cout << "Summary:" << endl;
    cout << "Matrix A non-zero elements: " << sp_A.getNonZero() << endl;
    cout << "Matrix B non-zero elements: " << sp_B.getNonZero() << endl;
    cout << "Result matrix non-zero elements: " << result.getNonZero() << endl;

    return 0;
}
