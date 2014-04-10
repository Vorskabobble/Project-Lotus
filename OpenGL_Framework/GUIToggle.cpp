#include "GUIToggle.h"

GUIToggle::GUIToggle(){
}

GUIToggle::~GUIToggle(){
}

bool GUIToggle::Update(){
	if (isActive){
		if (containsMouse()){
			if (Game->INPUT.keyPressed[VK_LBUTTON]){
				state->used = !state->used;
				Game->INPUT.keyPressed[VK_LBUTTON] = false;
				return true;
			}
		}
	}
	return false;
}