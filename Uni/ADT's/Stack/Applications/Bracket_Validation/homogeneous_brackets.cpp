#include <iostream>
#include <string>
#include "../../Stack.h"
using namespace std;

int homogeneousBracketsValidity(string infixString)
{
    Stack<char> s;

    cout << "\nChecking: " << infixString << endl;
    cout << "Following the pseudocode step by step:\n";

    for (int i = 0; i < infixString.length(); i++)
    {
        char next_character = infixString[i];
        cout << "Position " << i << ": character = '" << next_character << "' -> ";
        if (next_character == '(')
        {
            s.push(next_character);
            cout << "Opening bracket - pushed to stack\n";
        }
        if (next_character == ')')
        {
            cout << "Closing bracket - ";
            if (s.isEmpty())
            {
                cout << "Stack is empty - return 0\n";
                return 0;
            }
            char stacktop = s.pop();
            if (stacktop != '(')
            {
                cout << "Stack top is not '(' - return 0\n";
                return 0;
            }
            cout << "Matched with '(' from stack\n";
        }
    }
    cout << "Finished scanning. Checking final stack state...\n";
    if (s.isEmpty())
    {
        cout << "Stack is empty - return 1 (VALID)\n";
        return 1;
    }
    else
    {
        cout << "Stack is not empty - return 0 (INVALID)\n";
        return 0;
    }
}

int main()
{
    cout << "=== Homogeneous Brackets Validity (Following Teacher's Pseudocode) ===\n";
    string testExpressions[] = {
        "(a+b)",
        "((a+b)*c)",
        "(a+b)*(c+d)",
        "((a+b)", // Invalid - missing closing
        "(a+b))", // Invalid - extra closing
        ")a+b(",  // Invalid - wrong order
        "a+b*c",  // Valid - no brackets
        "()",     // Valid - empty brackets
        "((()))"  // Valid - nested
    };

    for (int i = 0; i < 9; i++)
    {
        cout << "\n"
             << string(50, '=') << endl;
        cout << "Test " << (i + 1) << ": ";

        int result = homogeneousBracketsValidity(testExpressions[i]);

        cout << "\nFINAL RESULT: " << result;
        if (result == 1)
        {
            cout << " (VALID expression)";
        }
        else
        {
            cout << " (INVALID expression)";
        }
        cout << endl;
    }
}