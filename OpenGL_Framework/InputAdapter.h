#pragma once
#include "key_codes.h"
#include "Input.h"

class InputAdapter{
private:
	Input* m_input;
public:
	InputAdapter();
	~InputAdapter();

	void processKeyDown(unsigned int key);
	void processKeyUp(unsigned int key);
	void processMouseMove(int x, int y);
	void processMouseDown(unsigned int button);
	void processMouseUp(unsigned int button);
};

