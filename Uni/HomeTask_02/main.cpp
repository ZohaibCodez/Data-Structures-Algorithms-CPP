#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "SparseMatrix.h"
using namespace std;

bool readMatrixFromFile(const char *filename, Matrix &mat)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Cannot open file " << filename << endl;
        return false;
    }

    // Read values into a temporary array first
    int values[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int value;
            if (file >> value)
            {
                values[i][j] = value;
            }
            else
            {
                cout << "Error reading matrix data" << endl;
                file.close();
                return false;
            }
        }
    }

    // Now set the values in the matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat.setValue(i, j, values[i][j]);
        }
    }

    file.close();
    return true;
}

int main()
{
    cout << "=== Sparse Matrix Implementation Demo ===" << endl
         << endl;

    // Create sample files for testing
    ofstream file1("matrix1.txt");
    file1 << "0 3 0" << endl;
    file1 << "0 0 0" << endl;
    file1 << "1 0 0" << endl;
    file1.close();

    ofstream file2("matrix2.txt");
    file2 << "1 0 2" << endl;
    file2 << "0 4 0" << endl;
    file2 << "0 0 5" << endl;
    file2.close();

    cout << "Files created successfully." << endl
         << endl;

    // Read matrices from files
    Matrix mat1(3, 3), mat2(3, 3);
    if (!readMatrixFromFile("matrix1.txt", mat1) || !readMatrixFromFile("matrix2.txt", mat2))
    {
        cout << "Failed to read matrix files" << endl;
        return 1;
    }

    cout << "Original Matrix 1:" << endl;
    mat1.display();
    cout << endl;

    cout << "Original Matrix 2:" << endl;
    mat2.display();
    cout << endl;

    // Create sparse matrices
    SparseMatrix sp_A;
    SparseMatrix sp_B;

    // Convert regular matrices to sparse matrices
    sp_A.Read_SparseMatrix(mat1);
    sp_B.Read_SparseMatrix(mat2);

    cout << "Sparse Matrix A:" << endl;
    sp_A.display();
    cout << endl;

    cout << "Sparse Matrix B:" << endl;
    sp_B.display();
    cout << endl;

    // Add sparse matrices
    SparseMatrix result = sp_A.AddSparseMatrix(sp_B);

    cout << "Result of Sparse Matrix Addition (A + B):" << endl;
    result.display();
    cout << endl;

    cout << "Summary:" << endl;
    cout << "Matrix A non-zero elements: " << sp_A.getNonZero() << endl;
    cout << "Matrix B non-zero elements: " << sp_B.getNonZero() << endl;
    cout << "Result matrix non-zero elements: " << result.getNonZero() << endl;

    return 0;
}


