#include <iostream>

using namespace std;

int main() {
    int number;
    int *pointer = &number;
    *pointer = 6;
    cout << "Number: " << number << ", pointer: " << pointer << ", pointer value: " << *pointer << endl;

    int table[10];
    int *table_pointer= table; //som er det samme som int *pointer= &table[0];

    table[2] = 5;
    table_pointer[3] = 8; // det samme som table[3] = 8
    *table_pointer = 0; // det samme som pointer[0] = 0 og som table[0] = 0
    *table = table[2]; // det samme som table[0] = table[2]

    return 0;
}