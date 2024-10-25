#include "WarehousemanFrame.h"


WarehousemanFrame::WarehousemanFrame()
{
    sql::PreparedStatement* pstmt;
    sql::Connection* con = DB_conn::getInstance()->con;;
    sql::ResultSet* result;

    pstmt = con->prepareStatement("SELECT * FROM test;");
    result = pstmt->executeQuery();

    while (result->next()) {

        st.push_back({
            result->getInt(1), result->getString(2), result->getInt(3), result->getString(4)
            });
    }
}

void WarehousemanFrame::zapisz_Z_db() {}

void WarehousemanFrame::generate_frame()
{
    max = 0;
    system("cls");
   
    cout << "Wyloguj" << (0 == at ? " <--" : "") << endl << endl;
    cout << "  NR ZAMOWIENIA |         TYTUL           |    ILOSC     |    ADRES          | " << endl;
    cout << "                |                         |              |                   | " << endl;


    for (int i = 0; i < st.size(); i++) {
        STRUCT s = st.at(i);
       
            max++;
            
            //nr zamówienia
            string idd = to_string(s.nr_zam);
            int d1 = idd.size();
            int il1 = (16 - d1) / 2;
            for (int i = 0; i < il1; i++)putchar(' ');
            cout << s.nr_zam;
            for (int i = 16 - d1; i > il1; i--)putchar(' ');
            putchar('|');

            //tytu³
            int d2 = s.tytul.size();
            int il2 = (25 - d2) / 2;
            for (int i = 0; i < il2; i++)putchar(' ');
            cout << s.tytul;
            for (int i = 25 - d2; i > il2; i--)putchar(' ');
            putchar('|');

            //iloœæ
            string iloscc = to_string(s.ilosc);
            int d3 = iloscc.size();
            int il3 = (14 - d3) / 2;
            for (int i = 0; i < il3; i++)putchar(' ');
            cout << s.ilosc;
            for (int i = 14 - d3; i > il3; i--)putchar(' ');
            putchar('|');

            //adres
            int d4 = s.adres.size();
            int il4 = (19 - d4) / 2;
            for (int i = 0; i < il4; i++)putchar(' ');
            cout << s.adres;
            for (int i = 19 - d4; i > il4; i--)putchar(' ');
            putchar('|');

            if (at == max) cout << " <-- ";

            cout << endl;  
    }
}

void WarehousemanFrame::handle_input()
{
    char c = _getch();
    if (-32 == int(c)) {
        c = _getch();
        if (72 == c) {
            at--;
            if (at < 0) {
                at = max;
            }
        }
        if (80 == c) {
            at++;
            if (at > max) {
                at = 0;
            }
        }
        return;
    }
    if (13 == c && 0==at) {
        UI::getInstance()->updateFrame(new LoginFrame());
    }
}
