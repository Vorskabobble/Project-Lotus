#pragma once
#include "GUIElement.h"
class GUIStatus : public GUIElement{
public:
	GUIStatus();
	~GUIStatus();

	bool Update();
	void lRender();
private:
	void barRender(int x, int y, int w, int h);
};

