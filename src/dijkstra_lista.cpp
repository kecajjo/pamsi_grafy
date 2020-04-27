#include "inc/dijkstra_lista.hh"

void dijkstra_l(lista_sasiedztwa<int, int> *graf, wynik *moj_wynik){

    int ilos_wierzch = graf->wierzcholki()->rozmiar();
    lista_2_kier< wierzcholek_l<int, int> >::iterator it_w = graf->wierzcholki(); // iterator do iterowania po wierzcholkach
    wierzcholek_l<int,int> *w = it_w.wartosc(0);
    kopiec< wierzcholek_l<int,int> *> kolejka; // kolejka wskaznikow na wierzcholek
    for(int i=0; i<ilos_wierzch;i++){
        moj_wynik->droga[i] = INT_MAX; // wszystkie drogi ustawiamy na wartosc maksymalna
        moj_wynik->poprzednik[i] = -1; // brak poprzednikow, docelowo beda nazwy, bedace rowniez indeksami
    }
    moj_wynik->droga[0] = 0;
    kolejka.dodaj(w, moj_wynik->droga[0]); // droga do wierzcholka startowego to 0

    while(kolejka.czy_pusta() == false){
        para< wierzcholek_l<int, int> *> pomocnicza = kolejka.sciagnij();
        int indeks = pomocnicza.nazwa->nazwa; // pobiera nazwe bedaca indeksem z wierzcholka
        int odleglosc = pomocnicza.priorytet;
        if(odleglosc <= moj_wynik->droga[indeks]){ // jesli odleglosc jest wieksza niz w wyniku to wierzcholek byl aktualizowany
            lista_2_kier< krawedz_l<int, int> *>::iterator it_kraw_wierzch = graf->przylegle_krawedzie(pomocnicza.nazwa);
            for(int i=0;i<it_kraw_wierzch.rozmiar();i++){
                krawedz_l<int, int> *k = *(it_kraw_wierzch.wartosc()); // wskaznik na krawedz pomocnicza
                w = graf->przeciwlegly_wierzch(pomocnicza.nazwa, k);
                // TO DO DALEJ
                if(moj_wynik->droga[w->nazwa] > (k->nazwa + pomocnicza.nazwa->nazwa)){
                    moj_wynik->droga[w->nazwa] = k->nazwa + pomocnicza.nazwa->nazwa; // aktualizuje droge na krotsza
                    moj_wynik->poprzednik[w->nazwa] = pomocnicza.nazwa->nazwa;
                    kolejka.dodaj(w, moj_wynik->droga[w->nazwa]); // dodaje do kolejki zaktualizowany wierzcholek
                }
            }
        }

    }
}