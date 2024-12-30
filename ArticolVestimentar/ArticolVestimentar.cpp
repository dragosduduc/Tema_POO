#include "ArticolVestimentar.h"

int ArticolVestimentar::nrArticoleVestimentare = 0;

ArticolVestimentar::ArticolVestimentar(string name, float price, string brand, string color): Produs{name, price}, marca{brand}, culoare{color} {};

void ArticolVestimentar::addArticoleVestimentare(int quant) {
    nrArticoleVestimentare += quant;
}

int ArticolVestimentar::getNrArticoleVestimentare() {
    return nrArticoleVestimentare;
}

string ArticolVestimentar::getTip() const {
    return "ART. VEST.";
}


float ArticolVestimentar::getPretTotal() const {
    return pretBaza + 20;
}

void ArticolVestimentar::afisare() const{
    Produs::afisare();
    cout << " " << marca << " " << culoare << ", ";
}