#include "ksiazka.h"


bool Ksiazka::dodajKsiazkaDoBazy(string aTytul, string aAutor, int aIsbn, string aWydawca, int aIlosc, string aOpis, double aCena) {
	sql::Connection* con = DB_conn::getInstance()->con;
	sql::PreparedStatement* pstmt;


	pstmt = con->prepareStatement("INSERT INTO baza_ksiazek(Tytul, Autor, ISBN, Wydawca, Ilosc, Opis, Cena) VALUES(?,?,?,?,?,?,?)");
	pstmt->setString(1, aTytul);
	pstmt->setString(2, aAutor);
	pstmt->setInt(3, aIsbn);
	pstmt->setString(4, aWydawca);
	pstmt->setInt(5, aIlosc);
	pstmt->setString(6, aOpis);
	pstmt->setDouble(7, aCena);
	bool res = pstmt->execute();
	delete pstmt;
	return res;
}


bool Ksiazka::usunKsiazke(string aTytul) {
	sql::Connection* con = DB_conn::getInstance()->con;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("DELETE  FROM baza_ksiazek WHERE `baza_ksiazek`.`Tytul`=?;");
	pstmt->setString(1, aTytul);
	bool res = pstmt->execute();
	delete pstmt;
}


vector<Ksiazka> Ksiazka::selectAll()
{
	vector<Ksiazka> vk;

	sql::Connection* con = DB_conn::getInstance()->con;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;

	pstmt = con->prepareStatement("SELECT * FROM baza_ksiazek;");
	result = pstmt->executeQuery();

	while (result->next()) {
		string name = result->getString(2);
		if (name.length() == 0)continue;
		vk.push_back(
			Ksiazka(name, result->getString(3), result->getDouble(8),result->getInt(1))
		);
	}
	return vk;
}

void Ksiazka::zwieksz_Il(int d_il)
{
	ilosc += d_il;
}

Ksiazka::Ksiazka(){}
