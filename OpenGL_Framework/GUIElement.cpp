#include "GUIElement.h"
#include "DebugPrint.h"

GUIElement::GUIElement(){
	Game = GameInfo::getInstance();
	state = new GUIState{ false, 0.0f };
	isActive = true;
	is3D = false;
	canRender = true;
	elementText = "";
	m_color = COLOR_ORANGE;
	m_x = m_y = m_z = m_w = m_h = 0;

	Text = new BFont(Game->SCREEN.hDC, "Courier", 12);
}

GUIElement::~GUIElement(){
	if (state){
		delete state;
	}
	if (Text){
		delete Text;
	}
	if (elementText){
//		delete elementText;
	}
}

void GUIElement::setActive(bool active){
	isActive = active;
}

void GUIElement::set3D(bool render3D){
	is3D = render3D;
}

void GUIElement::setRender(bool render){
	canRender = render;
}

void GUIElement::setFont(int size, char* font){
	if (Text){
		delete Text;
	}
	Text = new BFont(Game->SCREEN.hDC, font, size);
	Text->setColor(COLOR_WHITE.r, COLOR_WHITE.g, COLOR_WHITE.b);
}

void GUIElement::setText(char* text){
	elementText = text;
}

void GUIElement::setPosition(int x, int y, int z){
	m_x = x;
	m_y = y;
	m_z = z;
}

void GUIElement::setDimensions(int pixelW, int pixelH){
	m_w = pixelW;
	m_h = pixelH;
}

void GUIElement::setColor(Color color){
	m_color = color;
}

GUIState* GUIElement::getState(){
	return state;
}

void GUIElement::Render(){
	if (canRender){
		vector3 t_pos;
		if (is3D){
			t_pos = worldToScreen();
		}
		else{
			t_pos.x = m_x;
			t_pos.y = m_y;
			t_pos.z = m_z;
		}

		if (t_pos.z > 0  && t_pos.z <= 1){
			glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glColor4f(m_color.r, m_color.g, m_color.b, m_color.a);
				glBegin(GL_QUADS);
					glVertex2f(t_pos.x, t_pos.y);
					glVertex2f(t_pos.x, t_pos.y + m_h);
					glVertex2f(t_pos.x + m_w, t_pos.y + m_h);
					glVertex2f(t_pos.x + m_w, t_pos.y);
				glEnd();
			glDisable(GL_BLEND);

			Text->printString(t_pos.x, t_pos.y + 12, elementText);
			
			lRender();
		}
	}
}

vector3 GUIElement::worldToScreen(){
	vector3 t_vect = { 0, 0, 0 };
	glEnable(GL_DEPTH_TEST);
	gluProject(m_x, m_y, m_z, Game->GL.modelView, Game->GL.projection, Game->GL.viewport, &t_vect.x, &t_vect.y, &t_vect.z);
	t_vect.y = Game->SCREEN.height - t_vect.y;
	glDisable(GL_DEPTH_TEST);

 	return t_vect;
}

bool GUIElement::containsMouse(){
	vector3 t_pos;
	if (is3D){
		t_pos = worldToScreen();
	}
	else{
		t_pos.x = m_x;
		t_pos.y = m_y;
		t_pos.z = m_z;
	}
	if (Game->INPUT.mouseX > t_pos.x && Game->INPUT.mouseX < t_pos.x + m_w){
		if (Game->INPUT.mouseY > t_pos.y && Game->INPUT.mouseY < t_pos.y + m_h){
			return true;
		}
	}
	return false;
}