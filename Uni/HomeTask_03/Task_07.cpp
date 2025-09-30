#include <iostream>
#include "..\ADT's\Stack\Stack.h"

using namespace std;

template <typename T>
void sortStack(Stack<T> &s)
{
    Stack<T> temp;
    while (!s.isEmpty())
    {
        T curr = s.pop();
        while (!temp.isEmpty() && temp.stackTop() > curr)
        {
            s.push(temp.pop());
        }

        temp.push(curr);
    }

    while (!temp.isEmpty())
    {
        s.push(temp.pop());
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
    S1.push(3);
    S1.push(1);
    S1.push(4);
    S1.push(2);

    cout << "Original stack: ";
    printStack(S1);

    sortStack(S1);

    cout << "Sorted stack: ";
    printStack(S1);

    // --- Test case 2 ---
    Stack<int> S2(10);
    S2.push(10);
    S2.push(5);
    S2.push(8);
    S2.push(1);
    S2.push(7);

    cout << "\nOriginal stack: ";
    printStack(S2);

    sortStack(S2);

    cout << "Sorted stack: ";
    printStack(S2);

    // --- Test case 3 (already sorted) ---
    Stack<int> S3(10);
    for (int i = 1; i <= 5; i++)
        S3.push(i);

    cout << "\nOriginal (already sorted): ";
    printStack(S3);

    sortStack(S3);

    cout << "Sorted stack: ";
    printStack(S3);

    return 0;
}