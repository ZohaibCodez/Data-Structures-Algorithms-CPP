#include <iostream>
#include <string>
#include "..\..\..\ADT's\Stack\Stack.h"
using namespace std;

int heterogeneousBracketsValidity(string infixString)
{
    Stack<char> s;

    cout << "\nChecking: " << infixString << endl;
    cout << "Following the pseudocode step by step:\n";

    for (int i = 0; i < infixString.length(); i++)
    {
        char next_character = infixString[i];
        cout << "Position " << i << ": character = '" << next_character << "' -> ";

        if (next_character == '(' || next_character == '{' || next_character == '[')
        {
            s.push(next_character);
            cout << "bracket found - pushed to stack\n";
        }

        if (next_character == ')' || next_character == '}' || next_character == ']')
        {
            cout << "Closing bracket - ";
            if (s.isEmpty())
            {
                cout << "Stack is empty - return 0\n";
                return 0;
            }

            char stackTop = s.pop();
            if ((stackTop == '(' && next_character != ')') ||
                (stackTop == '{' && next_character != '}') ||
                (stackTop == '[' && next_character != ']'))
            {
                cout << "Stack top is not '(' or '{' or '[' - return 0\n";
                return 0;
            }
            cout << "Opening bracket match from stack\n";
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
    cout << "=== Heterogeneous Brackets Validity (Following Teacher's Pseudocode) ===\n";

    string testExpressions[] = {
        "(a+b)",
        "{a+b}",
        "[a+b]",
        "({a+b})",
        "[(a+b)*{c+d}]",
        "{[(a+b)*c]+d}",
        "(a+b]",
        "{a+b)",
        "([a+b)]",
        "{[}]",
        "(){}[]",
        "",
        "abc"};

    for (int i = 0; i < 13; i++)
    {
        cout << "\n"
             << string(50, '=') << endl;
        cout << "Test " << (i + 1) << ": ";

        int result = heterogeneousBracketsValidity(testExpressions[i]);

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

    return 0;
}