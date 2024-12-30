#include "DiscVintage.h"

int DiscVintage::nrDiscVintage = 0;

DiscVintage::DiscVintage(string name, float price, bool mint, int rarity):Produs{name, price}, isMint{mint}, coefRaritate{rarity} {};

void DiscVintage::addDiscVintage(int quant) {
    nrDiscVintage += quant;
}

int DiscVintage::getNrDiscVintage() {
    return nrDiscVintage;
}

string DiscVintage::getTip() const {
    return "DISC VINT.";
}


float DiscVintage::getPretTotal() const {
    return (pretBaza + 5 + 15 * coefRaritate);
}

void DiscVintage::afisare() const {
    Produs::afisare();
    cout << ", ";
    if (isMint)
        cout << "este mint, ";
    else
        cout << "nu este mint, ";
    cout << "coef. raritate = " << coefRaritate << ", ";
}
