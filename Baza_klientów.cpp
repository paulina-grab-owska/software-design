#include "Baza_klientów.h"

Baza_klientów* Baza_klientów::instance = nullptr;

Baza_klientów::Baza_klientów() {}

Baza_klientów* Baza_klientów::getInstance() {
	if (instance == nullptr)
	{
		instance = new Baza_klientów();
	}
	return instance;
}


bool Baza_klientów::dodajDoBazy(string aImiê, string aNazwisko, int aNumer_telefonu, string aE_mail, string aLogin, string aHas³o) {
	
	sql::Connection* con = DB_conn::getInstance()->con;
	sql::PreparedStatement* pstmt;

	pstmt = con->prepareStatement("INSERT INTO baza_klientow(imie, nazwisko, nr_telefonu, email, login, haslo) VALUES(?,?,?,?,?,?)");
	pstmt->setString(1, aImiê);
	pstmt->setString(2, aNazwisko);
	pstmt->setInt(3, aNumer_telefonu );
	pstmt->setString(4, aE_mail);
	pstmt->setString(5, aLogin);
	pstmt->setString(6, aHas³o);
	bool res = pstmt->execute();
	delete pstmt;
	logowanie(aLogin, aHas³o);
	return res;
}

bool Baza_klientów::logowanie(string aLogin, string aHas³o) {

	sql::Connection* con = DB_conn::getInstance()->con;
	sql::PreparedStatement* pstmt;

	pstmt = con->prepareStatement("SELECT * FROM `baza_klientow` WHERE `login`=? AND `haslo`=?;");
	pstmt->setString(1, aLogin);
	pstmt->setString(2, aHas³o);

	sql::ResultSet* res = pstmt->executeQuery();

	if (res->rowsCount() == 1)
	{
		res->next();
		this->id_klienta = res->getInt(1);
		this->rola = res->getString(8);
		return true;
	}
		
	return false;
}