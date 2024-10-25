#include "AdminFrame.h"


AdminFrame::AdminFrame(){
    sf = 0;
    at = 0;
    fraza = "";
    vk = Ksiazka::selectAll();
}


void AdminFrame::generate_frame() {
    system("cls");
    if (0 == sf) {
        cout << "Dodaj ksiazke do bazy" << (at == 0 ? " <--\n" : "\n");
        cout << "Usun ksiazke z bazy" << (at == 1 ? " <--\n" : "\n");
        cout << "Wyloguj" << (at == 2 ? " <--\n" : "\n");
        return;
    }
    if (1 == sf) {//dodawanie
        cout << "Tytul: " << s[0] << (at == 0 ? " <--\n" : "\n");
        cout << "Autor: " << s[1] << (at == 1 ? " <--\n" : "\n");
        cout << "ISBN: " << s[2] << (at == 2 ? " <--\n" : "\n");
        cout << "Wydawca: " << s[3] << (at == 3 ? " <--\n" : "\n");
        cout << "Ilosc: " << s[4] << (at == 4 ? " <--\n" : "\n");
        cout << "Opis: " << s[5] << (at == 5 ? " <--\n" : "\n");
        cout << "Cena: " << s[6] << (at == 6 ? " <--\n" : "\n");
        cout << "Zapisz" << s[7] << (at == 7 ? " <--\n" : "\n");
        return;
    }
    if (2 == sf) {//usuwanie
        max = 0;
        cout << "Filtrowanie: " << fraza << (0 == at ? " <--" : "") << endl << endl;
        cout << "Zapisz zmiany " << (1 == at ? " <--" : "") << endl << endl;

        cout << "           TYTUL           |           AUTOR           |    CENA    |" << endl;
        cout << "                           |                           |            |" << endl;
        
        for (int i = 0; i < vk.size(); i++) {
            Ksiazka k = vk.at(i);
            if ((k.autor.find(fraza) != std::string::npos || k.tytul.find(fraza) != std::string::npos) && k.autor.size() > 0) {
                max++;
                if (max + 1 == at)pointed = &vk.at(i);
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
                if (at == max + 1) cout << " <-- ";

                cout << endl;
            }
        }
        return;
    }
}


void AdminFrame::handle_input()
{
    char c = _getch();
    if (-32 == int(c)) {
        c = _getch();
        if (72 == c) {
            at--;
            if (at < 0) {
                if (0 == sf) { at = 2; }
                if (1 == sf) { at = 7; }
                if (2 == sf) { at = max+1; }
            }
        }
        if (80 == c) {
            at++;
            if (0 == sf) {
                if (at > 2) {
                    at = 0;
                }
            }
            if (1 == sf) {
                if (at > 7) {
                    at = 0;
                }
            }
            if (2 == sf) {
                if (at > max+1) {
                    at = 0;
                }
            }
            return;
        }
        return;
    }
    if (0 == sf) {
        if (13 == c) {
            if (at == 0) {sf = 1;at = 0; }
            if (at == 1) { sf = 2;at = 0;}
            if (at == 2) { UI::getInstance()->updateFrame(new LoginFrame()); }

        }
        return;
    }
    if (1 == sf) {
        if (13 == c) {
            if (at == 7) {
                if (!((new Ksiazka)->dodajKsiazkaDoBazy(s[0], s[1], stoi(s[2]), s[3], stoi(s[4]), s[5], stod(s[6])))) {
                    if (13 == c) {
                        sf=0;
                    }
                }
                else {
                    UI::getInstance()->updateFrame(new AdminFrame());
                }
            }
            at++;
            return;
        }
        if (8 == c) {
            s[at].pop_back();
            return;
        }
        if ('.' == c && 6 == at && !(s[6].find('.') != std::string::npos)) {
            s[6] += c;
        }
        if (c >= '0' && c <= 'z') {
            if (2 == at || 4 == at || 6 == at) {
                if (c >= '0' && c <= '9') {
                    s[at] += c;
                }
                return;
            }
            s[at] += c;
            return;
        }
    }


    if (2 == sf) {

        if (-32 == int(c)) {
            c = _getch();
            if (72 == c) {
                at--;
                if (at < 0) {
                    at = max + 1;
                }
            }
            if (80 == c) {
                at++;
                if (at > max + 1)at = 0;
            }
            return;
        }

        if (13 == c && 1 == at) {
            sf=0;
            return;
        }

        if (13 == c && 1!=at && 0!=at) {
            (new Ksiazka)->usunKsiazke(vk.at(at-2).tytul);
            vk.erase(vk.begin()+at-2);
            at--;
        }

        if (9 == c) {
            at++;
            if (at > max + 1)at = 0;
            return;
        }

        if (0 == at) {

            if (8 == c) {
                if (fraza.size() > 0) fraza.pop_back();
                return;
            }

            if (('0' <= c && 'z' >= c)) {
                fraza += c;
                return;
            }
        }
    }
}
