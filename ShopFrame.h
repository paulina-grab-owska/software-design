#pragma once
#include "FrameInterface.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <sstream> 
#include "UI.h"
#include "ksiazka.h"
#include "OrderFrame.h"

using namespace std;

class ShopFrame : public FrameInterface {

    vector<Ksiazka> vk;
    Ksiazka* pointed;
    string fraza;
    int at = 0;
    int max = 0;

public:

    ShopFrame();

    void generate_frame();
    void handle_input();
};

