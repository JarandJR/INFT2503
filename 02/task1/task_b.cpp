#include <iostream>

int i = 3;
int j = 5;
int *p = &i; // point to same memory location as variable i
int *q = &j; // point to same memory location as variable j

int main() {
    *p = 7; // i = 7, and p still points to the same address
    *q += 4; // j += 4 --> j = 9, and q still points to the same address point
    *q = *p + 1; // j = i + 1 --> j = 8, and q still point to the same address point
    p = q; // p now point to the same address point as q, which is the address point of j = 8
    std::cout << "*p value: " << *p << ", *q value: "  << *q << std::endl;

    return 0;
}