#pragma once
#include "key_codes.h"
#include "utility.h"
#include "InputInfo.h"

class Input
{
private:
public:
	Input();
	~Input();

	void processKeyDown(unsigned int key);
	void processKeyUp(unsigned int key);

	void processMouseAxis(int x, int y);
};

