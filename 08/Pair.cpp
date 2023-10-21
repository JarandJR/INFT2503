#include <iostream>

using namespace std;

template <typename A, typename B>
class Pair {
public:
    A first;
    B second;
    Pair(A first, B second) : first(first), second(second) {}

    Pair operator+(const Pair &other) {
        return Pair(first + other.first, second + other.second);
    }

    bool operator>(const Pair &other) {
        return (first + second) > (other.first + other.second);
    }

    friend ostream &operator<<(ostream &os, const Pair &pair) {
        return os << "(" << pair.first << ", " << pair.second << ")";
    }
};
