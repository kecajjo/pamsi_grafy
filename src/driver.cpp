#include "inc/graf_l.hh"
#include "inc/graf_m.hh"

int main(){

    mac_sasiedztwa<int, int> macierz;
    macierz.dodaj_wierzcholek(1);
    macierz.dodaj_wierzcholek(2);

    lista_2_kier< wierzcholek_m<int> >::iterator iter_w_m = macierz.wierzcholki();
    iter_w_m.iteruj(0);
    wierzcholek_m<int> *w1_m = iter_w_m.wartosc();
    iter_w_m.iteruj(1);
    wierzcholek_m< int> *w2_m = iter_w_m.wartosc();

    macierz.dodaj_krawedz(w1_m,w2_m,3);
    lista_2_kier< krawedz_m<int, int> >::iterator iter_k_m = macierz.krawedzie();
    iter_k_m.iteruj(0);
    krawedz_m<int, int> *k1_m = iter_k_m.wartosc();
    macierz.usun_krawedz(k1_m);
    macierz.usun_wierzcholek(w1_m);
    macierz.usun_wierzcholek(w2_m);

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
    macierz.zamien(k1_m, 111);
    macierz.zamien(w1_m, 222);
    w1_m = iter_w_m.wartosc(9);
    w2_m = iter_w_m.wartosc(10);
    macierz.dodaj_krawedz(w1_m,w2_m,63);

    k1_m = iter_k_m.wartosc(0);
    wierzcholek_m<int> **tab_w_m = macierz.koncowki_krawedzi(k1_m);
    w1_m = tab_w_m[0];
    w2_m = tab_w_m[1];
    

    w1_m = iter_w_m.wartosc(20);
    std::cout << "czy sasiednie: " << macierz.czy_sasiednie(w1_m,w2_m) << std::endl;

    w1_m = macierz.przeciwlegly_wierzch(w2_m, k1_m);
    std::cout << "rozmiar: " << macierz.wierzcholki()->rozmiar() << std::endl;
    w1_m = iter_w_m.wartosc(0);
 /*    krawedz_m<int, int> *tmp[25];
    for(int i=0;i<25;i++){
        tmp[i] = macierz.przylegle_krawedzie(w1_m)[i];
    }  */
    macierz.usun_wierzcholek(w1_m);

    //////////////////////
    // lista sasiedztwa //
    //////////////////////
    lista_sasiedztwa<int, int> sasiad;
    sasiad.dodaj_wierzcholek(1);
    sasiad.dodaj_wierzcholek(2);
    
    lista_2_kier< wierzcholek_l<int, int> >::iterator iter_w = sasiad.wierzcholki();
    iter_w.iteruj(0);
    wierzcholek_l<int, int> *w1 = iter_w.wartosc();
    iter_w.iteruj(1);
    wierzcholek_l<int, int> *w2 = iter_w.wartosc();
    //wierzcholek_l<int, int> *w2 = iter_w.zwroc_elem()->wartosc;

    sasiad.dodaj_krawedz(w1,w2,3);
    lista_2_kier< krawedz_l<int, int> >::iterator iter_k = sasiad.krawedzie();
    iter_k.iteruj(0);
    krawedz_l<int, int> *k1 = iter_k.wartosc();
    sasiad.usun_krawedz(k1);
    sasiad.usun_wierzcholek(w1);
    sasiad.usun_wierzcholek(w2);

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
    sasiad.zamien(k1, 111);
    sasiad.zamien(w1, 222);
    w1 = iter_w.wartosc(9);
    w2 = iter_w.wartosc(10);
    sasiad.dodaj_krawedz(w1,w2,63);

    k1 = iter_k.wartosc(0);
    wierzcholek_l<int, int> **tab_w = sasiad.koncowki_krawedzi(k1);
    w1 = tab_w[0];
    w2 = tab_w[1];
    

    w1 = iter_w.wartosc(20);
    std::cout << "czy sasiednie: " << sasiad.czy_sasiednie(w1,w2) << std::endl;

    w1 = sasiad.przeciwlegly_wierzch(w2, k1);

    w1 = iter_w.wartosc(0);
    sasiad.usun_wierzcholek(w1);

    return 0;
}