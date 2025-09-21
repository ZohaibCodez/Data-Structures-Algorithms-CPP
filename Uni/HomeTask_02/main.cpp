#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "SparseMatrix.h"
using namespace std;

Matrix readMatrixFromFile(const char *filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Cannot open file " << filename << endl;
        return Matrix(0, 0);
    }

    // Count rows and columns
    int rows = 0, cols = 0;
    string line;
    while (getline(file, line))
    {
        if (!line.empty())
        {
            rows++;
            if (cols == 0)
            {
                // Count elements in first row
                for (int i = 0; i < line.length(); i++)
                {
                    if (line[i] != ' ' && line[i] != '\t')
                    {
                        cols++;
                        // Skip to next space
                        while (i < line.length() && line[i] != ' ' && line[i] != '\t')
                        {
                            i++;
                        }
                    }
                }
            }
        }
    }

    file.close();
    file.open(filename);

    Matrix mat(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int value;
            file >> value;
            mat.setValue(i, j, value);
        }
    }

    file.close();
    return mat;
}

int main()
{
    // Create sample files for testing
    ofstream file1("matrix1.txt");
    file1 << "0 3 0\n";
    file1 << "0 0 0\n";
    file1 << "1 0 0\n";
    file1.close();

    ofstream file2("matrix2.txt");
    file2 << "1 0 2\n";
    file2 << "0 4 0\n";
    file2 << "0 0 5\n";
    file2.close();

    cout << "=== Sparse Matrix Implementation Demo ===" << endl
         << endl;

    // Read matrices from files
    Matrix mat1 = readMatrixFromFile("matrix1.txt");
    Matrix mat2 = readMatrixFromFile("matrix2.txt");

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
