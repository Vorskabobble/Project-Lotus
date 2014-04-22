#pragma once
#include "GUIElement.h"
class GUIStatus : public GUIElement{
public:
	GUIStatus();
	~GUIStatus();

	bool Update();
	void lRender();
};

