#include "Disc.h"

Disc::Disc(string name, float price, string band, string recordLabel, Data release): Produs{name, price}, trupa{band}, casaDiscuri{recordLabel}, punereVanzare{release} {};

Disc::~Disc() = default;

float Disc::getPretTotal() const {
    return (pretBaza + 5);
}

void Disc::afisare() const {
    Produs::afisare();
    cout << trupa << " " << casaDiscuri << " " << punereVanzare << " ";
}
