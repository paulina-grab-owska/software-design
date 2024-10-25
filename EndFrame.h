#pragma once
#include "FrameInterface.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "UI.h"
#include "ShopFrame.h"

using namespace std;

class EndFrame :
    public FrameInterface
{
public:
    int at;
    
    EndFrame();
   
    void generate_frame();
    void handle_input();
};
