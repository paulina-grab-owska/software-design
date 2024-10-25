#include "OrderFrame.h"


OrderFrame::OrderFrame(vector<Ksiazka> v)
{
	for (Ksiazka k : v) {
		if(k.ilosc > 0)
		order.push_back(k);
	}
}


void OrderFrame::generate_frame()
{
	system("cls");
    double sumaa = 0;
    cout << endl;
    cout << "Adres dostawy: "<< adres <<" <--"<< endl << endl;

	cout << "           TYTUL           |           AUTOR           |    CENA    | Il. w koszyku |    SUMA    |" << endl;
	cout << "                           |                           |            |               |            |" << endl;
    
    for (int i = 0; i < order.size(); i++) {
        Ksiazka k = order.at(i);
            int s1 = k.tytul.size();
            int s2 = k.autor.size();
            int il = (27 - s1) / 2;
            for (int i = 0; i < il; i++)putchar(' ');
            cout << k.tytul;
            for (int i = 27 - s1; i > il; i--)putchar(' ');
            putchar('|');
            il = (27 - s2) / 2;
            for (int i = 0; i < il; i++)putchar(' ');
            cout << k.autor;
            for (int i = 27 - s2; i > il; i--)putchar(' ');
            putchar('|');
            ostringstream ss;
            ss << k.cena;
            string cen = ss.str();
            int s3 = cen.size();
            il = (12 - s3) / 2;
            for (int i = 0; i < il; i++)putchar(' ');
            cout << cen;
            for (int i = 12 - s3; i > il; i--)putchar(' ');
            putchar('|');
            string count = to_string(k.ilosc);
            int s4 = count.size();
            il = (15 - s4) / 2;
            for (int i = 0; i < il; i++)putchar(' ');
            cout << count;
            for (int i = 15 - s4; i > il; i--)putchar(' ');
            putchar('|');
            ostringstream ssc;
            ssc << k.cena * k.ilosc;
            sumaa += k.cena * k.ilosc;
            string cen_sum = ssc.str();
            int s5 = cen_sum.size();
            il = (12 - s5) / 2;
            for (int i = 0; i < il; i++)putchar(' ');
            cout << cen_sum;
            for (int i = 12 - s5; i > il; i--)putchar(' ');
            putchar('|');
            cout << endl;   
    }
    cout << "====================================================================================|            |" << endl;
    cout << "                                   SUMA CALKOWITA                                   |";
    
    ostringstream sumc;
    sumc << sumaa;
    string s_suma = sumc.str();
    int s6 = s_suma.size();
    int il = (12 - s6) / 2;
    for (int i = 0; i < il; i++)putchar(' ');
    cout << s_suma;
    for (int i = 12 - s6; i > il; i--)putchar(' ');
    cout << "|" << endl;
    this->suma = sumaa;
}

void OrderFrame::handle_input()
{
	char c = _getch();
    if (-32 == int(c)) {
        c = _getch();
        return;
    }
    if (13 == c) {
        (new Zamowienie())
            ->ustaw_adres(adres)
            ->ustaw_ksiazki(order)
            ->zapisz_w_db();
        UI::getInstance()->updateFrame(new DeliveryFrame(suma));
    }
    if (8 == c) {
        if (adres.size() > 0) adres.pop_back();
        return;
    }
    if (('0' <= c && 'z' >= c)) {
        adres += c;
        return;
    }
}
