#include "inc/graf_m.hh"
#include "inc/graf_l.hh"
#include "inc/dijkstra.hh"
#include "inc/losowanie_grafu.hh"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <ctime>
#include <chrono>


int main(){

    std::string nazwa_pliku_losowanego;
    //std::string nazwa_pliku_wyniku_lista;
    //std::string nazwa_pliku_wyniku_macierz;
    std::ofstream czasy_mac;
    std::ofstream czasy_lista;
    std::ofstream czasy_por_rep;
    std::chrono::high_resolution_clock::time_point start, koniec;
    double trwanie;

    czasy_mac.open("wyniki/mac.csv");
    if(czasy_mac.is_open() == false){
        std::cout << "BLAD: plik sie nie otworzyl" << std::endl;
        return 1;
    }
    czasy_lista.open("wyniki/lista.csv");
    if(czasy_lista.is_open() == false){
        std::cout << "BLAD: plik sie nie otworzyl" << std::endl;
        return 1;
    }
    czasy_por_rep.open("wyniki/porownanie.csv");
    if(czasy_por_rep.is_open() == false){
        std::cout << "BLAD: plik sie nie otworzyl" << std::endl;
        return 1;
    }

    int rozmiar[5] = {10, 30, 60, 100, 150};
    for(int gestosc=0;gestosc<4;gestosc++){
        czasy_mac << "typ gestosci;" << gestosc << ";" 
            << "rozmiary;" << std::endl
            << rozmiar[0] << ";" << rozmiar[1] << ";"
            << rozmiar[2] << ";" << rozmiar[3] << ";"
            << rozmiar[4] << ";" << std::endl;
        czasy_lista << "typ gestosci;" << gestosc << ";" 
            << "rozmiary;" << std::endl
            << rozmiar[0] << ";" << rozmiar[1] << ";"
            << rozmiar[2] << ";" << rozmiar[3] << ";"
            << rozmiar[4] << ";" << std::endl;
        czasy_por_rep << "typ gestosci;" << gestosc << ";" 
            << "lista;macierz;"
            << "rozmiary;" << std::endl
            << rozmiar[0] << ";" << rozmiar[0] << ";"
            << rozmiar[1] << ";" << rozmiar[1] << ";"
            << rozmiar[2] << ";" << rozmiar[2] << ";"
            << rozmiar[3] << ";" << rozmiar[3] << ";"
            << rozmiar[4] << ";" << rozmiar[4] << ";" << std::endl;
        for(int powtorzenie=0;powtorzenie<100;powtorzenie++){
            for(int indeks_rozmiaru=0; indeks_rozmiaru<5; indeks_rozmiaru++){
            
                nazwa_pliku_losowanego = "grafy/graf_" 
                    + std::to_string(rozmiar[indeks_rozmiaru]) 
                    + "_" + std::to_string(gestosc)
                    + "_powt" + std::to_string(powtorzenie);
                losuj_graf(rozmiar[indeks_rozmiaru], nazwa_pliku_losowanego, gestosc);

                std::ifstream plik;
                lista_sasiedztwa<int, int> graf_l;
                plik.open(nazwa_pliku_losowanego);
                if(plik.is_open() == false){
                    std::cout << "BLAD: plik sie nie otworzyl" << std::endl;
                    return 1;
                }
                plik >> graf_l;
                plik.close();

                wynik moj_wynik_l;
                int wielkosc = graf_l.wierzcholki()->rozmiar();
                moj_wynik_l.droga = new int[wielkosc];
                moj_wynik_l.poprzednik = new int[wielkosc];
                moj_wynik_l.wielkosc = wielkosc;

                start = std::chrono::high_resolution_clock::now(); 
                dijkstra_l(&graf_l, &moj_wynik_l); 
                koniec = std::chrono::high_resolution_clock::now();
                trwanie = std::chrono::duration<double, std::milli>(koniec-start).count();
                czasy_lista << trwanie << ";";
                czasy_por_rep << trwanie << ";";

                wynik moj_wynik_m;
                moj_wynik_m.droga = new int[wielkosc];
                moj_wynik_m.poprzednik = new int[wielkosc];
                moj_wynik_m.wielkosc = wielkosc;   

                mac_sasiedztwa<int, int> graf_m;
                plik.open(nazwa_pliku_losowanego);
                if(plik.is_open() == false){
                    std::cout << "BLAD: plik sie nie otworzyl" << std::endl;
                    return 1;
                }
                plik >> graf_m;
                plik.close();

                start = std::chrono::high_resolution_clock::now();
                dijkstra_m(&graf_m, &moj_wynik_m); 
                koniec = std::chrono::high_resolution_clock::now();
                trwanie = std::chrono::duration<double, std::milli>(koniec-start).count();
                czasy_mac << trwanie << ";";
                czasy_por_rep << trwanie << ";";


                //std::ofstream plik2;
                //plik2.open(nazwa_pliku_wyniku);
                //if(plik2.is_open() == false){
                //    std::cout << "BLAD: plik sie nie otworzyl" << std::endl;
                //    return 1;
                //}
                //plik2 << moj_wynik_l;
            }
            czasy_lista << std::endl;
            czasy_mac << std::endl;
            czasy_por_rep << std::endl;
        }
        czasy_lista << std::endl << std::endl;
        czasy_mac << std::endl << std::endl;
        czasy_por_rep << std::endl << std::endl;
    }

    czasy_lista.close();
    czasy_mac.close();
    czasy_por_rep.close();

 return 0;
}