#include <iostream>

using namespace std;

const int max_line_length = 81;

int main() {
    char name[max_line_length];
    char address[max_line_length];
    int age;
    char position[max_line_length];

    cout << "Name: ";
    cin.getline(name, max_line_length);

    cout << "Address: ";
    cin.getline(address, max_line_length);

    cout << "Age: ";
    cin >> age;
    cin.get(); // Removes newline

    cout << "Position: ";
    cin.getline(position, max_line_length);

    cout << endl << name << endl << address << endl << age << endl << position << endl;
    return 0;
}