#pragma once
#include "FrameInterface.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Baza_klientów.h"
#include "UI.h"
#include "ShopFrame.h"
#include "AdminFrame.h"
#include "WarehousemanFrame.h"

using namespace std;

class LoginFrame : public FrameInterface {

public:

    string s[6];

    int sf;
    int at;

    LoginFrame();

    void generate_frame();
    void handle_input();
};

