#pragma once
#include <string>
#include <vector>
#include "DB_connector.h"
#include "ksiazka.h"


class Zamowienie {

public:

    vector<Ksiazka> ksiazki;
    string adres;

    Zamowienie* dodajKsiazke(const Ksiazka& ksiazka) {
        ksiazki.push_back(ksiazka);
        return this;
    }

    Zamowienie* ustaw_adres(string s) {
        this->adres = s;
        return this;
    }

    Zamowienie* ustaw_ksiazki(vector<Ksiazka> vk) {
        this->ksiazki = vk;
        return this;
    }

    void zapisz_w_db() {
        sql::Connection* con = DB_conn::getInstance()->con;
        sql::PreparedStatement* pstmt;

        pstmt = con->prepareStatement("INSERT INTO baza_zam(adres, id_klienta) VALUES(?,?)");
        pstmt->setString(1, adres);
        pstmt->setInt(2, Baza_klientów::getInstance()->id_klienta);
        bool res = pstmt->execute();

        pstmt = con->prepareStatement("SELECT LAST_INSERT_ID();");
        sql::ResultSet* res2 = pstmt->executeQuery();

        res2->next();
        int id_z = res2->getInt(1);

        for (Ksiazka k : ksiazki) {
            pstmt = con->prepareStatement("INSERT INTO inf_zam(id_zam, id_ksiazka, ilosc) VALUES(?,?,?);");
            pstmt->setInt(1, id_z);
            pstmt->setInt(2, k.id_ksiazka);
            pstmt->setInt(3, k.ilosc);
            bool res = pstmt->execute();
        }

        delete pstmt;
    }
};

class Platnosc {

public:
    double kwota;

    Platnosc(double kwota_) : kwota(kwota_) {}
};
