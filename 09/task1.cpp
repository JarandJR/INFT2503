#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

void task(vector<int> v1) {
    auto pos = find_if(
            v1.begin(),
            v1.end(),
            [](int i)-> bool {return i > 15;}
    );
    cout << "Find the first element that is greater than 15:" << endl;
    if (pos != v1.end())
        cout << "Element found at index: " << pos - v1.begin() << ", element: " << *pos << endl;
    else
        cout << "Could not find an element greater than 15" << endl;
    cout << endl;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;

    task(v1);

    v1.resize(v1.size() - 3);
    cout << "v1: " << v1 << endl;
    task(v1);

    return 0;
}