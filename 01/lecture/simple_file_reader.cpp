#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    const char filename[] = "simple_File.txt";
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "Something went wrong when trying to open in-file" << endl;
        exit(EXIT_FAILURE);
    }

    int number;
    int sum = 0;
    while (file >> number) {
        sum += number;
    }
    cout << "The sum: " << sum << endl;
    file.close();    

    return 0;
}