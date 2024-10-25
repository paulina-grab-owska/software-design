#pragma once

class FrameInterface
{
public:
	virtual void generate_frame() = 0;
	virtual void handle_input() = 0;
};

