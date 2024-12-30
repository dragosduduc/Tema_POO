#include "Produs.h"

int Produs::cnt = 0;

Produs::Produs(string name, float price):nume{name}, pretBaza{price}, cod{cnt++} {};

Produs::~Produs() = default;

int Produs::getCod() const {
    return cod;
}

float Produs::getPretBaza() const {
    return pretBaza;
}

void Produs::afisare() const {
    cout << "ID: " << cod << ", [" << getTip() << "] " << nume;
}