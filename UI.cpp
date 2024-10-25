#include "UI.h"

UI* UI::instance = nullptr;

UI::UI() {
	this->current_frame = new LoginFrame();
}

UI* UI::getInstance() {
	if (instance == nullptr)
	{
		instance = new UI();
	}
	return instance;
}

void UI::updateFrame(FrameInterface* upF)
{
	current_frame = upF;
}

void UI::loop_iter() {
	this->generate_frame();
	this->handle_inp();
	this->loop_iter();
}

void UI::generate_frame() {
	current_frame->generate_frame();
}

void UI::handle_inp() {
	current_frame->handle_input();
}