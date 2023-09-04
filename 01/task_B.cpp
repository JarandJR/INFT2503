#include <iostream>
#include <fstream>

using namespace std;

const int length = 5;

const int HIGH = 20;
const int LOW = 10;

void read_temperatures(double temps[], int length);
void count_temperatures(double temps[]);

int main() {
    double temperatures[length];
    read_temperatures(temperatures, length);
    count_temperatures(temperatures);
    return 0;
}

void read_temperatures(double temps[], int length) {
    const char filename[] = "temperatures.txt";
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "Something went wrong when trying to open in-file" << endl;
        exit(EXIT_FAILURE);
    }

    int i = 0;
    double temp;
    while (file >> temp) {
        temps[i++] = temp;
    }
    file.close();
}

void count_temperatures(double temps[]) {
    int high = 0;
    int low = 0;

    for (int i = 0; i < length; i++) {
        if (temps[i] > HIGH) {
            high++;
        } else if (temps[i] < LOW) {
            low++;
        }
    }
    cout << endl << "Temperature lower then " << LOW << ": " << low << endl;
    cout << "Temperature inbetween " << LOW << " and " << HIGH << ": " << length - low - high << endl;
    cout << "Temperature higher then " << HIGH << ": " << high << endl;
}