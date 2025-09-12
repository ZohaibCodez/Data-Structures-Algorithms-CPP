/*
Type: Tree Recursion
Difficulty: Beginner

Time Complexity: O(2^n) - exponential due to two recursive calls at each level
Space Complexity: O(n) - maximum depth of recursion tree is n

Approach:
- Base case: Stop when n becomes 0 or negative
- Recursive case: Print current number, then make TWO recursive calls with n-1
- This creates a binary tree structure where each node has two children
- Each level doubles the number of function calls

Example:
Input: n = 3
Output: 3 2 1 1 2 1 1 (showing the tree traversal pattern)

Key Learning:
- Understanding exponential time complexity
- Visualizing recursion tree structure
- Recognizing when multiple recursive calls create exponential growth
- Call stack visualization for tree recursion
*/

#include <iostream>
using namespace std;

void func(int n)
{
    if (n > 0)
    {
        cout << n << " ";        // Process current node
        func(n - 1);              // Left subtree
        func(n - 1);              // Right subtree
    }
}

int main()
{
    int x = 3;

    cout << "Tree Recursion Example with n = " << x << ":" << endl;
    cout << "Output shows the tree traversal pattern:";
    func(x);
    
    return 0;
}