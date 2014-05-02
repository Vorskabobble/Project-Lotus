#pragma once
#include "GUIElement.h"

//sets state to true if it is clicked

class GUIButton : public GUIElement{
public:
	GUIButton();
	~GUIButton();

	//checks if button is clicked
	bool Update();
};