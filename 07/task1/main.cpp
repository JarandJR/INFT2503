#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
    cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
    Fraction a(10, 20);
    Fraction b(3, 4);
    Fraction c;
    c.set(5);
    Fraction d = a / b;
    print("a = ", a);
    print("b = ", b);
    print("c = ", c);
    print("d = ", d);
    b += a;
    ++c;
    d *= d;
    print("b = ", b);
    print("c = ", c);
    print("d = ", d);
    c = a + b - d * a;
    c = -c;
    print("c = ", c);
    if (a + b != c + d)
        cout << "a + b != c + d" << endl;
    else
        cout << " a + b == c + d" << endl;
    while (b > a)
        b -= a;
    print("b = ", b);

    cout << endl << "a)" <<endl;
    print("d = ", d);
    cout << endl << "d = 1 - d" << endl;
    d = 1 - d;
    print("d = ", d);
    cout << endl << "d = d - 2" << endl;
    d = d - 2;
    print("d = ", d);

    cout << endl << "b)" <<endl;
    print("a = ", a);
    print("b = ", b);

    d = (((5 - 3) - b) - 7) - a;
    c = 5 - 3 - b - 7 - a;

    cout << endl;
    cout << "d = 5 - 3 - b - 7 - a" << endl;
    print("d = ", d);
    cout << endl << "c = (((5 - 3) - b) - 7) - a" << endl;
    print("c = ", c);

    cout << endl << "check if d == c ->" << endl;
    if (c == d) {
        cout << "Expression calculated from left to right" << endl;
    } else {
        cout << "Expression calculated from right to left" << endl;
    }

    return 0;
}