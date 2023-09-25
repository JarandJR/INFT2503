#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

int main() {
    cout << "Task 1" << endl << "--------------------------" << endl << endl;
    vector<double> vec{1,2,3,4,5};

    cout << "Element[0]: " << vec[0] << endl;
    cout << "Front: " << vec.front() << endl;
    cout << "Back: " << vec.back() << endl << endl;

    vec.emplace(vec.begin(), 10.);
    cout << "Emplace 10. ..." << endl;
    cout << "New front: " << vec.front() << endl << endl;

    auto it = std::find(vec.begin(), vec.end(), 2);
    if ( it != vec.end()) {
        cout << "Found the number 2 in the list! Value found: " << *it << endl;
    }
}
