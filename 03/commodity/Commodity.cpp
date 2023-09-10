#include "Commodity.h"

#include <utility>

const double tax = 1.25;

Commodity::Commodity(int id, string name, double price) : id(id), name(std::move(name)), price(price) {}

int Commodity::get_id() const {
    return id;
}

string Commodity::get_name() {
    return name;
}

double Commodity::get_price() const {
    return price;
}

void Commodity::set_price(double new_price) {
    price = new_price;
}

double Commodity::get_price(double quantity) const {
    return price * quantity;
}

double Commodity::get_price_with_sales_tax(double quantity) const {
    return price * tax * quantity;
}
