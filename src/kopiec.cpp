#ifndef KOPIEC_CPP
#define KOPIEC_CPP

#include "inc/kopiec.hh"

template <typename typ>
void kopiec<typ>::podmien(para<typ> *pierwszy, para<typ> *drugi){
    para<typ> chwilowe = *pierwszy;
    pierwszy->priorytet = drugi->priorytet;
    drugi->priorytet = chwilowe.priorytet;
    pierwszy->nazwa = drugi->nazwa;
    drugi->nazwa = chwilowe.nazwa;
}

template<typename typ>
void kopiec<typ>::napraw_kopiec_po_usunieciu(){
    int i = 1;
    int rozmiar = this->kolejka.zwroc_rozmiar();
    while(i<=rozmiar){
        if(i*2 <= rozmiar){
            if( (i*2+1) <= rozmiar){
                if(this->kolejka[i*2-1]<this->kolejka[i*2]){
                    if(this->kolejka[i-1]>this->kolejka[i*2-1]){
                        podmien(&this->kolejka[i*2-1], &this->kolejka[i-1]);
                    }
                    i*=2;
                } else{
                    if(this->kolejka[i-1]>this->kolejka[i*2]){
                        podmien(&this->kolejka[i*2], &this->kolejka[i-1]);
                    }
                    i = i*2 + 1;
                }
            } else{
                if(this->kolejka[i-1]>this->kolejka[i*2-1]){
                    podmien(&this->kolejka[i*2-1], &this->kolejka[i-1]);
                }
                i*=2;
            }
        } else{
            i*=2;
        }
    }
}

template<typename typ>
void kopiec<typ>::napraw_kopiec_po_dodaniu(){
    int syn = this->kolejka.zwroc_rozmiar()-1; // indeks syna
    int ojciec = (syn-1)/2; // indeks ojca
    while(this->kolejka[ojciec] > this->kolejka[syn] && syn != 0){
        this->podmien(&this->kolejka[ojciec], &this->kolejka[syn]);
        syn = ojciec;
        ojciec = (ojciec-1)/2;
    }
}

template <typename typ>
void kopiec<typ>::dodaj(typ do_dodania, int priorytet){
    para<typ> moja_para(do_dodania);
    moja_para.priorytet = priorytet;
    this->kolejka.dodaj(moja_para);
    this->napraw_kopiec_po_dodaniu();
}

template <typename typ>
para<typ> kopiec<typ>::sciagnij(){
    para<typ> do_zwrocenia;
    do_zwrocenia.nazwa = this->kolejka[0].nazwa;
    do_zwrocenia.priorytet = this->kolejka[0].priorytet;
    podmien(&this->kolejka[0], &this->kolejka[this->kolejka.zwroc_rozmiar()-1]);
    this->kolejka.usun();
    this->napraw_kopiec_po_usunieciu();
    return do_zwrocenia;
}

template <typename typ>
para<typ> kopiec<typ>::pokaz_najmniejszy(){
    return this->kolejka[0];
}

template <typename typ>
int kopiec<typ>::rozmiar(){
    return this->kolejka.zwroc_rozmiar();
}

template <typename typ>
bool kopiec<typ>::czy_pusta(){
    if(this->kolejka.zwroc_rozmiar() == 0){
        return true; // jesli kolejka jest pusta zwraca true
    }
    return false; // jesli kolejka ma elementy zwraca false
}

#endif