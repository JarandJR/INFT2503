#include <iostream>
#include <memory> // For unique_ptr

using namespace std;

class A {
public:
    A() {
        cout << "Objektet blir opprettet" << endl;
    }
    ~A() {
        cout << "Objektet blir slettet" << endl;
    }
};
int main() {
    {
        unique_ptr<A> a(new A()); // Et objekt opprettes på heapen, som a peker til
                                    // Når a slettes, frigjøres også det anonyme objektet
    }
    cout << "Scopet er avsluttet" << endl;
}
