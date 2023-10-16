#include "Set.h"
#include "algorithm"

// Create new empty list
Set::Set() {};

// Add number to list
Set &Set::operator+=(int integer) {
    if (std::find(list.begin(), list.end(), integer) == list.end())
        push_back(integer);
    return *this;
}

// Set list to other list
Set &Set::operator=(const Set& other) {
    list = other.list;
    return *this;
}

// Print list
std::ostream &operator<<(std::ostream &out, const Set &set) {
    out << "Set: {";
    for (auto i : set.list) {
        out << " " << i;
    }
    out << " }" << std::endl;
    return out;
}

// Union of list
Set Set::operator+(const Set &other) {
    Set set = *this;
    for (auto i : other.list) {
        if (std::find(set.list.begin(), set.list.end(), i) == set.list.end())
            set.push_back(i);
    }
    return set;
}

// Push number to the end of list
void Set::push_back(int i) {
    list.push_back(i);
}
