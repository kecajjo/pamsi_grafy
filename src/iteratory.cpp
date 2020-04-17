#ifndef ITERATORY_CPP
#define ITERATORY_CPP

#include "inc/iteratory.hh"

template <typename typ>
lista<typ>::iterator::iterator(){
    this->aktualny_element = nullptr;
    this->przypisana_lista = nullptr;
    this->numer_aktualnego = -1
}

template <typename typ>
lista<typ>::iterator::iterator(lista<typ> moja_lista){
    this->aktualny_element = nullptr;
    this->przypisana_lista = moja_lista;
    this->numer_aktualnego = -1
}

// numeracja od 0 jak w tablicy
template <typename typ>
element<typ>* lista<typ::iterator::iteruj(unsigned int numer_szukanego){
    if(this->przypisana_lista != nullptr){
        if(this->przypisana_lista->czy_pusta() == false){
            element<typ> *wybrany = this->przypisana_lista->pierwszy();
            for(unsigned int i=0;i<numer_szukanego;i++){
                if (wybrany->nastepny == nullptr){
                    std::cout<<"nie ma takiego elementu"<<std::endl;
                    std::cout<<"zwrocono nullptr"<<std::endl;
                    return nullptr; //w razie przekroczenia zakresu zwraca nullptr
                }
                wybrany = wybrany->nastepny;
            }
            return wybrany; // jesli lista nie bedzie pusta zwroci adres elementu
        }
        std::cout << "lista pusta, zwrocono nulptr" << std::endl;
        return nullptr; // w razie pustej listy zwraca nullptr
    }
    std::cout << "nie przypisano listy, zwrocono nullptr" << std:::endl;
    return nullptr;
}

#endif