#pragma once
#include <string>
#include "DB_connector.h"

class Baza_klientów {
protected:
	static Baza_klientów* instance;
	Baza_klientów();

public:
	static Baza_klientów* getInstance();
	int id_klienta;
	string rola;

public: bool dodajDoBazy(string aImiê, string aNazwisko, int aNumer_telefonu, string aE_mail, string aLogin, string aHas³o);

public: bool logowanie(string aLogin, string aHas³o);
};

