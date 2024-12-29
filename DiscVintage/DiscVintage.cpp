#include "DiscVintage.h"

DiscVintage::DiscVintage(string name, float price, bool mint, int rarity):Produs{name, price}, isMint{mint}, coefRaritate{rarity} {};

float DiscVintage::getPretTotal() const {
    return (pretBaza + 5 + 15 * coefRaritate);
}

void DiscVintage::afisare() const {
    Produs::afisare();
    cout << isMint << " " << coefRaritate << " ";
}
