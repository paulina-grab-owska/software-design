#pragma once
#include <string>
#include <vector>
#include "DB_connector.h"


class Ksiazka {

public:

    string tytul;
    string autor;
    double cena;
    int ilosc;
    int id_ksiazka;
  
public: 

    bool dodajKsiazkaDoBazy(string aTytul, string aAutor, int aIsbn, string aWydawca, int aIlosc, string aOpis, double aCena);
    bool usunKsiazke(string aTytul);
    static vector<Ksiazka> selectAll();
    void zwieksz_Il(int d_il);

    Ksiazka(string tytul_, string autor_,double cena_,int id_) :tytul(tytul_), autor(autor_),cena(cena_), id_ksiazka(id_), ilosc(0) {};
    Ksiazka();
};
