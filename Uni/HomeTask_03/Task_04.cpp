#include <iostream>
#include "..\ADT's\Stack\Stack.h"
using namespace std;

int is_anbncn(string s)
{
    Stack<char> st1;
    Stack<char> st2;
    bool seenB = false;
    bool seenC = false;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == 'a')
        {
            if (seenB || seenC)
            {
                return 0;
            }
            st1.push(s[i]);
        }
        else if (s[i] == 'b' && !st1.isEmpty())
        {
            if (seenC)
            {
                return 0;
            }
            seenB = true;
            st1.pop();
            st2.push(s[i]);
        }
        else if (s[i] == 'c' && !st2.isEmpty())
        {
            seenC = true;
            st2.pop();
        }
        else
        {
            return 0;
        }
        i++;
    }
    return st1.isEmpty() && st2.isEmpty();
}

int main()
{
    string tests[] = {
        "", "abc", "aabbcc", "aaabbbccc", "aaaaabbbbbccccc", // valid
        "aabbbccc", "aaabbccc", "aaabbbbccc", "aabbc", "aabcc", // invalid
        "acb", "aabbccaa", "xyz", "aaaa", "bbbccc", "abcc" // tricky
    };

    for (string t : tests) {
        cout << "Testing \"" << t << "\" : ";
        if (is_anbncn(t))
            cout << "Valid (a^n b^n c^n)" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}
