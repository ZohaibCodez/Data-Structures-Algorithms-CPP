#include <iostream>
#include "..\ADT's\Stack\Stack.h"
using namespace std;

template <typename T>
void reverseStack(Stack<T> &S)
{
    Stack<T> temp(S.getTop() + 1); // temp stack with same size as S

    int n = S.getTop() + 1; // number of elements in stack

    // Outer loop → repeat for each element
    for (int i = 0; i < n; i++)
    {
        // Step 1: take top element
        T topElem = S.pop();

        // Step 2: move remaining (n-i-1) elements into temp
        for (int j = 0; j < n - i - 1; j++)
        {
            temp.push(S.pop());
        }

        // Step 3: put saved element at bottom of S
        S.push(topElem);

        // Step 4: move back from temp into S
        while (!temp.isEmpty())
        {
            S.push(temp.pop());
        }
    }
}

// Utility function to print stack (top to bottom)
template <typename T>
void printStack(Stack<T> S)
{
    cout << "[top -> ";
    while (!S.isEmpty())
    {
        cout << S.pop() << " ";
    }
    cout << "]" << endl;
}

int main()
{
    // --- Test case 1 ---
    Stack<int> S1(10);
    for (int i = 1; i <= 5; i++)
        S1.push(i); // Stack: top=5, bottom=1

    cout << "Original stack: ";
    printStack(S1);

    reverseStack(S1);

    cout << "Reversed stack: ";
    printStack(S1);

    // --- Test case 2 (edge case: one element) ---
    Stack<int> S2(5);
    S2.push(42);
    cout << "\nOriginal stack: ";
    printStack(S2);
    reverseStack(S2);
    cout << "Reversed stack: ";
    printStack(S2);

    // --- Test case 3 (edge case: empty stack) ---
    Stack<int> S3(5);
    cout << "\nOriginal empty stack: ";
    printStack(S3);
    reverseStack(S3);
    cout << "Reversed empty stack: ";
    printStack(S3);

    return 0;
}
