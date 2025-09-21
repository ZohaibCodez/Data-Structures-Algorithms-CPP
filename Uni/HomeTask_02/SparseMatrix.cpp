#include "SparseMatrix.h"
#include "Matrix.h"

SparseMatrix::SparseMatrix(int non_zero)
{
    this->non_zero = non_zero;
    if (non_zero > 0)
    {
        S_Mat = new int *[non_zero];
        for (int i = 0; i < non_zero; i++)
        {
            S_Mat[i] = new int[colms];
            for (int j = 0; j < colms; j++)
            {
                S_Mat[i][j] = 0;
            }
        }
    }
    else
    {
        S_Mat = nullptr;
    }
}

SparseMatrix::~SparseMatrix()
{
    for (int i = 0; i < non_zero; i++)
    {
        delete[] S_Mat[i];
    }
    delete[] S_Mat;
}

void SparseMatrix::Read_SparseMatrix(const Matrix &mat)
{
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

    if (S_Mat != nullptr)
    {
        for (int i = 0; i < non_zero; i++)
        {
            delete[] S_Mat[i];
        }
        delete[] S_Mat;
    }

    non_zero = count;
    if (non_zero > 0)
    {
        S_Mat = new int *[non_zero];
        for (int i = 0; i < non_zero; i++)
        {
            S_Mat[i] = new int[colms];
        }

        // Fill sparse matrix
        int index = 0;
        for (int i = 0; i < mat.getRows(); i++)
        {
            for (int j = 0; j < mat.getCols(); j++)
            {
                if (mat.getValue(i, j) != 0)
                {
                    S_Mat[index][0] = i;                  // row
                    S_Mat[index][1] = j;                  // col
                    S_Mat[index][2] = mat.getValue(i, j); // value
                    index++;
                }
            }
        }
    }
}

SparseMatrix SparseMatrix::AddSparseMatrix(SparseMatrix B)
{
    // Simple addition - assuming matrices have same dimensions
    // Create a temporary array to store all elements
    int maxElements = this->non_zero + B.non_zero;
    int **temp = new int *[maxElements];
    for (int i = 0; i < maxElements; i++)
    {
        temp[i] = new int[3];
    }

    int resultCount = 0;
    int i = 0, j = 0;

    // Merge the two sparse matrices
    while (i < this->non_zero && j < B.non_zero)
    {
        int thisRow = this->S_Mat[i][0];
        int thisCol = this->S_Mat[i][1];
        int BRow = B.S_Mat[j][0];
        int BCol = B.S_Mat[j][1];

        if (thisRow < BRow || (thisRow == BRow && thisCol < BCol))
        {
            temp[resultCount][0] = thisRow;
            temp[resultCount][1] = thisCol;
            temp[resultCount][2] = this->S_Mat[i][2];
            i++;
        }
        else if (thisRow > BRow || (thisRow == BRow && thisCol > BCol))
        {
            temp[resultCount][0] = BRow;
            temp[resultCount][1] = BCol;
            temp[resultCount][2] = B.S_Mat[j][2];
            j++;
        }
        else
        { // Same position
            int sum = this->S_Mat[i][2] + B.S_Mat[j][2];
            if (sum != 0)
            {
                temp[resultCount][0] = thisRow;
                temp[resultCount][1] = thisCol;
                temp[resultCount][2] = sum;
            }
            i++;
            j++;
        }
        if (temp[resultCount][2] != 0)
        {
            resultCount++;
        }
    }
    while (i < this->non_zero)
    {
        temp[resultCount][0] = this->S_Mat[i][0];
        temp[resultCount][1] = this->S_Mat[i][1];
        temp[resultCount][2] = this->S_Mat[i][2];
        resultCount++;
        i++;
    }

    // Add remaining elements from B matrix
    while (j < B.non_zero)
    {
        temp[resultCount][0] = B.S_Mat[j][0];
        temp[resultCount][1] = B.S_Mat[j][1];
        temp[resultCount][2] = B.S_Mat[j][2];
        resultCount++;
        j++;
    }

    // Create result sparse matrix
    SparseMatrix result(resultCount);
    for (int k = 0; k < resultCount; k++)
    {
        result.S_Mat[k][0] = temp[k][0];
        result.S_Mat[k][1] = temp[k][1];
        result.S_Mat[k][2] = temp[k][2];
    }

    // Clean up temporary array
    for (int k = 0; k < maxElements; k++)
    {
        delete[] temp[k];
    }
    delete[] temp;

    return result;
}

void SparseMatrix::display() const
{
    cout << "Sparse Matrix (Non-zero elements: " << non_zero << "):" << endl;
    cout << "Row Col Value" << endl;
    for (int i = 0; i < non_zero; i++)
    {
        cout << S_Mat[i][0] << "   " << S_Mat[i][1] << "   " << S_Mat[i][2] << endl;
    }
}

int SparseMatrix::getNonZero() const { return non_zero; }