#include "inc/graf_l.hh"

int main(){
    lista_sasiedztwa<int, int> sasiad;
    sasiad.dodaj_wierzcholek(1);
    sasiad.dodaj_wierzcholek(2);
    
    lista< wierzcholek_l<int, int> >::iterator iter_w = &sasiad.lista_wierzcholkow;
    wierzcholek_l<int, int> *w1 = (iter_w.iteruj(0))->wartosc;
    wierzcholek_l<int, int> *w2 = (iter_w.iteruj(1))->wartosc;
    sasiad.dodaj_krawedz(w1,w2,3);
    lista_2_kier< krawedz_l<int, int> >::iterator iter_k = &sasiad.lista_krawedzi;
    krawedz_l<int, int> *k1 = (iter_k.iteruj(0))->wartosc;
    sasiad.usun_krawedz(k1);
    sasiad.usun_wierzcholek(w1);
    sasiad.usun_wierzcholek(w2);

    int do_dodania = 25;
    for(int i=0;i<do_dodania;i++){
        sasiad.dodaj_wierzcholek(i);
    }
    w1 = (iter_w.iteruj(0))->wartosc;
    for(int i=1;i<do_dodania;i++){
        w2 = (iter_w.iteruj(i))->wartosc;
        sasiad.dodaj_krawedz(w1,w2,i);
    }
    sasiad.usun_wierzcholek(w1);

    return 0;
}