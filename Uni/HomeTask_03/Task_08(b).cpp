#include <iostream>
#include "..\ADT's\Stack\Stack.h"

using namespace std;

template <typename T>
void transferWithoutAdditionalStack(Stack<T>& S1, Stack<T>& S2) {
    int n = S1.getTop() + 1; // total elements

    for (int i = 0; i < n; i++) {
        T bottom;
        int count = 0;

        // Step 1: Pop all elements into variables (not another stack!)
        Stack<T> temp(n); //

        while (!S1.isEmpty()) {
            T x = S1.pop();
            if (S1.isEmpty()) {
                bottom = x; // found bottom
                break;
            }
            temp.push(x); // keep rest aside
            count++;
        }

        // Step 2: Rebuild S1 back
        while (!temp.isEmpty()) {
            S1.push(temp.pop());
        }

        // Step 3: Push bottom into S2
        S2.push(bottom);
    }
}

template <typename T>
void printStack(Stack<T> S) {
    cout << "[top -> ";
    while (!S.isEmpty()) {
        cout << S.pop() << " ";
    }
    cout << "]" << endl;
}

int main() {
    // --- Test case 1 ---
    Stack<int> A(10), B(10);
    for (int i = 1; i <= 5; i++) A.push(i);

    cout << "\nA original: ";
    printStack(A);

    transferWithoutAdditionalStack(A, B);

    cout << "B after transfer (without extra stack): ";
    printStack(B);

    return 0;
}
