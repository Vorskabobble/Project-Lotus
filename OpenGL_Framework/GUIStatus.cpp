#include "GUIStatus.h"

GUIStatus::GUIStatus(){
}

GUIStatus::~GUIStatus(){
}

bool GUIStatus::Update(){
	if (state->state > 1.0f){
		state->state = 1.0f;
	}
	else if (state->state < 0){
		state->state = 0;
	}
	return false;
}

void GUIStatus::lRender(){
	vector3 t_pos;
	if (is3D){
		t_pos = worldToScreen();
	}
	else{
		t_pos.x = m_x;
		t_pos.y = m_y;
		t_pos.z = m_z;
	}
	int t_w = m_w;
	if (t_w < 0){
		t_w = -t_w;
	}
	int t_h = m_h;
	if (t_h < 0){
		t_h = -t_h;
	}
	if (t_w > t_h){
		if (m_w > 0){
			float t_w = m_w * state->state;
			boxRender(t_pos.x, t_pos.y, t_w, m_h, m_subColor);
		}
		else{
			float t_w = -m_w * state->state;
			boxRender(t_pos.x - t_w, t_pos.y, t_w, m_h, m_subColor);
		}
	}
	else{
		if (m_h > 0){
			float t_h = m_h * state->state;
			boxRender(t_pos.x, t_pos.y, m_w, t_h, m_subColor);
		}
		else{
			float t_h = m_h * state->state;
			boxRender(t_pos.x, t_pos.y - t_h, m_w, m_h, m_subColor);
		}
	}
}
