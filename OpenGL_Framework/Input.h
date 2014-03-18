#pragma once
#include "key_codes.h"
#include "GameInfo.h"
#include "InputInfo.h"

class Input
{
private:
	GameInfo* Game;
public:
	Input();
	~Input();

	void processKeyDown(unsigned int key);
	void processKeyUp(unsigned int key);

	void processMouseAxis(int x, int y);
};

