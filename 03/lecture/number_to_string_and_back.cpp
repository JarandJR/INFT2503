#include <iostream>
#include <sstream>

using namespace std;

string number_to_string(int number) {
    ostringstream oss;
    oss << number;
    return oss.str();
}

void to_number() {
    istringstream iss;
    int int_number;
    double double_number;

    iss.str("10 12.5");
    iss >> int_number;
    iss >> double_number;

    cout << "int_number: "
         << int_number << ", double_number: "
         << double_number << endl;
}

int main() {
    to_number();
    int number = 12;
    cout << "Number as string: " <<
    to_string(number) <<
    " , or " << number_to_string(number) << endl;
}