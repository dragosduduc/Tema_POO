#include "CD.h"

int CD::nrCDs = 0;

CD::CD(string name, float price, string band, string recordLabel, Data release): Disc{name, price, band, recordLabel, release} {};

void CD::addCD(int quant) {
    nrCDs += quant;
}

int CD::getNrCDs() {
    return nrCDs;
}