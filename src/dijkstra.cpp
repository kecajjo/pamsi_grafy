#include "inc/dijkstra.hh"

// algorytm na liscie wymaga, zeby wierzcholki w nazwie przechowywaly swoj indeks
// numer wierzcholka startowego musi byc mniejszy od ilosci wierzcholkow w grafie
void dijkstra_l(lista_sasiedztwa<int, int> *graf, wynik *moj_wynik, int nr_wierzch_start){

    int ilos_wierzch = graf->wierzcholki()->rozmiar();
    lista_2_kier< wierzcholek_l<int, int> >::iterator it_w = graf->wierzcholki(); // iterator do iterowania po wierzcholkach
    wierzcholek_l<int,int> *w = it_w.wartosc(nr_wierzch_start);
    kopiec< wierzcholek_l<int,int> *> kolejka; // kolejka wskaznikow na wierzcholek
    for(int i=0; i<ilos_wierzch;i++){
        moj_wynik->droga[i] = INT_MAX; // wszystkie drogi ustawiamy na wartosc maksymalna
        moj_wynik->poprzednik[i] = -1; // brak poprzednikow, docelowo beda nazwy, bedace rowniez indeksami
    }
    moj_wynik->droga[nr_wierzch_start] = 0;
    kolejka.dodaj(w, moj_wynik->droga[nr_wierzch_start]); // droga do wierzcholka startowego to 0
    while(kolejka.czy_pusta() == false){
        para< wierzcholek_l<int, int> *> pomocnicza = kolejka.sciagnij();
        int indeks = pomocnicza.nazwa->nazwa; // pobiera nazwe bedaca indeksem z wierzcholka
        int odleglosc = pomocnicza.priorytet;
        if(odleglosc <= moj_wynik->droga[indeks]){ // jesli odleglosc jest wieksza niz w wyniku to wierzcholek byl aktualizowany
            lista_2_kier< krawedz_l<int, int> *>::iterator it_kraw_wierzch = graf->przylegle_krawedzie(pomocnicza.nazwa);
            int ilosc_krawedzi = it_kraw_wierzch.rozmiar();
            for(int i=0;i<ilosc_krawedzi;i++){
                krawedz_l<int, int> *k = *(it_kraw_wierzch.wartosc()); // wskaznik na krawedz pomocnicza
                w = graf->przeciwlegly_wierzch(pomocnicza.nazwa, k);
                if(moj_wynik->droga[w->nazwa] > (k->nazwa + moj_wynik->droga[pomocnicza.nazwa->nazwa])){
                    moj_wynik->droga[w->nazwa] = k->nazwa + moj_wynik->droga[pomocnicza.nazwa->nazwa]; // aktualizuje droge na krotsza
                    moj_wynik->poprzednik[w->nazwa] = pomocnicza.nazwa->nazwa; // aktualizuje poprzednika
                    kolejka.dodaj(w, moj_wynik->droga[w->nazwa]); // dodaje do kolejki zaktualizowany wierzcholek
                }
                it_kraw_wierzch++;
            }
        }
    }
}

// numer wierzcholka startowego musi byc mniejszy od ilosci wierzcholkow w grafie
void dijkstra_m(mac_sasiedztwa<int, int> *graf, wynik *moj_wynik, int nr_wierzch_start){

    int ilos_wierzch = graf->wierzcholki()->rozmiar();
    lista_2_kier< wierzcholek_m<int> >::iterator it_w = graf->wierzcholki(); // iterator do iterowania po wierzcholkach
    wierzcholek_m<int> *w = it_w.wartosc(nr_wierzch_start);
    kopiec< wierzcholek_m<int> *> kolejka; // kolejka wskaznikow na wierzcholek
    for(int i=0; i<ilos_wierzch;i++){
        moj_wynik->droga[i] = INT_MAX; // wszystkie drogi ustawiamy na wartosc maksymalna
        moj_wynik->poprzednik[i] = -1; // brak poprzednikow, docelowo beda nazwy, bedace rowniez indeksami
    }
    moj_wynik->droga[nr_wierzch_start] = 0;
    kolejka.dodaj(w, moj_wynik->droga[nr_wierzch_start]); // droga do wierzcholka startowego to 0

    while(kolejka.czy_pusta() == false){
        para< wierzcholek_m<int> *> pomocnicza = kolejka.sciagnij();
        int indeks = pomocnicza.nazwa->indeks; // pobiera nazwe bedaca indeksem z wierzcholka
        int odleglosc = pomocnicza.priorytet;
        if(odleglosc <= moj_wynik->droga[indeks]){ // jesli odleglosc jest wieksza niz w wyniku to wierzcholek byl aktualizowany
            krawedz_m<int, int> **wiersz = graf->przylegle_krawedzie(pomocnicza.nazwa);
            int ilosc_krawedzi = graf->wierzcholki()->rozmiar();
            for(int i=0;i<ilosc_krawedzi;i++){ // wiersz ma tyle elementow ile jest wierzcholkow w grafie
                krawedz_m<int, int> *k = wiersz[i]; // wskaznik na krawedz pomocnicza
                if(k != nullptr){
                    w = graf->przeciwlegly_wierzch(pomocnicza.nazwa, k);
                    if(moj_wynik->droga[w->indeks] > (k->nazwa + moj_wynik->droga[pomocnicza.nazwa->indeks])){
                        moj_wynik->droga[w->indeks] = k->nazwa + moj_wynik->droga[pomocnicza.nazwa->indeks]; // aktualizuje droge na krotsza
                        moj_wynik->poprzednik[w->indeks] = pomocnicza.nazwa->indeks; // aktualizuje poprzednika
                        kolejka.dodaj(w, moj_wynik->droga[w->indeks]); // dodaje do kolejki zaktualizowany wierzcholek
                    }
                }
            }
        }

    }
}

std::ostream& operator << (std::ostream &strm, wynik moj_wynik){
    strm << "indeks, droga, poprzednicy po spacji" << std::endl;
    for(int i=0;i<moj_wynik.wielkosc;i++){
        strm << i << ", " << moj_wynik.droga[i] << ", ";
        int j = i;
        while(moj_wynik.poprzednik[j] != -1){
            strm << moj_wynik.poprzednik[j] << " ";
            j = moj_wynik.poprzednik[j];
        }
        strm << std::endl;
    }
    return strm;
}