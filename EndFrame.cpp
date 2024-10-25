#include "EndFrame.h"

EndFrame::EndFrame()
{
    at = 0;
}


void EndFrame::generate_frame()
{
    system("cls");

    cout << "Dziekujemy za zlozenie zamowienia. Zamowienie zostalo przekazane do realizacji" << endl << endl;

    cout << "Powrot do sklepu" << (at == 0 ? " <--\n" : "\n");
    cout << "Wyjdz" << (at == 1 ? " <--\n" : "\n");
}


void EndFrame::handle_input()
{
    char c = _getch();
    if (-32 == int(c)) {
        c = _getch();
        if (72 == c) {
            at--;
            if (at < 0) {
                at = 1;
            }
        }
        if (80 == c) {
            at++;
            if (at > 1) {
                at = 0;
            }
        }
        return;
    }
    if (13 == c && 0 == at) {
        UI::getInstance()->updateFrame(new ShopFrame());
    }
    if (13 == c && 1 == at) {
        exit(0);
    }
}