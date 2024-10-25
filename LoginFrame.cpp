#include "LoginFrame.h"


LoginFrame::LoginFrame()
{
    sf = 0;
    at = 0;
}


void LoginFrame::generate_frame()
{
    system("cls");

    if (0 == sf) {
        cout << "LOGOWANIE" << (at == 0 ? " <--\n" : "\n"); 
        cout << "REJESTRACJA" << (at == 1 ? " <--\n" : "\n");

        return;
    }

    if (1 == sf) {
        cout << "Login: " << s[4] << (at == 0 ? " <--\n" : "\n");
        cout << "Haslo: " << s[5] << (at == 1 ? " <--\n" : "\n");

        return;
    }

    if (2 == sf) {
        cout << "Imie: " << s[0] << (at == 0 ? " <--\n" : "\n");
        cout << "Nazwisko: " << s[1] << (at == 1 ? " <--\n" : "\n");
        cout << "Numer telefonu: " << s[2] << (at == 2 ? " <--\n" : "\n");
        cout << "Email: " << s[3] << (at == 3 ? " <--\n" : "\n");
        cout << "Login: " << s[4] << (at == 4 ? " <--\n" : "\n");
        cout << "Haslo: " << s[5] << (at == 5 ? " <--\n" : "\n");
        return;
    }

    if (3 == sf) {
        cout << "Poprawnie zaresjestrowano"<<endl<<endl;
        cout << "Przejdz do logowania  <--\n" << (at == 0);
        return;
    }
}


void LoginFrame::handle_input()
{
    char c = _getch();
    if (-32 == int(c)) {
        c = _getch();
        if (72 == c) {
            at--;
            if (at < 0) {
                if (0 == sf)at = 1;
                if (1 == sf)at = 1;
                if (2 == sf)at = 5;
                if (3 == sf)at = 0;
            }
        }
        if (80 == c) {
            at++;
            if (0 == sf && at > 1)at = 0;
            if (1 == sf && at > 1)at = 0;
            if (2 == sf && at > 5)at = 0;
            if (3 == sf && at > 0)at = 0;
        }
        return;
    }
    if (0 == sf) {
        if (13 == c && 0 == at) {
            sf = 1;
        }
        if (13 == c && 1 == at) {
            sf = 2;
        }
    }
    if (1 == sf) {
        if (9 == c) {
            at++;
            if (at > 1)at = 0;
            return;
        }
        if (13 == c) {
            if (at == 1) {
                if (!Baza_klientów::getInstance()->logowanie(s[4], s[5]))
                    sf = 3;
                else {
                   if( "USER" == Baza_klientów::getInstance()->rola ) UI::getInstance()->updateFrame(new ShopFrame());
                   if ("ADMIN" == Baza_klientów::getInstance()->rola) UI::getInstance()->updateFrame(new AdminFrame());
                   if ("WAR" == Baza_klientów::getInstance()->rola) UI::getInstance()->updateFrame(new WarehousemanFrame());
                }
                return;
            }
            at++;
            return;
        }
        if (8 == c) {
            if( s[4 + at].size()>0 ) s[4 + at].pop_back();
            return;
        }
        if (('0' <= c && 'z' >= c)) {
            s[4 + at] += c;
            return;
        }
    }
    if (2 == sf) {
        if (9 == c) {
            at++;
            if (at > 5)at = 0;
            return;
        }
        if (13 == c) {
            if (at == 5) {
                if (!Baza_klientów::getInstance()->dodajDoBazy(s[0], s[1], stoi(s[2]), s[3], s[4], s[5]))
                    sf = 3;
                else {
                    if ("USER" == Baza_klientów::getInstance()->rola)UI::getInstance()->updateFrame(new ShopFrame());            
                }
                return;
            }
            at++;
            return;
        }
        if (8 == c) {
            s[at].pop_back();
            return;
        }
        if (2 == at)
            if (c >= '0' && c <= '9') {
                s[at] += c;
                return;
            }
        if (c >= '0' && c <= 'z') {
            s[at] += c;
            return;
        }
        return;
    }
    if (3 == sf) {
        if (13 == c && at == 0) {
         UI::getInstance()->updateFrame(new LoginFrame());
        } 
    }
    return;
}
