#pragma once
#include "GUIElement.h"
class GUISlider : public GUIElement{
public:
	GUISlider();
	~GUISlider();

	bool Update();
	void lRender();
};

