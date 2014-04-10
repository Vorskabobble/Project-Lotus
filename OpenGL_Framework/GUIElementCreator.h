#pragma once
#include "GUIElement.h"
#include "GUIButton.h"
#include "GUISlider.h"
#include "GUIToggle.h"
#include "GUIStatus.h"

enum GUITYPE{
	BUTTON = 0,
	SLIDER,
	TOGGLE,
	STATUS
};

class GUIElementCreator{
public:
	GUIElementCreator();
	~GUIElementCreator();

	GUIElement* createElement(GUITYPE type);
};

