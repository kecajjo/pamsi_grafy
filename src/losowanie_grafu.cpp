#include <iostream>
#include <climits>
#include <fstream>

#define ROZMIAR 1000
int main(){
    std::srand(time(NULL));
    std::ofstream plik;
    plik.open("graf.txt");

    int tab[ROZMIAR][ROZMIAR];
    int ilosc_krawedzi = ROZMIAR*(ROZMIAR-1)/2;
    int ilosc_wierzcholkow = ROZMIAR;
    for(int i=0;i<ROZMIAR;i++){
        for(int j=0;j<ROZMIAR;j++){
            tab[i][j] = rand()%1000;
        }
    }
    plik << ilosc_krawedzi << "\t"
        << ilosc_wierzcholkow << "\t"
        << 0 << std::endl;

    for(int i=0;i<ROZMIAR;i++){
        for(int j=0;j<ROZMIAR;j++){
            if(i != j){
                plik << i << "\t"
                    << j << "\t"
                    << tab[i][j] << std::endl;
            }
        }
    }
}