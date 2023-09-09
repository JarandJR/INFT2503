#include <iostream>

using namespace std;

void simple_ref_example();

int main() {
    int number;
    int number2 = 3;

    int const *pointer = &number; // Konstant peker, kan ikke endre verdien, men kan endre det den peker til
    pointer = &number2; // lov
    //*pointer = 4; // ikke lov

    int *const pointer2 = &number; // Konstant peker, kan ikke endre hva den peker til, men kan endre verdi
    //pointer2 = &number2; // ikke lov
    *pointer2 = 6; // lov

    const int *const pointer3 = &number; // Konstan peker, kan ikke endre verdie eller hva den peker til
    // pointer3 = &number2; // ikke lov
    // *pointer3 = 7; // ikke lov

    cout << "Pointer 1: " << pointer << " value: " << *pointer << " = number2: " << number2 << endl;
    cout << "Pointer 2: " << pointer2 << " value: " << *pointer2  << " = number1: " << number << endl;
    cout << "Pointer 3: " << pointer3 << " value: " << *pointer3  << " = number1: " << number << endl;

    simple_ref_example();

    return 0;
}

void simple_ref_example() {
    int number;
    int &ref = number; // peker til samme plass i minnet
    ref = 6;
    number++; // begge vil ende med en verdi på 7
    cout << "Ref: " << ref << " Number: " << number << endl;
}
