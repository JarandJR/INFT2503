#include <iostream>

using namespace std;

int table_length = 20;

int find_sum(const int *table, int length);

int main() {
    int table[table_length];
    cout << "Start table: ";
    for (int i = 0; i < table_length; ++i) {
        table[i] = i + 1;
        cout << table[i] << ", ";
    }
    cout << endl;

    int length1 = 10;
    int length2 = 5;
    cout << "Sum of the 10 first numbers: " << find_sum(table, length1) << endl;
    cout << "Sum of the 5 first numbers: " << find_sum(&table[table_length - length1], length2) << endl;
    cout << "Sum of the 5 last numbers: " << find_sum(table + (table_length - length2), length2) << endl;
}

int find_sum(const int *table, int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += *table++;
    }
    return sum;
}