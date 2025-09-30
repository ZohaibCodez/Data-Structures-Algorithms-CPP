#include <iostream>
#include "..\ADT's\Stack\Stack.h"
using namespace std;

int is_anbn(string s)
{
    Stack<char> st;
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
            st.push(s[i]);
        }
        else if (s[i] == 'b' && !st.isEmpty())
        {
            seenB = true;
            st.pop();
        }
        else
        {
            return 0;
        }
        i++;
    }
    return st.isEmpty();
}

int main()
{
    string tests[] = {"", "ab", "aabb", "aaabbb", "aab", "abba", "aaaabb", "abc", "ba", "abab"};

    for (string t : tests)
    {
        cout << "Testing \"" << t << "\" : ";
        if (is_anbn(t))
            cout << "Valid (a^n b^n)\n";
        else
            cout << "Invalid\n";
    }

    return 0;
}
