#include <algorithm> // header-fil for algoritmer
#include <iostream>
#include <vector> // header-fil for vector
using namespace std;

int main() {
    vector<int> numbers; // oppretter en vektor av heltall
    int number;
    cout << "Skriv positive tall (avslutt med 0): ";
    cin >> number;

    while (number > 0) {
        numbers.emplace_back(number); // legger inn det nye tallet bakerst
        cin >> number;
    }

    cout << "Du har skrevet " << numbers.size() << " tall" << endl;
    for (int n : numbers) {
        cout << n << " "; // henter ut et og et tall ved indeksering
    }
    cout << endl;
}
