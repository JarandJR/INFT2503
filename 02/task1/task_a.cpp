#include <iostream>

int i = 3;
int j = 5;
int *p = &i; // point to same memory location as variable i
int *q = &j; // point to same memory location as variable j

int main() {
    std::cout << "i_value: " << i << ", address: " << &i << std::endl;
    std::cout << "*p_value: " << *p << ", address: " << p << std::endl;
    std::cout << "j_value: " << j << ", address: " << &j << std::endl;
    std::cout << "*q_value: " << *q << ", address: " << q << std::endl;

    return 0;
}