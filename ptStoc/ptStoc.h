#ifndef PTSTOC_H
#define PTSTOC_H

#include "ArticolVestimentar.h"
#include "CD.h"
#include "Vinil.h"
#include "DiscVintage.h"

void adaugareProdus(map<int, pair<Produs*, int>>&);
bool modifStoc(map<int, pair<Produs*, int>>&);
void modifStocCOMANDA(map<int, pair<Produs*, int>>::iterator, int);
bool okStoc();
bool stergeStoc(map<int, pair<Produs*, int>>&);
bool preturiStoc(map<int, pair<Produs*, int>>&);

#endif //PTSTOC_H
