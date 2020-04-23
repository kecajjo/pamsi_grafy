#include "inc/graf_l.hh"

int main(){
    lista_sasiedztwa<int, int> sasiad;
    sasiad.dodaj_wierzcholek(1);
    sasiad.dodaj_wierzcholek(2);
    
    lista_2_kier< wierzcholek_l<int, int> >::iterator iter_w = sasiad.wierzcholki();
    iter_w.iteruj(0);
    wierzcholek_l<int, int> *w1 = iter_w.zwroc_elem()->wartosc;
    iter_w.iteruj(1);
    wierzcholek_l<int, int> *w2 = iter_w.zwroc_elem()->wartosc;

    sasiad.dodaj_krawedz(w1,w2,3);
    lista_2_kier< krawedz_l<int, int> >::iterator iter_k = sasiad.krawedzie();
    iter_k.iteruj(0);
    krawedz_l<int, int> *k1 = iter_k.zwroc_elem()->wartosc;
    sasiad.usun_krawedz(k1);
    sasiad.usun_wierzcholek(w1);
    sasiad.usun_wierzcholek(w2);

    int do_dodania = 25;
    for(int i=0;i<do_dodania;i++){
        sasiad.dodaj_wierzcholek(i);
    }

    iter_w.iteruj(5);
    w1 = iter_w.zwroc_elem()->wartosc;
    iter_w.iteruj(7);
    w2 = iter_w.zwroc_elem()->wartosc;
    sasiad.dodaj_krawedz(w1,w2,57);

    w1 = (iter_w.zwroc_elem(0))->wartosc;
    for(int i=1;i<do_dodania;i++){
        w2 = (iter_w.zwroc_elem(i))->wartosc;
        sasiad.dodaj_krawedz(w1,w2,i);
    }
    k1 = iter_k.zwroc_elem(1)->wartosc;
    sasiad.zamien(k1, 111);
    sasiad.zamien(w1, 222);
    w1 = (iter_w.zwroc_elem(9))->wartosc;
    w2 = (iter_w.zwroc_elem(10))->wartosc;
    sasiad.dodaj_krawedz(w1,w2,63);

    k1 = iter_k.zwroc_elem(0)->wartosc;
    wierzcholek_l<int, int> **tab_w = sasiad.koncowki_krawedzi(k1);
    w1 = tab_w[0];
    w2 = tab_w[1];
    

    w1 = iter_w.zwroc_elem(20)->wartosc;
    std::cout << "czy sasiednie: " << sasiad.czy_sasiednie(w1,w2) << std::endl;

    w1 = sasiad.przeciwlegly_wierzch(w2, k1);

    w1 = iter_w.zwroc_elem(0)->wartosc;
    sasiad.usun_wierzcholek(w1);

    return 0;
}