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
    replace_copy_if(
            v1.begin(),
            v1.end(),
            v1.begin(),
            [](int i) -> int {return i%2 != 0;},
            100
            );
    cout << "Odd numbers replaced with 100" << endl;
    cout << "v1: " << v1 << endl;

    return 0;
}