#include <iostream>

using namespace std;

const int length = 5;

const int HIGH = 20;
const int LOW = 10;

void get_temperatures();

int main() {
    get_temperatures();
    return 0;
}

void get_temperatures() {
    int high = 0;
    int low = 0;

    double temperature;
    cout << "Write " << length << " numbers" << endl;
    for (int i = 0; i < length; i++) {
        cout << "Temperature " << i+1 << ": ";
        cin >> temperature;

        if (temperature > HIGH) {
            high++;
        } else if (temperature < LOW) {
            low++;
        }
    }
    cout << endl << "Temperature lower then " << LOW << ": " << low << endl;
    cout << "Temperature inbetween " << LOW << " and " << HIGH << ": " << length - low - high << endl;
    cout << "Temperature higher then " << HIGH << ": " << high << endl;
}