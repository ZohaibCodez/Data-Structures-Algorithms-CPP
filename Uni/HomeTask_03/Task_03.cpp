#include <iostream>
#include "..\ADT's\Stack\Stack.h"
using namespace std;

int is_asbt(string s)
{
    Stack<char> stack;
    bool seenB = false;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == 'a')
        {
            if (seenB)
            {
                return 0;
            }
            stack.push(s[i]);
        }
        else if (s[i] == 'b' && !stack.isEmpty())
        {
            seenB = true;
        }
        else
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main()
{
    string tests[] = {"", "aaa", "bbb", "aaaaabbb", "ab", "aabbaa", "aba", "abc"};

    for (string t : tests)
    {
        cout << "Testing \"" << t << "\" : ";
        if (is_asbt(t))
            cout << "Valid (a^s b^t)\n";
        else
            cout << "Invalid\n";
    }

    return 0;
}
