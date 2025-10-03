#include <iostream>
#include <sstream>
#include <string>
#include "..\..\ADT's\Stack\Stack.h"

using namespace std;

string reverseWords(string str)
{
    Stack<string> st;
    string word;
    stringstream ss(str);

    while (ss >> word)
    {
        Stack<char> charSt;
        int i = 0;
        while (word[i] != '\0')
        {
            charSt.push(word[i]);
            i++;
        }
        string resultedWord;
        while (!charSt.isEmpty())
        {
            resultedWord += charSt.pop();
            // if(!charSt.isEmpty()){
            //     resultedWord+=
            // }
        }
        st.push(resultedWord);
    }

    string result = "";
    int count = 0;
    while (!st.isEmpty())
    {
        result += st.stackTop();
        st.pop();
        if (!st.isEmpty())
            result += " ";
        count++;
    }
    Stack<string> st2;
    string WORD;
    stringstream ss2(result);

    while (ss2 >> WORD)
    {
        st2.push(WORD);
    }

    string FINALresult = "";
    while (!st2.isEmpty())
    {
        FINALresult += st2.stackTop();
        st2.pop();
        if (!st2.isEmpty())
            FINALresult += " ";
    }

    return FINALresult;
}

int main()
{
    string s = "Welcome to DSA";
    cout << reverseWords(s) << endl;
    return 0;
}