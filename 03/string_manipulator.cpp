#include <iostream>
#include <string>

using namespace std;

// Task 4
int main() {
    // a)
    cout << "Write 3 words: " << endl;
    string word1, word2, word3;
    cin >> word1 >> word2 >> word3;

    cout << endl << "The words registered:" << endl << endl
    << "1: " + word1 + " 2: " << word2 + " 3: " << word3 << endl;
    cout << "-------------------------------------------" << endl << endl;

    // b)
    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << "A sentence of the words: " << endl << endl << "\"" <<sentence << "\"" << endl;
    cout << "-------------------------------------------" << endl << endl;

    // c)
    cout << "The length of the words:" << endl << endl
    << "word1: " << word1.length() << endl
    << "word2: " << word2.length() << endl
    << "word3: " << word3.length() << endl
    << "sentence: " << sentence.length() << endl
    << "-------------------------------------------" << endl << endl;

    // d)
    string sentence2 = sentence;
    cout << "sentence1 copied to sentence2: " << endl << endl;
    cout << "sentence1: " << sentence << endl;
    cout << "sentence2: " << sentence2 << endl
    << "-------------------------------------------" << endl << endl;

    // e)
    for (int i = 9; i < 12; ++i) {
        if (sentence2.length() >= i + 1) {
            sentence2[i] = 'X';
        }
    }
    cout << "sentence2 possibly changed..." << endl << endl;
    cout << "sentence1: " << sentence << endl;
    cout << "sentence2: " << sentence2 << endl << endl;
    cout << "-------------------------------------------" << endl << endl;

    // f)
    cout << "Making a substring of the 5 first chars..." << endl << endl;
    if (sentence.length() > 5) {
        string sentence_start = sentence.substr(0, 5);
        cout << "sentence_start: " << sentence_start << endl;
        cout << "sentence: " << sentence << endl << endl;
    }
    cout << "-------------------------------------------" << endl << endl;

    // g)
    cout << "Finding \"hallo\" in sentence..." << endl << endl;
    if (sentence.find("hallo") != string::npos) {
        size_t found_index = sentence.find("hallo");
        cout << "Found \"hallo\" at index: " << found_index << endl;
        cout << "sentence: " << sentence << endl;
    } else {
        cout << "Could not find the word \"hallo\"" << endl;
    }
    cout << "-------------------------------------------" << endl << endl;

    // h)
    cout << "Finding substring \"er\" in sentence..." << endl << endl;
    string substring = "er";
    size_t i = 0;

    cout << "sentence: " << sentence << endl;
    while ((i = sentence.find(substring, i)) != string::npos) {
        cout << "Found substring \"" << substring << "\" at position: " << i << endl;
        i++;
    }
    cout << "-------------------------------------------" << endl;
}