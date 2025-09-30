#include <iostream>
#include <string>
#include "..\ADT's\Stack\Stack.h"

using namespace std;

int heterogeneousBracketsValidation(string expression)
{
    Stack<char> s;
    int i = 0;

    cout << "\nChecking: " << expression << endl;

    while (expression[i] != '\0')
    {
        char next_character = expression[i];
        cout << "Position " << i << ": character = '" << next_character << "' -> ";
        if (next_character == '(' || next_character == '{' || next_character == '[')
        {
            cout << "bracket found - pushed to stack\n";
            s.push(next_character);
        }
        if (next_character == ')' || next_character == '}' || next_character == ']')
        {
            if (s.isEmpty())
            {
                return 0;
            }
            char stackTop = s.pop();
            if (stackTop == '(' && next_character != ')')
            {
                cout << "Extra Opening '(' bracket found." << endl;
                return 0;
            }
            if (stackTop == '{' && next_character != '}')
            {
                cout << "Extra Opening '{' bracket found." << endl;
                return 0;
            }
            if (stackTop == '[' && next_character != ']')
            {
                cout << "Extra Opening '[' bracket found." << endl;
                return 0;
            }
            cout << "Opening bracket match from stack\n";
        }
        i++;
    }
    cout << "Finished scanning. Checking final stack state...\n";

    if (s.isEmpty())
    {
        cout << "Stack is empty - return 1 (VALID) \n";
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
        "(a+b)",         // Valid - simple parentheses
        "{a+b}",         // Valid - simple braces
        "[a+b]",         // Valid - simple square brackets
        "({a+b})",       // Valid - nested different types
        "[(a+b)*{c+d}]", // Valid - multiple nested
        "{[(a+b)*c]+d}", // Valid - complex nesting
        "(a+b]",         // Invalid - mismatched types
        "{a+b)",         // Invalid - mismatched types
        "([a+b)]",       // Invalid - wrong closing order
        "{[}]",          // Invalid - interleaved
        "(){}[]",        // Valid - all types empty
        "",              // Valid - empty string
        "abc"            // Valid - no brackets
    };

    for (int i = 0; i < 13; i++)
    {
        cout << "\n"
             << string(50, '=') << endl;
        cout << "Test " << (i + 1) << ": ";

        int result = heterogeneousBracketsValidation(testExpressions[i]);

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