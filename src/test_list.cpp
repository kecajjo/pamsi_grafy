#include <iostream>
#include "inc/lista.hh"
#include "inc/lista_2_kier.hh"
int main(){

/*     lista_2_kier<int*> m_l;
    int **a;
    m_l.dodaj_na_koniec(*a); */

    std::cout << "lista dwukierunkowa:" << std::endl;

    lista_2_kier<int> moja_lista_2_kier;
    moja_lista_2_kier.dodaj_na_koniec(9999);
    moja_lista_2_kier.dodaj_na_poczatek(3);
    moja_lista_2_kier.dodaj_na_poczatek(5);
    moja_lista_2_kier.dodaj_na_poczatek(2);
    moja_lista_2_kier.dodaj_na_poczatek(1);
    moja_lista_2_kier.dodaj_na_koniec(9999);
    moja_lista_2_kier.dodaj_na_koniec(77);
    moja_lista_2_kier.dodaj_na_koniec(7);
    moja_lista_2_kier.dodaj_na_koniec(8);
    moja_lista_2_kier.dodaj_na_koniec(19);
    moja_lista_2_kier.usun_pierwszy();
    moja_lista_2_kier.usun_ostatni();
    moja_lista_2_kier.usun_element(9999);
    
    lista_2_kier<int>::iterator it = &moja_lista_2_kier;
    it = &moja_lista_2_kier;
    lista_2_kier<int>::iterator it2;
    it2=it;

    element_2_kier<int> *te_it = it2.iteruj(2);
    element_2_kier<int> *t_it = it2.iteruj(te_it, 2);
    std::cout<<"test iteracji:"<<*te_it->wartosc<<std::endl;
    std::cout<<"test iteracji od elementu:"<<*t_it->wartosc<<std::endl;
    t_it = moja_lista_2_kier.pierwszy();
    std::cout<<std::endl;
    it.poczatek();
    for(int i=0;i<6;i++){
        std::cout << *(it.wartosc())->wartosc << std::endl;
        it++;
    }
    te_it = it2.iteruj_wstecz(2);
    t_it = it2.iteruj_wstecz(te_it, 2);
    std::cout<<"test iteracji wstecz:"<<*te_it->wartosc<<std::endl;
    std::cout<<"test iteracji wstecz od elementu:"<<*t_it->wartosc<<std::endl;
    std::cout<<std::endl;
    
    it.koniec();
    for(int i=0;i<6;i++){
        std::cout << *(it.wartosc())->wartosc << std::endl;
        it--;
    }

/*     element_2_kier<int> *test_iteracji2 = moja_lista_2_kier.iteruj(1);
    std::cout<<"test iteracji:"<<*test_iteracji2->wartosc<<std::endl;
    element_2_kier<int> *test_iteracji3 = moja_lista_2_kier.iteruj_od_konca(1);
    std::cout<<"test iteracji od konca:"<<*test_iteracji3->wartosc<<std::endl; */
    element_2_kier<int> *pierwszy2 = moja_lista_2_kier.pierwszy();
    std::cout<<"pierwszy:"<<*pierwszy2->wartosc<<std::endl;
    element_2_kier<int> *ostatni2 = moja_lista_2_kier.ostatni();
    std::cout<<"ostatni:"<<*ostatni2->wartosc<<std::endl;

    std::cout<<"rozmiar:"<<moja_lista_2_kier.rozmiar()<<std::endl;

    moja_lista_2_kier.wyczysc();
    std::cout << "rozmiar po wyczyszczeniu:"<<moja_lista_2_kier.rozmiar()<<std::endl;
    std::cout << std::endl << "lista jednokierunkowa" << std::endl;

    lista<int> moja_lista;
    moja_lista.dodaj_na_poczatek(3);
    moja_lista.dodaj_na_poczatek(5);
    moja_lista.dodaj_na_poczatek(2);
    moja_lista.dodaj_na_poczatek(1);
    moja_lista.dodaj_na_koniec(9999);
    moja_lista.dodaj_na_koniec(77);



    lista<int>::iterator iter = &moja_lista;
    //iter = &moja_lista;
    lista<int>::iterator iter2;
    iter2=iter;

    element<int> *test_iteracji = iter2.iteruj(2);
    element<int> *t_iter = iter2.iteruj(test_iteracji, 1);
    std::cout<<"test iteracji:"<<*test_iteracji->wartosc<<std::endl;
    std::cout<<"test iteracji od elementu:"<<*t_iter->wartosc<<std::endl;
    t_iter = moja_lista.pierwszy();
    std::cout<<std::endl;
    for(int i=0;i<6;i++){
        std::cout << *(iter.wartosc())->wartosc << std::endl;
        iter++;
    }
    element<int> *pierwszy = moja_lista.pierwszy();
    std::cout<<"pierwszy:"<<*pierwszy->wartosc<<std::endl;
    element<int> *ostatni = moja_lista.ostatni();
    std::cout<<"ostatni:"<<*ostatni->wartosc<<std::endl;

    std::cout<<"rozmiar:"<<moja_lista.rozmiar()<<std::endl;

    std::cout << *(iter.przeszukaj(1)->wartosc) << std::endl;;

    moja_lista.wyczysc();
    std::cout<<"rozmiar po wyczyszczeniu:"<<moja_lista.rozmiar()<<std::endl;

 return 0;
}