#include <iostream>
#include <string>
#include "..\..\..\ADT's\Stack\Stack.h"
#include <ctype.h>

using namespace std;

bool isInForm(string word)
{
    Stack<char> s;
    int i=0;
    if(word[0] == 'b'){
        return false;
    }
    while(word[i] != '\0'){
        if(word[i] == 'b'){
            if(word[i-1] == 'a' && word[i+1]=='a'){
                return false;
            }
        }
        if(word[i]=='a'){
            s.push(word[i]);
        }
        i++;
    }
    int j=0;
    cout << word.length() << endl;
    while(j< (word.length())){
        if(word[j] == 'b' && !s.isEmpty()){
            s.pop();
        }
        j++;
    }
    if(s.isEmpty()){
        return true;
    }else{
        return false;
    }
}

int main()
{
    string isForm = isInForm("aaaabbbba") ? "In the form" : "Not in the form";
    cout << isForm;
    return 0;
}