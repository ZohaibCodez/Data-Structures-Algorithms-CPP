#include <iostream>
#include "..\ADT's\Stack\Stack.h"
using namespace std;

template <typename T>
void reverseStack(Stack<T> &s)
{
    Stack<T> stack1;
    Stack<T> stack2;

    while (!s.isEmpty())
    {
        stack1.push(s.pop());
    }

    while (!stack1.isEmpty())
    {
        stack2.push(stack1.pop());
    }

    while (!stack2.isEmpty())
    {
        s.push(stack2.pop());
    }
}

template <typename T>
void printStack(Stack<T> S)
{
    cout << "[top -> ";
    while (!S.isEmpty())
    {
        cout << S.stackTop() << " ";
        S.pop();
    }
    cout << "]" << endl;
}

int main()
{
    // --- Test case 1 ---
    Stack<int> S1;
    for (int i = 1; i <= 5; i++)
        S1.push(i); // Stack: 1 is top, 5 is bottom
    cout << "Original stack: ";
    printStack(S1);

    reverseStack(S1);
    cout << "Reversed stack: ";
    printStack(S1);
    cout << endl;

    // --- Test case 2 ---
    Stack<int> S2;
    for (int i = 10; i <= 15; i++)
        S2.push(i); // Stack: 10 top, 15 bottom
    cout << "Original stack: ";
    printStack(S2);

    reverseStack(S2);
    cout << "Reversed stack: ";
    printStack(S2);
    cout << endl;

    // --- Test case 3 (edge case: empty) ---
    Stack<int> S3;
    cout << "Original stack (empty): ";
    printStack(S3);

    reverseStack(S3);
    cout << "Reversed stack (empty): ";
    printStack(S3);
    cout << endl;

    // --- Test case 4 (one element) ---
    Stack<int> S4;
    S4.push(42);
    cout << "Original stack: ";
    printStack(S4);

    reverseStack(S4);
    cout << "Reversed stack: ";
    printStack(S4);

    return 0;
}