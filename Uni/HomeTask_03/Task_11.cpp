#include <iostream>
#include <string>
#include "..\ADT's\Stack\Stack.h"
#include <ctype.h>

using namespace std;

template<typename T>
bool isPalindroneWord(T word)
{
    Stack<char> s;
    string temp;
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] != ' ' && word[i] != '-' && word[i] != '.' && word[i] != '?' && word[i] != '!' && word[i] != '\'')
        {
            // cout << i+1 << word[i] << endl;
            if (isupper(word[i]))
            {
                temp += char(tolower(word[i]));
            }
            else
            {
                temp += word[i];
            }
        }
    }
    word = temp;
    int i = 0;
    if (word.length() % 2 != 0)
    {

        for (i = 0; i < (word.length() / 2); i++)
        {
            s.push(word[i]);
        }
        for (int j = i + 1; j < word.length(); j++)
        {
            if (word[j] == s.stackTop())
            {
                s.pop();
            }
        }
        if (s.isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        for (i = 0; i < (word.length() / 2); i++)
        {
            s.push(word[i]);
        }
        for (int j = i; j < word.length(); j++)
        {
            if (word[j] == s.stackTop())
            {
                s.pop();
            }
        }
        if (s.isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    string isPalid = isPalindroneWord("dadd") ? "Palindrone" : "Not a palindrone";
    cout << isPalid;
    return 0;
}