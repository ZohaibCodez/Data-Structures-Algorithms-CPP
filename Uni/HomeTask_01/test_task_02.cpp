#include <iostream>
#include "Task_02.h"

int main()
{
    cout << "=== Creating 3x3 Array ===\n";
    Array2D arr(3, 3);

    // Set values manually
    cout << "\nSetting values...\n";
    int counter = 1;
    for (int j = 0; j < 3; j++)
    { // columns first (to reflect column-major)
        for (int i = 0; i < 3; i++)
        { // rows inside
            arr.setIndexValue(i, j, counter++);
        }
    }

    cout << "\nArray contents (Column-Major Layout):\n";
    arr.printArray();

    cout << "\n=== Testing getIndexValue ===\n";
    cout << "Value at (1, 2): " << arr.getIndexValue(1, 2) << endl;

    cout << "\n=== Testing addressOfIndex ===\n";
    cout << "Logical address of (1, 2) from base index 0: "
         << arr.addressOfIndex(1, 2) << endl;
    cout << "Logical address of (0, 0) from base index 1000: "
         << arr.addressOfIndex(0, 0, 1000) << endl;

    cout << "\n=== Testing Copy Constructor ===\n";
    Array2D copyArr = arr;
    cout << "Copied Array:\n";
    copyArr.printArray();

    cout << "\n=== Testing Operator+ ===\n";
    Array2D sum = arr + copyArr;
    cout << "Sum of arr + copyArr:\n";
    sum.printArray();

    cout << "\n=== Testing printSubArray (1,3)x(0,2) ===\n";
    sum.printSubArray(1, 3, 0, 2);

    cout << "\n=== Testing clear(0,2,1,3) ===\n";
    sum.clear(0, 2, 1, 3);
    sum.printArray();

    cout << "\nProgram finished — no memory leaks expected ✅\n";
    return 0;
}
