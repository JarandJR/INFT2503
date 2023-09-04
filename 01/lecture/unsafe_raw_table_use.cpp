#include <iostream>

using namespace std;

int main() {
    int a;
    int b[3];
    double c;

    cout << "a = " << a << ", c = " << c << endl;
    for (int i = 0; i < 5; i++) {
        cout << "i = " << i << " element: " << b[i] << endl;
    }
    return 0;
}