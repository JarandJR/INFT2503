#pragma once

#include <string>

using namespace std;

class Surface {
public:
    Surface(string name_, double length_, double width_);
    const string &get_name() const;
    double get_length() const;
    double get_width() const;
    double get_area() const;
    double get_circumference() const;
private:
    string name;
    double length{};
    double width{};
};
