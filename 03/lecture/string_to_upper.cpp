#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cout << R"(Write a word and press "Enter". Quit with "x":)" << endl;
    cin >> word; // Vi leser ordet inn i et string-objekt

    // Vi kan bruke sammenligningsoperatorene for å sammenligne
    // innholdet i streng-objektene. (For å sammenligne strenger
    // som er lagret i char-tabeller må vi bruke strcpy(), dersom
    // vi bruker operatorene da, vil vi sammenligne adressene, og
    // det er sjelden meningen!)
    while (word != "x" && word != "X") {
        cout << word;
        for (char & i : word) {
            i = toupper(i);
        }
        cout << " to upper: " << word << endl;
        cin >> word;
    }
}
