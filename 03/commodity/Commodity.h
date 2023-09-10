#include <string>

using namespace std;

class Commodity {
private:
    int id;
    string name;
    double price;

public:
    Commodity(int id, string name, double price);
    string get_name();
    int get_id() const ;
    double get_price() const;
    void set_price(double price);
    double get_price(double quantity) const;
    double get_price_with_sales_tax(double quantity) const;
};

