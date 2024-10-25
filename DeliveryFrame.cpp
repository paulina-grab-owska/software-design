#include "DeliveryFrame.h"

DeliveryFrame::DeliveryFrame()
{
	at = 0;
}

DeliveryFrame::DeliveryFrame(double suma)
{
    at = 0;
    this->suma = suma;
}

void DeliveryFrame::generate_frame()
{
    system("cls");
    double a;
    cout << "\t\nWybierz opcje dostawy: " << endl;
    cout << "\t1. Paczkomat            |    11,99   | "<<(at == 0 ? " <--\n" : "\n");
    cout << "\t2. Odbior osobisty      |    0,00    |" <<(at == 1 ? " <--\n" : "\n");
    cout << "\t3. Dostawa do domu      |    16,99   |" <<(at == 2 ? " <--\n" : "\n");
}

void DeliveryFrame::handle_input()
{
    double a;
    if (at == 0) a = 11.99;
    if (at == 1) a = 0.00;
    if (at == 2) a = 16.99;
    char c = _getch();
    if (-32 == int(c)) {
        c = _getch();
        if (72 == c) {
            at--;
            if (at < 0) {
                at = 2;
            }
        }
        if (80 == c) {
            at++;
            if (at > 2) {
                at = 0;
            }
        }
        return;
    }
    if (13 == c) {
        UI::getInstance()->updateFrame(new PayFrame(suma+=a));
    }
}