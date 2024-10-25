#pragma once
#include "FrameInterface.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <sstream> 
#include <vector>
#include "UI.h"
#include "zamowienie.h"
#include "DeliveryFrame.h"

using namespace std;

class OrderFrame : public FrameInterface {

    vector<Ksiazka> order;
    string adres;
    double suma;

public:

    OrderFrame(vector<Ksiazka>);

    void generate_frame();
    void handle_input();
};

