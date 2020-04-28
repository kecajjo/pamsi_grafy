#ifndef LOSOWANIE_GRAFU_HH
#define LOSOWANIE_GRAFU_HH
#include <iostream>
#include <climits>
#include <fstream>
#include <string>

void losuj_graf(int ilosc_wierzcholkow, std::string nazwa, int typ_gestosci = 1, int zakres_wag_kraw = 500);
#include "../losowanie_grafu.cpp"
#endif