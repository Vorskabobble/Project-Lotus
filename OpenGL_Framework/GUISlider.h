#pragma once
#include "GUIElement.h"

//a silder bar can be dragged effecting the state variable

class GUISlider : public GUIElement{
public:
	GUISlider();
	~GUISlider();

	bool Update();
	void lRender();
};

