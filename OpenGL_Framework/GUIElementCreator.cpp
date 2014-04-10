#include "GUIElementCreator.h"

GUIElementCreator::GUIElementCreator(){
}

GUIElementCreator::~GUIElementCreator(){
}

GUIElement* GUIElementCreator::createElement(GUITYPE type){
	GUIElement*  t_el = NULL;
	switch (type)
	{
	case BUTTON:
		t_el = new GUIButton();
		break;
	case SLIDER:
		t_el = new GUISlider();
		break;
	case TOGGLE:
		t_el = new GUIToggle();
		break;
	case STATUS:
		t_el = new GUIStatus();
		break;
	default:
		break;
	}
	return t_el;
}
