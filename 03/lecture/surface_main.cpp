#include <iostream>
#include "Surface.h"

using namespace std;

int main() {
    Surface floor("My floor", 20.0, 20.0);
    double cir = floor.get_circumference();
    cout << "Circumference: " << cir << endl;
    cout << "Area: " << floor.get_area() << endl;
}