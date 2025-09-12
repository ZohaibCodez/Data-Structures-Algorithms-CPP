/*
Topic: 2D Array Memory Allocation Patterns
Difficulty: Intermediate

Time Complexity: O(rows * cols) - for initialization and printing
Space Complexity: O(rows * cols) - for storing the 2D array data

Approach:
- Demonstrates three different ways to create 2D arrays in C++
- Stack allocation: All data stored in stack memory
- Partial heap: Array of pointers in stack, data in heap
- Full heap: Both pointers and data in heap memory
- Shows memory management differences and access patterns

Example:
All three methods create a 3x3 matrix with values 1-9:
1 2 3
4 5 6
7 8 9

Key Learning:
- Understanding stack vs heap memory allocation
- Memory management responsibilities for different allocation methods
- Performance implications of different 2D array implementations
- Proper cleanup of dynamically allocated memory
*/

#include <iostream>
using namespace std;

int main()
{
    const int ROWS = 3, COLS = 3;
    int i, j;
    int counter = 1;

    // Method 1: Stack Allocation - Everything in stack
    cout << "=== Method 1: Stack Allocation (Everything in Stack) ===" << endl;
    int A[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Memory: Allocated on stack, automatically freed" << endl
         << endl;

    // Method 2: Partial Heap - Array of pointers in stack, data in heap
    cout << "=== Method 2: Partial Heap (Pointers in Stack, Data in Heap) ===" << endl;
    int *B[ROWS]; // Array of pointers in stack
    for (i = 0; i < ROWS; i++)
    {
        B[i] = new int[COLS]; // Each row allocated in heap
        for (j = 0; j < COLS; j++)
        {
            B[i][j] = counter++; // Initialize with values 1-9
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Memory: Pointers on stack, data on heap" << endl
         << endl;

    // Method 3: Full Heap - Everything in heap
    cout << "=== Method 3: Full Heap (Everything in Heap) ===" << endl;
    int **C = new int *[ROWS]; // Array of pointers in heap
    counter = 1;
    for (i = 0; i < ROWS; i++)
    {
        C[i] = new int[COLS]; // Each row allocated in heap
        for (j = 0; j < COLS; j++)
        {
            C[i][j] = counter++; // Initialize with values 1-9
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Memory: Both pointers and data on heap" << endl
         << endl;

    // Cleanup for heap allocations
    cout << "=== Memory Cleanup ===" << endl;

    // Cleanup Method 2 (Partial Heap)
    for (i = 0; i < ROWS; i++)
    {
        delete[] B[i];
    }
    cout << "Method 2 memory freed" << endl;

    // Cleanup Method 3 (Full Heap)
    for (i = 0; i < ROWS; i++)
    {
        delete[] C[i];
    }
    delete[] C;
    cout << "Method 3 memory freed" << endl;

    return 0;
}