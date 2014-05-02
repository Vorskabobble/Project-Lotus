#include "GUIElement.h"
#include "DebugPrint.h"

GUIElement::GUIElement(){
	Game = GameInfo::getInstance();
	state = new GUIState{ false, 0.0f };
	isActive = true;
	is3D = false;
	canRender = true;
	elementText = "";
	m_colour = COLOUR_GRAY;
	m_subColour = COLOUR_WHITE;
	m_x = m_y = m_z = m_w = m_h = 0;
	m_ox = m_oy = m_oz = 0;

	Text = NULL;
	setFont();
}

GUIElement::~GUIElement(){
	if (state){
		delete state;
	}
	if (Text){
		delete Text;
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
	Text->setColor(COLOUR_WHITE.r, COLOUR_WHITE.g, COLOUR_WHITE.b);
	fSize = size;
}

void GUIElement::setText(std::string text){
	elementText = text;
}

void GUIElement::setPosition(float x, float y, float z){
	m_x = x + m_ox;
	m_y = y + m_oy;
	m_z = z + m_oz;
}

void GUIElement::setOffset(float x, float y, float z){
	m_ox = x;
	m_oy = y;
	m_oz = z;

	setPosition(m_x, m_y, m_z);
}

void GUIElement::setDimensions(int pixelW, int pixelH){
	m_w = pixelW;
	m_h = pixelH;
}

void GUIElement::setColour(Colour colour){
	m_colour = colour;
}

void GUIElement::setSubColour(Colour colour){
	m_subColour = colour;
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
			boxRender(t_pos.x - 2, t_pos.y - 2, m_w + 4, m_h + 4, m_colour);
			Text->printString(t_pos.x + 5, t_pos.y + fSize, (char*)elementText.c_str());	
			lRender();
		}
	}
}

void GUIElement::boxRender(int x, int y, int w, int h, Colour colour){
	glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(colour.r, colour.g, colour.b, colour.a);
		glBegin(GL_QUADS);
			glVertex2f(x, y);
			glVertex2f(x, y + h);
			glVertex2f(x + w, y + h);
			glVertex2f(x + w, y);
		glEnd();
	glDisable(GL_BLEND);
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