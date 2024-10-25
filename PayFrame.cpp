#include "PayFrame.h"


PayFrame::PayFrame()
{
	at = 0;
}


PayFrame::PayFrame(double s)
{
	at = 0;
	s_suma = s;
}

void PayFrame::generate_frame()
{
	system("cls");
    
	cout << "Kwota do zaplaty: " << s_suma << endl;
    
    cout << "Wybierz forme zaplaty: " << endl;
    cout << "		platnosc gotowka przy odbiorze " << (at == 0 ? " <--\n" : "\n");
    cout << "		blik " << (at == 1 ? " <--\n" : "\n");
    cout << "		przelew tradycyjny " << (at == 2 ? " <--\n" : "\n");
}


void PayFrame::handle_input()
{
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
        UI::getInstance()->updateFrame(new EndFrame());
    }
}