#pragma once
#include "GUIElement.h"

//sets state to its opposite when clicked

class GUIToggle : public GUIElement{
public:
	GUIToggle();
	~GUIToggle();

	bool Update();
	void lRender();
};

