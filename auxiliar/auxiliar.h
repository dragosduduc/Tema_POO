#ifndef AUX_H
#define AUX_H

#include <string>
#include "Data.h"
#include "Manager.h"
#include "operatorComenzi.h"
#include "Asistent.h"
using namespace std;

bool isNameValid(string);
bool isCNPValid(string);
string formatName(string);
int getVechime(Data);
Angajat* angajare();

#endif //AUX_H
