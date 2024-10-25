#include "Baza_klient�w.h"

Baza_klient�w* Baza_klient�w::instance = nullptr;

Baza_klient�w::Baza_klient�w() {}

Baza_klient�w* Baza_klient�w::getInstance() {
	if (instance == nullptr)
	{
		instance = new Baza_klient�w();
	}
	return instance;
}


bool Baza_klient�w::dodajDoBazy(string aImi�, string aNazwisko, int aNumer_telefonu, string aE_mail, string aLogin, string aHas�o) {
	
	sql::Connection* con = DB_conn::getInstance()->con;
	sql::PreparedStatement* pstmt;

	pstmt = con->prepareStatement("INSERT INTO baza_klientow(imie, nazwisko, nr_telefonu, email, login, haslo) VALUES(?,?,?,?,?,?)");
	pstmt->setString(1, aImi�);
	pstmt->setString(2, aNazwisko);
	pstmt->setInt(3, aNumer_telefonu );
	pstmt->setString(4, aE_mail);
	pstmt->setString(5, aLogin);
	pstmt->setString(6, aHas�o);
	bool res = pstmt->execute();
	delete pstmt;
	logowanie(aLogin, aHas�o);
	return res;
}

bool Baza_klient�w::logowanie(string aLogin, string aHas�o) {

	sql::Connection* con = DB_conn::getInstance()->con;
	sql::PreparedStatement* pstmt;

	pstmt = con->prepareStatement("SELECT * FROM `baza_klientow` WHERE `login`=? AND `haslo`=?;");
	pstmt->setString(1, aLogin);
	pstmt->setString(2, aHas�o);

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