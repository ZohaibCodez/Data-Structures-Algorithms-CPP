#include <iostream>

using namespace std;

int number_of_digits(int number)
{
    if (number == 0)
    {
        return 0;
    }
    else
    {
        return 1 + number_of_digits(number / 10);
    }
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << number_of_digits(number);
    return 0;
}