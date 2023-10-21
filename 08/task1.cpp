#include <iostream>

using namespace std;

template <typename Type>
bool equal(Type a, Type b) {
    cout << "Generic-case Type" << endl;
    return a == b;
}

bool equal(double a, double b) {
    cout << "Special-case double" << endl;
    return abs(a-b) < 0.00001;
}

int main() {
    cout << "Task 1" << endl << endl;
    cout << "Equals checker:" << endl << endl;

    cout << "1, and 4" << endl;
    cout << equal(1, 4) << endl << endl;

    cout << "true and true" << endl;
    cout << equal(true, true) << endl << endl;

    cout << "1.2 and 1.4" << endl;
    cout << equal(1.2, 1.4) << endl << endl;

    cout << "1.000001 and 1.000002" << endl;
    cout << equal(1.000001, 1.000002) << endl;
    return 0;
}