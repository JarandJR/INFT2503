#include <iostream>

using namespace std;

int main() {
    int a = 5; // This is OK
    cout<< "a: " << a << endl;

    //int &b; // Can not reference a value that is not initialized
    int &b = a; // This is OK. b is now a reference to a
    cout<< "&b: " << &b << ", &a: " << &a << endl;

    int *c; // Instantiates a pointer. This is OK
    cout<< "c: " << c << endl;

    c = &b; // Sets the pointing address to the address a in this example.
            // This is OK.
    cout<< "c: " << c << endl;

    //*a = *b + *c; // a is not a pointer, but a value.
                    // b is not a pointer, but a reference.
                    // c is a pointer and gives no error here
    a = b + *c; // This is OK. a = 5 + 5 = 10
    cout<< "a: " << a << endl;

    //&b = 2; // Can not assign a reference a value
    b = 2; // This is OK. Sets the value of a = 2 since b is a reference to a
    cout<< "b: " << b << ", a: " << a << endl;

    cout<< "Compiles :)" << endl;
}