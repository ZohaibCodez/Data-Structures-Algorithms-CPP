#include <iostream>
#include "..\..\ADT's\Stack\Stack.h"

using namespace std;

int dec2oct(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return dec2oct(n / 8) * 10 + (n % 8);
    }
}

int main()
{
    int n = 69;
    cout << "Octal equivalent of " << n << " is: " << dec2oct(n) << endl;
    n = 389;
    cout << "Octal equivalent of " << n << " is: " << dec2oct(n);
    return 0;
}