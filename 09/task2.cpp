#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;
    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    auto e = equal(
            v1.begin(),
            v1.begin() + 5,
            v2.begin(),
            [](int a, int b) -> bool {return abs(a - b) <= 2;}
            );
    cout << "Comparing the first 5 numbers to be equal are not: " << e << endl;

    e = equal(
            v1.begin(),
            v1.begin() + 4,
            v2.begin(),
            [](int a, int b) -> bool {return abs(a - b) <= 2;}
            );
    cout << "Comparing the first 4 numbers to be equal are not: " << e << endl;

    return 0;
}