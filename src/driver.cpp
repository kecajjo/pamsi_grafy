#include "inc/graf_l.hh"
#include "inc/graf_m.hh"
#include "inc/dijkstra.hh"
#include "inc/losowanie_grafu.hh"

int main(){

    std::cout << std::endl << "MACIERZ SASIEDZTWA" << std::endl << std::endl;

    mac_sasiedztwa<int, int> macierz;
    std::cout << "ilosc wierzcholkow: " << macierz.wierzcholki()->rozmiar() << "dodaje 2 wierzcholki" << std::endl;
    macierz.dodaj_wierzcholek(1);
    macierz.dodaj_wierzcholek(2);
    std::cout << "ilosc wierzcholkow po dodaniu: " << macierz.wierzcholki()->rozmiar() << std::endl;

    lista_2_kier< wierzcholek_m<int> >::iterator iter_w_m = macierz.wierzcholki();
    iter_w_m.iteruj(0);
    wierzcholek_m<int> *w1_m = iter_w_m.wartosc();
    iter_w_m.iteruj(1);
    wierzcholek_m< int> *w2_m = iter_w_m.wartosc();

    std::cout << "ilosc krawedzi przed dodaniem 1: " << macierz.krawedzie()->rozmiar() << std::endl;
    macierz.dodaj_krawedz(w1_m,w2_m,3);
    std::cout << "ilosc krawedzi po dodaniu: " << macierz.krawedzie()->rozmiar() << std::endl;
    lista_2_kier< krawedz_m<int, int> >::iterator iter_k_m = macierz.krawedzie();
    iter_k_m.iteruj(0);
    krawedz_m<int, int> *k1_m = iter_k_m.wartosc();
    std::cout << "ilosc krawedzi przed usunieciem 1: " << macierz.krawedzie()->rozmiar() << std::endl;
    macierz.usun_krawedz(k1_m);
    std::cout << "ilosc krawedzi po usunieciu: " << macierz.krawedzie()->rozmiar() << std::endl;
    std::cout << "ilosc wierzcholkow przed usunieciem 2: " << macierz.wierzcholki()->rozmiar() << std::endl;
    macierz.usun_wierzcholek(w1_m);
    macierz.usun_wierzcholek(w2_m);
    std::cout << "ilosc wierzcholkow po usunieciu: " << macierz.wierzcholki()->rozmiar() << std::endl;

    int do_dodania_m = 25;
    for(int i=0;i<do_dodania_m;i++){
        macierz.dodaj_wierzcholek(i);
    }

    iter_w_m.iteruj(5);
    w1_m = iter_w_m.wartosc();
    iter_w_m.iteruj(7);
    w2_m = iter_w_m.wartosc();
    macierz.dodaj_krawedz(w1_m,w2_m,57);

    w1_m = iter_w_m.wartosc(0);
    for(int i=1;i<do_dodania_m;i++){
        w2_m = iter_w_m.wartosc(i);
        macierz.dodaj_krawedz(w1_m,w2_m,i);
    }

    k1_m = iter_k_m.wartosc(1);
    std::cout << "nazwa krawedzi przed zamiana na 111: " << k1_m->nazwa << std::endl;
    macierz.zamien(k1_m, 111);
    std::cout << "nazwa krawedzi po zamianie na 111: " << k1_m->nazwa << std::endl;
    std::cout << "nazwa wierzcholka przed zamiana na 222: " << w1_m->nazwa << std::endl;
    macierz.zamien(w1_m, 222);
    std::cout << "nazwa wierzcholka po zamianie na 222: " << w1_m->nazwa << std::endl;
    w1_m = iter_w_m.wartosc(9);
    w2_m = iter_w_m.wartosc(10);
    macierz.dodaj_krawedz(w1_m,w2_m,63);

    k1_m = iter_k_m.wartosc(0);
    wierzcholek_m<int> **tab_w_m = macierz.koncowki_krawedzi(k1_m);
    w1_m = tab_w_m[0];
    w2_m = tab_w_m[1];
    std::cout << "nazwy wierzcholkow przylegajacych do krawedzi: " 
        << w1_m->nazwa << " i " << w2_m->nazwa << std::endl;

    std::cout << "sprawdzenie czy wierzcholki poprzednio zwrocone sa sasiednie: " << macierz.czy_sasiednie(w1_m,w2_m) << std::endl;

    w1_m = macierz.przeciwlegly_wierzch(w2_m, k1_m);
    std::cout << "nazwa przeciwleglego wierzcholka do w2_m wzgledem k1_m: " << w1_m->nazwa << std::endl;
    
    w1_m = iter_w_m.wartosc(0);
    std::cout << "ilosc krawedzi przed usunieciem wierzcholka o znacznej ich liczbie: " << macierz.krawedzie()->rozmiar() << std::endl;
    macierz.usun_wierzcholek(w1_m);
    std::cout << "ilosc krawedzi po usunieciu wierzcholka o znacznej ich liczbie: " << macierz.krawedzie()->rozmiar() << std::endl;

    //std::cout<<macierz;

    //////////////////////
    // lista sasiedztwa //
    //////////////////////

    std::cout << std::endl << "LISTA SASIEDZTWA" << std::endl << std::endl;
    lista_sasiedztwa<int, int> sasiad;
    std::cout << "ilosc wierzcholkow: " << sasiad.wierzcholki()->rozmiar() << "dodaje 2 wierzcholki" << std::endl;
    sasiad.dodaj_wierzcholek(1);
    sasiad.dodaj_wierzcholek(2);
    std::cout << "ilosc wierzcholkow po dodaniu: " << sasiad.wierzcholki()->rozmiar() << std::endl;
    
    lista_2_kier< wierzcholek_l<int, int> >::iterator iter_w = sasiad.wierzcholki();
    iter_w.iteruj(0);
    wierzcholek_l<int, int> *w1 = iter_w.wartosc();
    iter_w.iteruj(1);
    wierzcholek_l<int, int> *w2 = iter_w.wartosc();

    std::cout << "ilosc krawedzi przed dodaniem 1: " << sasiad.krawedzie()->rozmiar() << std::endl;
    sasiad.dodaj_krawedz(w1,w2,3);
    std::cout << "ilosc krawedzi po dodaniu: " << sasiad.krawedzie()->rozmiar() << std::endl;
    lista_2_kier< krawedz_l<int, int> >::iterator iter_k = sasiad.krawedzie();
    iter_k.iteruj(0);
    krawedz_l<int, int> *k1 = iter_k.wartosc();
    std::cout << "ilosc krawedzi przed usunieciem 1: " << sasiad.krawedzie()->rozmiar() << std::endl;
    sasiad.usun_krawedz(k1);
    std::cout << "ilosc krawedzi po usunieciu: " << sasiad.krawedzie()->rozmiar() << std::endl;
    std::cout << "ilosc wierzcholkow przed usunieciem 2: " << sasiad.wierzcholki()->rozmiar() << std::endl;
    sasiad.usun_wierzcholek(w1);
    sasiad.usun_wierzcholek(w2);
    std::cout << "ilosc wierzcholkow po usunieciu: " << sasiad.wierzcholki()->rozmiar() << std::endl;

    int do_dodania = 25;
    for(int i=0;i<do_dodania;i++){
        sasiad.dodaj_wierzcholek(i);
    }

    iter_w.iteruj(5);
    w1 = iter_w.wartosc();
    iter_w.iteruj(7);
    w2 = iter_w.wartosc();
    sasiad.dodaj_krawedz(w1,w2,57);

    w1 = iter_w.wartosc(0);
    for(int i=1;i<do_dodania;i++){
        w2 = iter_w.wartosc(i);
        sasiad.dodaj_krawedz(w1,w2,i);
    }
    k1 = iter_k.wartosc(1);
    std::cout << "nazwa krawedzi przed zamiana na 111: " << k1->nazwa << std::endl;
    sasiad.zamien(k1, 111);
    std::cout << "nazwa krawedzi po zamianie na 111: " << k1->nazwa << std::endl;
    std::cout << "nazwa wierzcholka przed zamiana na 222: " << w1->nazwa << std::endl;
    sasiad.zamien(w1, 222);
    std::cout << "nazwa wierzcholka po zamianie na 222: " << w1->nazwa << std::endl;
    w1 = iter_w.wartosc(9);
    w2 = iter_w.wartosc(10);
    sasiad.dodaj_krawedz(w1,w2,63);

    k1 = iter_k.wartosc(0);
    wierzcholek_l<int, int> **tab_w = sasiad.koncowki_krawedzi(k1);
    w1 = tab_w[0];
    w2 = tab_w[1];
    std::cout << "nazwy wierzcholkow przylegajacych do krawedzi: " 
        << w1->nazwa << " i " << w2->nazwa << std::endl;

    std::cout << "sprawdzenie czy wierzcholki poprzednio zwrocone sa sasiednie: " << sasiad.czy_sasiednie(w1,w2) << std::endl;

    w1 = sasiad.przeciwlegly_wierzch(w2, k1);
    std::cout << "nazwa przeciwleglego wierzcholka do w2 wzgledem k1: " << w1->nazwa << std::endl;

    w1 = iter_w.wartosc(0);
    std::cout << "ilosc krawedzi przed usunieciem wierzcholka o znacznej ich liczbie: " << sasiad.krawedzie()->rozmiar() << std::endl;
    sasiad.usun_wierzcholek(w1);
    std::cout << "ilosc krawedzi po usunieciu wierzcholka o znacznej ich liczbie: " << sasiad.krawedzie()->rozmiar() << std::endl;

    return 0;
}