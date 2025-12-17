#include <iostream>
#include <string>
using namespace std;

void evalStr(string str)
{
}

int main()
{
    string str1 = "DACDACCDCBC";
    int strLength = str1.size();
    // string str2 = ""
    int charFreq[26];
    char Char[26];
    for (int i = 0; i < 26; i++)
    {
        charFreq[i] = 0;
    }
    for (int i = 0; i < strLength; i++)
    {
        Char[int(str1[i])-65] = str1[i];
        // cout << int(str1[i])-65 <<  " ";
        charFreq[int(str1[i])-65] += 1;
    }
    int i = 0;
    while(Char[i] != '\0')
    {
        cout << Char[i] << " " << charFreq[i] << endl;
        i++;
    }
    
    return 0;
}