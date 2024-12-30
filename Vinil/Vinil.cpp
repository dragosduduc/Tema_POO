#include "Vinil.h"

int Vinil::nrVinil = 0;

Vinil::Vinil(string name, float price, string band, string recordLabel, Data release): Disc{name, price, band, recordLabel, release} {};

void Vinil::addVinil(int quant) {
    nrVinil += quant;
}

int Vinil::getNrVinil() {
    return nrVinil;
}

string Vinil::getTip() const {
    return "VINIL";
}

