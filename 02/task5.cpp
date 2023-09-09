#include <iostream>

using namespace std;

int main() {
    double number;
    // Definer en peker som skal peke til number .
    double *pointer = &number;

    // Definer en referanse som skal referere til number .
    double &ref = number;

    // Vis tre måter å få tilordnet verdi til number på.
    cout << "Number: " << number << endl;
    *pointer += 2.1;
    cout << "Number: " << number << endl;
    ref += 3.2;
    cout << "Number: " << number << endl;
    number += 1.1;
    cout << "Number: " << number << endl;
}