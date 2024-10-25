#include "ShopFrame.h"


ShopFrame::ShopFrame()
{
    vk = Ksiazka::selectAll();
    fraza = "";
}

void ShopFrame::generate_frame()
{
    max = 0;
    system("cls");
    cout << "Witaj w Sklepie!" << endl << endl;

    cout << "Filtrowanie: " << fraza << (0 == at ? " <--" : "") << endl << endl;

    cout << "Zatwierdz zamowienie " <<  (1 == at ? " <--" : "") << endl << endl;


    cout << "           TYTUL           |           AUTOR           |    CENA    | Il. w koszyku |" << endl;
    cout << "                           |                           |            |               |" << endl;

    for (int i = 0; i < vk.size(); i++) {
        Ksiazka k = vk.at(i);
        if ((k.autor.find(fraza) != std::string::npos || k.tytul.find(fraza) != std::string::npos) && k.autor.size() > 0) {
            max++;
            if (max+1 == at)pointed = &vk.at(i);
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
            if (at == max+1) cout << " <-- ";

            cout << endl;
        }
    }
    
}

void ShopFrame::handle_input()
{
    char c = _getch();

    if (-32 == int(c) ) {
        c = _getch();
        if (72 == c) {
            at--;
            if (at < 0) {
                at = max+1;
            }
        }
        if (80 == c) {
            at++;
            if (at > max+1)at = 0;
        }

        if (77 == c && at > 1) {
            pointed->zwieksz_Il(1);
        }
        if (75 == c && at > 1) {
            if(pointed->ilosc > 0)
                pointed->zwieksz_Il(-1);
        }
        return;
    }
    if (13 == c && at == 1) {
        UI::getInstance()->updateFrame(new OrderFrame(vk));
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
