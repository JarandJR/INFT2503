#include <iostream>

int main() {
    double table[5];
    double *pointer;
    pointer = table; // pointer peker til table[0]
    *pointer = 1.1; // table[0] får verdien 0.0
    *(pointer + 1) = *pointer; // table[1] får samme verdi som table[0]
    pointer++; // pointer peker til table[1]

    std::cout << "Pointer should have value 1.1 = " << *pointer << std::endl;


    const int m = 5;
    int ints[m];
    double floats[m];
    std::cout << "Int addresses:\n";
    // Adressene skrives ut på heksadesimal form.
    for (int i = 0; i < m; i++)
        std::cout << (ints + i) << std::endl;
    /*
     * Vi ser at adressene endrer seg med 4 for
     * hver gang i øker med 1. En variabel av
     * typen int legger beslag på 4 byte.
     * */

    std::cout << "\nDouble addresses:\n";
    for (int i = 0; i < m; i++)
        std::cout << (floats + i) << std::endl;
    /*
     * En variabel av typen double legger beslag
     * på 8 byte. Dermed øker adressen med 8 hver
     * gang i øker med 1.
     */

    return 0;
}