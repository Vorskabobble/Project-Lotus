#pragma once
#include "GUIElement.h"
class GUISlider : public GUIElement{
public:
	GUISlider();
	~GUISlider();

	bool Update();
	void lRender();
private:
	void toggleRender(int x, int y, int w, int h);
};

