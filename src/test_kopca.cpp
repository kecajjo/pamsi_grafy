#include <iostream>
#include "inc/kopiec.hh"
#include <climits>

#define ROZMIAR 10

template<typename typ>
bool czy_rosnaco(typ tablica[], int rozmiar){
    for(int i=1;i<rozmiar;i++){
        if(tablica[i-1]>tablica[i]){
            std::cout<<std::endl<<std::endl<<"NIE DZIALA"<<std::endl<<std::endl;
            return false;
        }
    }
    return true;
}

int main(){

    std::srand(time(NULL));

    int tab[ROZMIAR+1];
    kopiec<int> kolejka;

    for(int i=0;i<ROZMIAR;i++){
        kolejka.dodaj(rand()%1000);
    }
    kolejka.sciagnij();
    kolejka.sciagnij();
    kolejka.dodaj(300);
    kolejka.dodaj(570);
    kolejka.dodaj(100);

    for(int i=0;i<ROZMIAR+1;i++){
        tab[i] = kolejka.sciagnij();
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
    std::cout << czy_rosnaco(tab, ROZMIAR+1) << std::endl;
    
 return 0;
}
