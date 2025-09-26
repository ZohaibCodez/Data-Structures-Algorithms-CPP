#include <iostream>
#include <string>
#include "..\..\..\ADT's\Stack\Stack.h"

void addingLargeNumbers(string firstNumber, string secondNumber)
{
    Stack<char> s1;
    Stack<char> s2;
    Stack<char> result;
    int i = 0, j = 0, carry = 0;
    while (firstNumber[i] != '\0')
    {
        s1.push(firstNumber[i]);
        i++;
    }
    i = 0;
    while (secondNumber[i] != '\0')
    {
        s2.push(secondNumber[i]);
        i++;
    }
    int sum = 0;
    int left = 0, right = 0;
    while ((!s1.isEmpty()) || (!s2.isEmpty()) || carry)
    {
        sum = 0;
        if (!s1.isEmpty())
        {
            sum += (s1.pop() - '0');
        }
        if (!s2.isEmpty())
        {
            sum += (s2.pop() - '0');
        }
        sum += carry;
        result.push(char('0' + (sum % 10)));
        carry = sum / 10;
    }
    if (carry != 0)
    {
        result.push(char('0' + carry));
    }
    while (!result.isEmpty())
    {
        cout << result.pop();
    }
}

int main()
{
    addingLargeNumbers("5", "32976");
    return 0;
}