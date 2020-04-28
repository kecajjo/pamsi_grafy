#ifndef DIJKSTRA_HH
#define DIJKSTRA_HH

#include "graf_l.hh"
#include "graf_m.hh"
#include "struktura_wyniku.hh"
#include "kopiec.hh"
#include <climits>

void dijkstra_l(lista_sasiedztwa<int, int> *graf, wynik *moj_wynik);
void dijkstra_m(mac_sasiedztwa<int, int> *graf, wynik *moj_wynik);
#include "../dijkstra.cpp"

#endif