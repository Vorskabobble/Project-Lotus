#include "GUIButton.h"
#include "DebugPrint.h"

GUIButton::GUIButton(){
}

GUIButton::~GUIButton(){
}

bool GUIButton::Update(){
	state->used = false;
	if (isActive){
		if (containsMouse()){
			if (Game->INPUT.keyPressed[VK_LBUTTON]){
				state->used = true;
				Game->INPUT.keyPressed[VK_LBUTTON] = false;
				return true;
			}
		}
	}
	return false;
}