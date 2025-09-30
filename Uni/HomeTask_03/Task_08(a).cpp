#include <iostream>
#include "..\ADT's\Stack\Stack.h"

using namespace std;

template <typename T>
void transferWithAdditionalStack(Stack<T> &S1, Stack<T> &S2)
{
    Stack<T> temp(S1.getTop() + 1);

    // Step 1: S1 → temp
    while (!S1.isEmpty())
    {
        temp.push(S1.pop());
    }

    // Step 2: temp → S2
    while (!temp.isEmpty())
    {
        S2.push(temp.pop());
    }
}

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
    Stack<int> S1(10), S2(10);
    for (int i = 1; i <= 5; i++)
        S1.push(i); // top=5, bottom=1

    cout << "S1 original: ";
    printStack(S1);

    transferWithAdditionalStack(S1, S2);

    cout << "S2 after transfer (with extra stack): ";
    printStack(S2);

    return 0;
}
