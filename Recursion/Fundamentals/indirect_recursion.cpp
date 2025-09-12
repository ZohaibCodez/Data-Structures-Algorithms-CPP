/*
Type: Indirect Recursion
Difficulty: Intermediate

Time Complexity: O(log n) - each call reduces n by half or by 1
Space Complexity: O(log n) - maximum depth of recursion stack

Approach:
- Two functions call each other indirectly (funcA calls funcB, funcB calls funcA)
- funcA: Prints current value and calls funcB with n-1
- funcB: Prints current value and calls funcA with n/2
- Base cases: funcA stops when n <= 0, funcB stops when n <= 1
- This creates a pattern where values decrease by subtraction and division

Example:
Input: funcA(20)
Output: 20 19 9 8 4 3 1 (showing the alternating pattern between functions)

Key Learning:
- Understanding indirect recursion (functions calling each other)
- Recognizing different termination conditions for different functions
- Visualizing call stack with multiple functions
- Understanding how different reduction patterns affect complexity
*/

#include <iostream>
using namespace std;

// Forward declaration
void funcB(int n);

void funcA(int n)
{
    if (n > 0)
    {
        cout << n << " ";        // Process current value in funcA
        funcB(n - 1);            // Call funcB with n-1
    }
}

void funcB(int n)
{
    if (n > 1)
    {
        cout << n << " ";        // Process current value in funcB
        funcA(n / 2);            // Call funcA with n/2
    }
}

int main()
{
    int x = 20;
    
    cout << "Indirect Recursion Example with funcA(" << x << "):" << endl;
    cout << "Output shows alternating calls between funcA and funcB:" << endl;
    funcA(x);
    cout << endl;
    
    return 0;
}