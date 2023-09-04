#include <climits>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    const char filename[] = "./power_of_two.txt";
    ofstream file;
    file.open(filename);
    if (!file) {
        cout << "Something went wrong when opening of out file" << endl;
        exit(EXIT_FAILURE);
    }
    long int product = 1L;
    int exponent = 0;
    while (product <= LONG_MAX / 2L) {
        exponent++;
        product *= 2L;
        file << "2 to the power of " << setw(4) << exponent << " = " << product << endl;
    }
    file.close();
    
    return 0;
}