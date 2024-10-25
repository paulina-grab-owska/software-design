#pragma once

#include <iostream>
#include <cstdio>
#include <windows.h>
#include "FrameInterface.h"
#include "LoginFrame.h"
#include "ShopFrame.h"

using namespace std;

class UI
{
protected:

	static UI* instance;

	string s;

	UI();

	FrameInterface* current_frame;

public:

	static UI* getInstance();

	void updateFrame(FrameInterface* upF);

	void loop_iter(); //loop program
	void handle_inp(); // handle input
	void generate_frame(); //generating one frame 

};

