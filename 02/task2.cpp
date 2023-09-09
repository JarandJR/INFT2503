#include <cstring>

using namespace std;

// Bad program to run
int main() {
    char *line = nullptr; // eller char *line = 0;
    // It will only be allocated memory space for the pointer line
    // And line point to address space 0
    strcpy(line, "Dette er en tekst");
    // strcpy copies the string to the memory location witch pointer 'line' points to.
    // 'line' is initialized to 'nullptr', this means it does not point to any valid memory location
    // When running the code the program will try to access an invalid memory location,
    // resulting in segmentation fault.

    // For example when running the code, the return address was:
    // "Process finished with exit code -1073741819 (0xC0000005)" instead of 0
}