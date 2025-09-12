/*
Type: Tail Recursion
Difficulty: Beginner

Time Complexity: O(n)
Space Complexity: O(n) - due to recursive call stack

Approach:
- Base case: Stop when n becomes 0 or negative
- Recursive case: Print current number, then call function with n-1
- This demonstrates tail recursion as processing happens before recursive call and our recursive call is the last statement executed by the function

Example:
Input: n = 3
Output: 3 2 1 (each on new line)

Key Learning:
- Understanding base case importance
- Call stack visualization
- Tail recursion pattern
*/

#include <iostream>
using namespace std;

void func(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        func(n - 1);
    }
}

int main()
{
    int x = 3;

    func(x);
    return 0;
}