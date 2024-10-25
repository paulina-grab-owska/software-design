#pragma once
#include "FrameInterface.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Baza_klientów.h"
#include "UI.h"
#include "EndFrame.h"

using namespace std;

class PayFrame : public FrameInterface {

public:
    int at;
    double s_suma;

    PayFrame();
    PayFrame(double s);

    void generate_frame();
    void handle_input();
};
