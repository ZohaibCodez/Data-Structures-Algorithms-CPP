#include <iostream>
#include <sstream>
#include <string>
#include "..\ADT's\Stack\Stack.h"

using namespace std;

string reverseWords(string str) {
    Stack<string> st;
    string word;
    stringstream ss(str);

    // Extract words and push into stack
    while (ss >> word) {
        st.push(word);
    }

    // Pop words and build result
    string result = "";
    while (!st.isEmpty()) {
        result += st.stackTop();
        st.pop();
        if (!st.isEmpty()) result += " "; // avoid trailing space
    }

    return result;
}

int main() {
    string s = "I love data structures";
    cout << reverseWords(s) << endl;
    return 0;
}