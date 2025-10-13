#include <iostream>

using namespace std;

int pow(int number, int power)
{
    if (power == 0)
    {
        return 1;
    }
    else
    {
        return number * pow(number, power - 1);
    }
}

int main()
{
    int number, power;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter a power: ";
    cin >> power;
    cout << pow(number, power) << endl;
    return 0;
}