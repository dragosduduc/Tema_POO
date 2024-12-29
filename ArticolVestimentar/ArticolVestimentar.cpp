#include "ArticolVestimentar.h"

ArticolVestimentar::ArticolVestimentar(string name, float price, string brand, string color): Produs{name, price}, marca{brand}, culoare{color} {};

float ArticolVestimentar::getPretTotal() const {
    return pretBaza + 20;
}

void ArticolVestimentar::afisare() const{
    Produs::afisare();
    cout << marca << " " << culoare << " ";
}