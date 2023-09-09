#include <iostream>

// Bad program to run
int main() {
    char text[5]; // Allocates space for 5 chars in memory
    char *pointer = text; // Defines a pointer that points to the first element of the table, text[0]
    char search_for = 'e'; // Defines the character being search for
    std::cin >> text; // Takes user-input and writes it to the table text
    std::cout << "Start: Text: " << text << std::endl;
    while (*pointer != search_for) { // Run's until it finds the char being searched for
        std::cout << "Text1: " << text << std::endl;
        std::cout << "Pointer value1: " << *pointer << std::endl << std::endl;

        *pointer = search_for; // Sets the value of the where the pointer is pointing to,
                               // to be the char being searched for
        // First iteration: *pointer = search_for --> text[0] = 'e'

        std::cout << "Text2: " << text << std::endl;
        std::cout << "Pointer value2: " << *pointer << std::endl << std::endl;

        pointer++; // Goes to the next element in the table: text[0++] --> text[1]

        std::cout << "Text3: " << text << std::endl;
        std::cout << "Pointer value3: " << *pointer << std::endl << std::endl;
    }
}

/**
* There is a couple of things that can go wrong here in this code and lead to undesirable behavior or errors
 *
 * 1. A buffer overflow can happen if the user inputs a word that is longer than 5 characters
 * This will result in overwriting potentially something important, like the return address
 *
 * 2. The program will exit once it finds the char 'e'.
 * Meaning if 'e' is the first character in the word, the program will just exit immediately
 *
 * 3. The values of the word being checked for containing 'e' is being changed throughout the iteration.
 * On line 13: "*pointer = search_for" changes the char of witch the pointer is at to the char "search_for"
 * Meaning in the first iteration: text[0] = 'e'
 * And so on
 *
 * 4. If the word that the user inputs does not contain an 'e'
 * the program would iterate over memory outside of the char text[5] and overwriting it like above
 * Memory location text[5] = 'e'. We don't know what is stored on that memory location
 * and don't want to change it's value like this program is doing
*/