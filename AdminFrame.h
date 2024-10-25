#pragma once
#include "FrameInterface.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <sstream> 
#include "Baza_klientów.h"
#include "UI.h"
#include "ksiazka.h"
#include "LoginFrame.h"

using namespace std;

class AdminFrame : public FrameInterface {

public:

    vector<Ksiazka> vk;
    Ksiazka* pointed;
    string s[8];
    string fraza;

    int at;
    int sf;
    int max;

    AdminFrame();

    void generate_frame();
    void handle_input();
};