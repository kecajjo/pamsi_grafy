#ifndef DIJKSTRA_HH
#define DIJKSTRA_HH

#include "graf_l.hh"
#include "graf_m.hh"
#include "kopiec.hh"
#include <climits>

struct wynik{
    int *poprzednik; // wskaznik na tablice poprzednikow, indeks oznacza wierzcholek
    int *droga; // wskaznik na tablice dlugosci drogi, indeks oznacza wierzcholek
    int wielkosc;
    wynik(){this->droga=nullptr; this->poprzednik=nullptr; this->wielkosc=-1;}
};


void dijkstra_l(lista_sasiedztwa<int, int> *graf, wynik *moj_wynik, int nr_wierzch_start = 0);
void dijkstra_m(mac_sasiedztwa<int, int> *graf, wynik *moj_wynik, int nr_wierzch_start = 0);
std::ostream& operator << (std::ostream &strm, wynik moj_wynik);


#endif