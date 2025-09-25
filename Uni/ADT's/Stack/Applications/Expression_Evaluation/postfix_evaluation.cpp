#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include "../../Stack.h"
using namespace std;

// Function to check if character is an operand
bool isOperand(char c)
{
    return isdigit(c); // For simplicity, using single digit numbers
}

// Function to check if character is an operator
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '$';
}

// Function to perform operation
int performOperation(int operand1, int operand2, char operator_char)
{
    switch (operator_char)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 == 0)
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return operand1 / operand2;
    case '%':
        if (operand2 == 0)
        {
            cout << "Error: Division by zero in modulo!" << endl;
            return 0;
        }
        return operand1 % operand2;
    case '^':
    case '$':
        return (int)pow(operand1, operand2);
    default:
        cout << "Error: Unknown operator " << operator_char << endl;
        return 0;
    }
}

// Postfix Expression Evaluation
// Input = postfix string
// Output = result of postfix expression
int postfixExpressionEvaluation(string postfix_string)
{

    // Create a stack that can store operands in it
    Stack<int> stack;

    // While (Scan the postfixstring from left to right till the end)
    for (int i = 0; i < postfix_string.length(); i++)
    {

        // get next_character from postfix_string
        char next_character = postfix_string[i];

        // if (next_character is operand)
        if (isOperand(next_character))
        {
            // push next_character into stack
            int operand_value = next_character - '0'; // Convert char digit to int
            stack.push(operand_value);
        }
        // else if (next_character is operator)
        else if (isOperator(next_character))
        {
            // operand2 = pop operand from stack
            int operand2 = stack.pop();

            // operand1 = pop operand from stack
            int operand1 = stack.pop();

            // Perform operation on the operand1 and operand2 depending on the operator
            int result = performOperation(operand1, operand2, next_character);

            // Push the result of this operation in stack
            stack.push(result);
        }
    }

    // Pop the result of "Postfix Expression Evaluation" from stack
    return stack.pop();
}

int main() {
    cout << "=== Postfix Expression Evaluation (Following Teacher's Pseudocode) ===\n";
    
    string testExpressions[] = {
        "23+",              // 2 + 3 = 5
        "23*",              // 2 * 3 = 6
        "23*4+",            // 2*3 + 4 = 10
        "234*+",            // 2 + 3*4 = 14
        "23+4*",            // (2+3) * 4 = 20
        "234+-",            // 2 + 3 - 4 = 1
        "15/",              // 1 / 5 = 0 (integer division)
        "52/",              // 5 / 2 = 2 (integer division)
        "23^",              // 2 ^ 3 = 8
        "234*+5-"           // 2 + 3*4 - 5 = 9
    };

    for (int i = 0; i < 10; i++) {
        cout << "\n" << string(50, '=') << endl;
        cout << "Test " << (i + 1) << ": " << testExpressions[i];
        
        int result = postfixExpressionEvaluation(testExpressions[i]);
        
        cout << "\nFINAL RESULT: " << result << endl;
    }
    
    return 0;
}