#ifndef INC_07_SET_H
#define INC_07_SET_H

#include <vector>
#include <iostream>

class Set {
public:
    std::vector<int> list;
    // Create new empty list
    Set();
    // Add number to list
    Set &operator+=(int integer);
    // Set list to other list
    Set &operator=(const Set& other);
    // Print list
    friend std::ostream &operator<<(std::ostream &out, const Set &set);
    // Union of list
    Set operator+(const Set &other);
private:
    // Push number to the end of list
    void push_back(int i);
};

#endif //INC_07_SET_H
