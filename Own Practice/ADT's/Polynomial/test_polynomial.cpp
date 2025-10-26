#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{
    Polynomial p(2);

    p.addTerm(3, 2); // 3x^2
    p.addTerm(5, 0); // + 5
    p.addTerm(2, 1); // + 2x

    cout << "Degree: " << p.getDegree() << endl;             // Expect 2
    cout << "Coeff of x^1: " << p.getCoefficient(1) << endl; // Expect 2
    cout << "Coeff of x^3: " << p.getCoefficient(3) << endl; // Expect 0
    cout << "Evaluation at x=2: " << p(2) << endl;           // Expect 3*(2^2)+2*(2)+5 = 21

    Polynomial q = p;                                     // test copy constructor
    cout << "Copied Polynomial at x=2: " << q(2) << endl; // Expect 21

    Polynomial r;
    r = p;                                                  // test assignment operator
    cout << "Assigned Polynomial at x=3: " << r(3) << endl; // Expect 3*(3^2)+2*(3)+5 = 38

    return 0;
}
