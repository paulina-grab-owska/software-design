#pragma once
#include "FrameInterface.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Baza_klientów.h"
#include "UI.h"
#include "PayFrame.h"
#include "OrderFrame.h"


using namespace std;

class DeliveryFrame :
    public FrameInterface
{
public:
    int at;
    string adres;
    double suma;

    DeliveryFrame();
    DeliveryFrame(double suma);

    void generate_frame();
    void handle_input();
};







