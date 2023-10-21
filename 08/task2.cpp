#include <iostream>
#include "Pair.cpp"

using namespace std;

int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    if (p1 > p2)
        cout << "p1 is the biggest" << endl;
    else
        cout << "p2 is the biggest" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum << endl;
}
