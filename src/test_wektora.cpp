#include "inc/wektor.hh"
#include <iostream>

int main(){
    wektor<wektor<int*>> wek_wsk;
    wek_wsk.dodaj(wektor<int*>(nullptr));
    wek_wsk.dodaj(wektor<int*>(nullptr));

    wektor<int> wek(111);
    int rozmiar = 25;
    for(int i=0;i<rozmiar;i++){
        wek.dodaj(i);
    }
    wek[5] = 777;
    std::cout << "wypisz wszystkie" << std::endl;
    for(int i=0;i<rozmiar;i++){
        std::cout << wek[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "wypisz bez indeksu 3" << std::endl;
    wek.usun(27);
    for(int i=0;i<rozmiar;i++){
        std::cout << wek[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "wypisz bez ostatniego: " << std::endl;
    wek.usun();
    for(int i=0;i<rozmiar;i++){
        std::cout << wek[i] << " ";
    }
    std::cout << std::endl;

    wek.wyczysc();
    std::cout << "rozmiar po czyszczeniu: " << wek.zwroc_rozmiar() << std::endl;

    std::cout << "wypisz wszystkie" << std::endl;
    for(int i=0;i<rozmiar;i++){
        wek.dodaj(i);
        std::cout << wek[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "rozmiar po dodawaniu: " << wek.zwroc_rozmiar() << std::endl;

    for(int i=0;i<rozmiar+2;i++){
        wek.usun();
    }
    std::cout << "rozmiar po pojedynczym usuwaniu: " << wek.zwroc_rozmiar() << std::endl;

}
