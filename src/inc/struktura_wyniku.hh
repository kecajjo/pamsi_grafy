#ifndef STRUKTURA_WYNIKU_HH
#define STRUKTURA_WYNIKU_HH

struct wynik{
    int *poprzednik; // wskaznik na tablice poprzednikow, indeks oznacza wierzcholek
    int *droga; // wskaznik na tablice dlugosci drogi, indeks oznacza wierzcholek
};

#endif