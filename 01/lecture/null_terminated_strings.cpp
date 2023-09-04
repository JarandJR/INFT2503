#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char text[5];
    cout << "Write a word: ";
    cin >> text;

    for (size_t i = 0; i < strlen(text); i++) {
        text[i] = toupper(text[i]);
    }
    cout << "Only in upper case: " << text << endl;
    
    for (size_t j = 0; j < strlen(text); j++) {
            text[j] = tolower(text[j]);
    }
    cout << "Only in lower case: " << text << endl;

    return 0;
}