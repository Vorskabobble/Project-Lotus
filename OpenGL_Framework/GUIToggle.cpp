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

void GUIToggle::lRender(){
	if (canRender){
		if (state->state){
			vector3 t_pos;
			if (is3D){
				t_pos = worldToScreen();
			}
			else{
				t_pos.x = m_x;
				t_pos.y = m_y;
				t_pos.z = m_z;
			}
			if (t_pos.z > 0 && t_pos.z <= 1){
				boxRender(t_pos.x, t_pos.y, m_w, m_h, m_subColor);
			}
		}
	}
}