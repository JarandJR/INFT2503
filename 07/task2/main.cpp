#include <iostream>
#include "Set.h"

using namespace std;

int main() {
    Set set;
    cout << "New empty set" << endl;
    cout << set << endl;

    set += 3;
    cout << "Adds number 3 to set" << endl;
    cout << set << endl;

    set += 42;
    cout << "Adds number 42 to set" << endl;
    cout << set << endl;

    Set other;
    other += 2;
    other += 3;
    cout << "Created new set called other" << endl;
    cout << "Other: " << other << endl;

    Set union_set = other + set;
    cout << "The union of set and the other set" << endl;
    cout << "Union set: " << union_set << endl;

    set = other;
    cout << "Setting set to be equal to the other set" << endl;
    cout << "Other: " << other;
    cout << set;

    return 0;
}