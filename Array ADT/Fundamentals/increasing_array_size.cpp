/*
Topic: Increasing Array Size (Manual Dynamic Array Resize)
Difficulty: Beginner

Time Complexity: O(n) - copying n elements to a larger array
Space Complexity: O(1) auxiliary - excluding the new allocated array

Approach:
- Allocate an initial dynamic array `p` of smaller size and fill it
- Allocate a larger array `q`
- Copy elements from `p` to `q`
- Delete the old array `p` to free memory
- Point `p` to `q` and nullify `q`
- Optionally initialize the new slots

Example:
Initial: [1 2 3 4 5]
After resize to 10: [1 2 3 4 5 6 7 8 9 10]

Key Learning:
- How to manually grow a dynamic array using raw pointers
- Importance of freeing the old allocation before reassigning the pointer
- Why higher-level containers like std::vector handle this automatically
*/

#include <iostream>
using namespace std;

int main()
{
    int *p = nullptr, *q = nullptr;
    int i;

    // Allocate initial array of size 5 and fill
    p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    cout << "Before resize (size = 5): ";
    for (i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    // Allocate larger array of size 10
    q = new int[10];

    // Copy existing elements
    for (i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    // Initialize new slots (for demo, continue the sequence)
    for (i = 5; i < 10; i++)
    {
        q[i] = i + 1; // 6..10
    }

    // Release old memory and reassign
    delete[] p;
    p = q;
    q = nullptr;

    cout << "After resize (size = 10): ";
    for (i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    // Final cleanup of the active allocation
    delete[] p;
    p = nullptr;

    return 0;
}