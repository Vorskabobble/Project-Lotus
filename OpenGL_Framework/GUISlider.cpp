#include "GUISlider.h"
#include "DebugPrint.h"

GUISlider::GUISlider(){
}

GUISlider::~GUISlider(){
}

bool GUISlider::Update(){
	if (isActive){
		if (containsMouse()){
			vector3 t_pos;
			if (is3D){
				t_pos = worldToScreen();
			}
			else{
				t_pos.x = m_x;
				t_pos.y = m_y;
				t_pos.z = m_z;
			}
			if (Game->INPUT.keyPressed[VK_LBUTTON]){
				if (m_w > m_h){
					state->state = (Game->INPUT.mouseX - t_pos.x) / m_w;
				}
				else{
					state->state = (Game->INPUT.mouseY - t_pos.y) / m_h;
				}
				if (state->state > 1){
					state->state = 1;
				}
				else if (state->state < 0){
					state->state = 0;
				}
				return true;
			}
		}
	}
	return false;
}

void GUISlider::lRender(){
	vector3 t_pos;
	if (is3D){
		t_pos = worldToScreen();
	}
	else{
		t_pos.x = m_x;
		t_pos.y = m_y;
		t_pos.z = m_z;
	}
	if (m_w > m_h){
		float t_x = m_x + (m_w * state->state);
		toggleRender(t_x, t_pos.y, 10, m_h);
	}
	else{
		float t_y = m_y + (m_h * state->state);
		toggleRender(t_pos.x, t_y, m_w, 10);
	}
}

void GUISlider::toggleRender(int x, int y, int w, int h){
	glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(COLOR_BLUE.r, COLOR_BLUE.g, COLOR_BLUE.b, COLOR_BLUE.a);
		glBegin(GL_QUADS);
			glVertex2f(x, y);
			glVertex2f(x, y + h);
			glVertex2f(x + w, y + h);
			glVertex2f(x + w, y);
		glEnd();
	glDisable(GL_BLEND);
}
