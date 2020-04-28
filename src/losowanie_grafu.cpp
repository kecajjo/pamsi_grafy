#include "inc/losowanie_grafu.hh"

// TO DO naprawic zeby moc podawac nazwe 

#define ROZMIAR 1000
void losuj_graf(int ilosc_wierzcholkow, std::string nazwa, int typ_gestosci, int zakres_wag_kraw){
    std::srand(time(NULL));

    std::ofstream plik;
    plik.open(nazwa);
    if(plik.is_open() == false){
        std::cout << "BLAD: plik sie nie otworzyl" << std::endl;
        return;
    }

    int **tab;
    tab = new int* [ilosc_wierzcholkow];
    for(int i=0;i<ilosc_wierzcholkow;i++){
        tab[i] = new int[ilosc_wierzcholkow];
    }
    int ilosc_krawedzi = 0;
    switch(typ_gestosci){
        case 1: // graf pelny
            ilosc_krawedzi = (ilosc_wierzcholkow*(ilosc_wierzcholkow-1)/2);
            break;
        case 2: // gestosc grafu = 75%
            ilosc_krawedzi = (ilosc_wierzcholkow*(ilosc_wierzcholkow-1)/2)*3/4;
            break;
        case 3: // gestosc grafu 50%
            ilosc_krawedzi = (ilosc_wierzcholkow*(ilosc_wierzcholkow-1)/2)/2;
            break;
        case 4: // gestosc grafu 25%
            ilosc_krawedzi = (ilosc_wierzcholkow*(ilosc_wierzcholkow-1)/2)/4;
            break;
        default: 
            std::cout << "nie znam takiego rodzaju gestosci" << std::endl;
            break;
    }
    
    for(int i=0;i<ilosc_wierzcholkow;i++){
        for(int j=0;j<i;j++){
            tab[i][j] = rand()%zakres_wag_kraw;
        }
    }
    plik << ilosc_krawedzi << "\t"
        << ilosc_wierzcholkow << "\t"
        << 0 << std::endl;
    int licznik_gestosci = 0;

    for(int i=0;i<ilosc_wierzcholkow;i++){
        for(int j=0;j<i;j++){
            switch(typ_gestosci){
                case 1: // graf pelny
                    plik << i << "\t"
                        << j << "\t"
                        << tab[i][j] << std::endl;
                    break;
                case 2: // gestosc grafu 75%
                    if(licznik_gestosci %4 != 3){
                        plik << i << "\t"
                            << j << "\t"
                            << tab[i][j] << std::endl;
                    }
                    break;
                case 3: // gestosc grafu 50%
                    if(licznik_gestosci %2 == 0){
                        plik << i << "\t"
                            << j << "\t"
                            << tab[i][j] << std::endl;
                    }
                    break;
                case 4: // gestosc grafu 25%
                    if(licznik_gestosci %4 == 0){
                        plik << i << "\t"
                            << j << "\t"
                            << tab[i][j] << std::endl;
                    }
                    break;
                default:
                    std::cout << "nie znam takiego rodzaju gestosci" << std::endl;
                    break;
            }
            licznik_gestosci++;
        }
    }
    plik.close();
}