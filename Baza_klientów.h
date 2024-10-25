#pragma once
#include <string>
#include "DB_connector.h"

class Baza_klient�w {
protected:
	static Baza_klient�w* instance;
	Baza_klient�w();

public:
	static Baza_klient�w* getInstance();
	int id_klienta;
	string rola;

public: bool dodajDoBazy(string aImi�, string aNazwisko, int aNumer_telefonu, string aE_mail, string aLogin, string aHas�o);

public: bool logowanie(string aLogin, string aHas�o);
};

