/*
Type: Head Recursion
Difficulty: Beginner

Time Complexity: O(n)
Space Complexity: O(n) - due to recursive call stack

Approach:
- Base case: Stop when n becomes 0 or negative
- Recursive case: Call function with n-1, then print current number
- This demonstrates head recursion as processing happens after recursive call and our recursive call is the very first statement executed by the function

Example:
Input: n = 3
Output: 1 2 3 (each on new line)

Key Learning:
- Understanding base case importance
- Call stack visualization
- Head recursion pattern
*/

#include <iostream>
using namespace std;

void func(int n)
{
    if (n > 0)
    {
        func(n - 1);
        cout << n << endl;
    }
}

int main()
{
    int x = 3;

    func(x);
    return 0;
}