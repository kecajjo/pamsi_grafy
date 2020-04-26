#include "inc/graf_m.hh"
#include "inc/graf_l.hh"
#include <iostream>
#include <fstream>

int main(){

    std::ifstream plik;
    plik.open("graf.txt");

    lista_sasiedztwa<int, int> graf;
    for(int licznik=0;licznik<1000;licznik++){    
        plik >> graf;

        int ilosc_wierzcholkow = graf.wierzcholki()->rozmiar();
        for(int i=0;i<ilosc_wierzcholkow;i++){
            graf.usun_wierzcholek(graf.wierzcholki()->ostatni()->wartosc);
        }
    }

 return 0;
}