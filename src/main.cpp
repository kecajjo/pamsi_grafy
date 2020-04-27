#include "inc/graf_m.hh"
#include "inc/graf_l.hh"
#include <iostream>
#include <fstream>
#include <unistd.h>


int main(){

/* krawedz_l<int,int> kl1;
krawedz_l<int,int> kl2;
krawedz_m<int,int> km1;
krawedz_m<int,int> km2;
wierzcholek_l<int,int> wl1;
wierzcholek_l<int,int> wl2;
wierzcholek_m<int> wm1;
wierzcholek_m<int> wm2;

kl1.nazwa = 2;
kl2.nazwa = 1;
km1.nazwa = 2;
km2.nazwa = 1;
wl1.nazwa = 2;
wl2.nazwa = 1;
wm1.nazwa = 2;
wm2.nazwa = 1;

std::cout << "<" << (kl1<kl2) <<std::endl;
std::cout << "<" << (km1<km2) <<std::endl;
std::cout << "<" << (wl1<wl2) <<std::endl;
std::cout << "<" << (wm1<wm2) <<std::endl;

std::cout << ">" << (kl1>kl2) <<std::endl;
std::cout << ">" << (km1>km2) <<std::endl;
std::cout << ">" << (wl1>wl2) <<std::endl;
std::cout << ">" << (wm1>wm2) <<std::endl;

std::cout << "==" << (kl1==kl2) <<std::endl;
std::cout << "==" << (km1==km2) <<std::endl;
std::cout << "==" << (wl1==wl2) <<std::endl;
std::cout << "==" << (wm1==wm2) <<std::endl;

std::cout << "<=" << (kl1<=kl2) <<std::endl;
std::cout << "<=" << (km1<=km2) <<std::endl;
std::cout << "<=" << (wl1<=wl2) <<std::endl;
std::cout << "<=" << (wm1<=wm2) <<std::endl;

std::cout << ">=" << (kl1>=kl2) <<std::endl;
std::cout << ">=" << (km1>=km2) <<std::endl;
std::cout << ">=" << (wl1>=wl2) <<std::endl;
std::cout << ">=" << (wm1>=wm2) <<std::endl; */

/*     std::ifstream plik;

    mac_sasiedztwa<int, int> graf;
    mac_sasiedztwa<int, int> graf2;
    for(int licznik=0;licznik<10;licznik++){    
        plik.open("graf.txt");
        plik >> graf;
        plik.close();
        std::cout<<"ilosc wierzcholkow" << graf.wierzcholki()->rozmiar() <<std::endl;
        int ilosc_wierzcholkow = graf.wierzcholki()->rozmiar();
        for(int i=0;i<ilosc_wierzcholkow;i++){
            graf.usun_wierzcholek(graf.wierzcholki()->ostatni()->wartosc);
        }
        std::cout<<licznik<<std::endl;
    }

    for(int licznik=0;licznik<10;licznik++){    
        plik.open("graf1.txt");
        plik >> graf2;
        plik.close();
        std::cout<<"ilosc wierzcholkow" << graf2.wierzcholki()->rozmiar() <<std::endl;
        int ilosc_wierzcholkow = graf2.wierzcholki()->rozmiar();
        for(int i=0;i<ilosc_wierzcholkow;i++){
            graf2.usun_wierzcholek(graf2.wierzcholki()->ostatni()->wartosc);
        }
        std::cout<<licznik<<std::endl;
    } */

/*     mac_sasiedztwa<int, int> graf;
    int ilosc_krawedzi = 0;
    for(int i=0;i<1000;i++){
        graf.dodaj_wierzcholek(i);
    }
    wierzcholek_m<int> *w1;
    wierzcholek_m<int> *w2;

    w1 = graf.wierzcholki()->pierwszy()->wartosc;
    w2 = graf.wierzcholki()->ostatni()->wartosc;
    for(int licznik=0;licznik<10;licznik++){
        for(int i=0;i<1000;i++){
            graf.dodaj_krawedz(w1, w2, i);
        }

        std::cout << "dodano krawedzie" <<std::endl;
        sleep(2);
        ilosc_krawedzi = graf.krawedzie()->rozmiar();
        for(int i=0;i<ilosc_krawedzi;i++){
            graf.usun_krawedz(graf.krawedzie()->ostatni()->wartosc);
        }
        std::cout << "usunieto krawedzie" << std::endl;
        std::cout << "licznik: " << licznik <<std::endl;
        sleep(2);
    } */

 return 0;
}