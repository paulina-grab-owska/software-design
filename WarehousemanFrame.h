#pragma once
#include "FrameInterface.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <sstream> 
#include <string>
#include "UI.h"
#include "ksiazka.h"
#include "OrderFrame.h"
#include "LoginFrame.h"

using namespace std;

typedef struct STRUCT{
    int nr_zam;
    string tytul;
    int ilosc;
    string adres;
};


class WarehousemanFrame : public FrameInterface {

public: 

    int nr_zam, ilosc;
    string tytul, adres;

    vector<STRUCT> st;

    int at = 0;
    int max = 0;

public:

    WarehousemanFrame();

    void generate_frame();
    void handle_input();
    void zapisz_Z_db();
};
