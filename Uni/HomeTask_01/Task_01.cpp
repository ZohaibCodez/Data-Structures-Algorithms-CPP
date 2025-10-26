#include <iostream>

using namespace std;

void allocateArray(int ***&arr, int n = 3)
{
    arr = new int **[n];
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = new int *[n];
        for (int j = 0; j < n; j++)
        {
            *(*(arr + i) + j) = new int[n];
        }
    }
}

void initializeArray(int ***arr, int n = 3)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                *(*(*(arr + i) + j) + k) = rand() % 100;
            }
        }
    }
}

void printArray(int ***arr, int n = 3)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << *(*(*(arr + i) + j) + k) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void deallocateArray(int ***arr, int n = 3)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            delete[] *(*(arr + i) + j);
        }
        delete[] *(arr + i);
    }
    delete[] arr;
}

int main()
{
    srand(time(0));

    int ***arr = nullptr;

    allocateArray(arr, 3);
    initializeArray(arr, 3);
    printArray(arr, 3);
    deallocateArray(arr, 3);

    return 0;
}