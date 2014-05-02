#pragma once
#include "GUIElement.h"

//displays a status bar depending on the state variable

class GUIStatus : public GUIElement{
public:
	GUIStatus();
	~GUIStatus();

	bool Update();
	void lRender();
};

