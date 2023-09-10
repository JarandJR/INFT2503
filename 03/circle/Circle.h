#pragma once

class Circle {
    public:
        explicit Circle(double radius_);
        double get_area() const;
        double get_circumference() const;
    private:
        double radius;
        const double pi = 3.141592;
};
