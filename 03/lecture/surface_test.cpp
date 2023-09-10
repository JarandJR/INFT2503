#include <iostream>
#include <string>
#include <utility>

using namespace std;

// ==> Her kommer definisjonen av klassen
class Surface {
    public:
        Surface(string name_, double length_, double width_);
        const string &get_name() const;
        double get_length() const;
        double get_width() const;
        double get_area() const;
        double get_circumference() const;
    private:
        string name; // til identifikasjon
        double length;
        double width;
};

// ==> Her kommer implementasjonen av klassen
Surface::Surface(string name_, double length_, double width_)
        : name(std::move(name_)), length(length_), width(width_) {}

const string &Surface::get_name() const {
    return name;
}
double Surface::get_length() const {
    return length;
}
double Surface::get_width() const {
    return width;
}
double Surface::get_area() const {
    return width * length;
}
double Surface::get_circumference() const {
    return 2 * (length + width);
}
//
// Dette er et program som tester klassen Flate .
// Vi tester klassen ved å opprette et objekt av klassen.
// Deretter henter vi ut dataene fra objektet og skriver disse ut,
// slik at vi kan se at objektet virkelig inneholder
// de dataene vi puttet inn, og at det gjør sine beregninger riktig.
//
int main() {
// Trinn 1: Lager et objekt av klassen.
    Surface floor("Torils golv", 4.8, 2.3);
// Trinn 2: Henter ut data og får utført beregninger på objektet
    const string& name = floor.get_name();
    double width = floor.get_width();
    double length = floor.get_length();
    double area = floor.get_area();
    double circumference = floor.get_circumference();
// Trinn 3: Skriver ut resultatene slik at de kan kontrolleres
    cout << "Data om golvet med navn: " << name << ":" << endl;
    cout << "Bredde: " << width << endl;
    cout << "Lengde: " << length << endl;
    cout << "Areal: " << area << endl;
    cout << "Omkrets: " << circumference << endl;
}