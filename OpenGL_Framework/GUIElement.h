#pragma once

#include "BFont.h"
#include "GameInfo.h"
#include "Color.h"

#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>

typedef struct{
	GLdouble x;
	GLdouble y;
	GLdouble z;
}vector3;

typedef struct{
	bool used;
	float state;
}GUIState;

class GUIElement{
protected:
	bool isActive, canRender, is3D;
	float m_x, m_y, m_z, m_w, m_h;
	float m_ox, m_oy, m_oz;

	int fSize;

	std::string elementText;

	Colour m_colour;
	Colour m_subColour;
	BFont* Text;

	GUIState* state;
	GameInfo* Game;
public:
	GUIElement();
	virtual ~GUIElement();

	//set weather to process this GUI element
	void setActive(bool active);
	//set if GUI element is in the 3D world
	void set3D(bool render3D);
	//set weather to render the GUI element
	void setRender(bool render);

	//set size and font of the text
	void setFont(int size = 12, char* font = "Courier");
	//set text to display
	void setText(std::string text = "");

	//set position for both 2D and 3D positions
	void setPosition(float x, float y, float z = 1);
	//set offset from position
	void setOffset(float x, float y, float z);
	//set the width and height of the rendered box
	void setDimensions(int w, int h);
	//set the colour of the rendered box
	void setColour(Colour colour);
	//set the sub colour of the rendered box
	void setSubColour(Colour colour);

	//returns the state of the GUI element
	GUIState* getState();

	virtual bool Update() = 0;
	virtual void lRender(){};
	void Render();
	void boxRender(int x, int y, int w, int h, Colour colour);

	vector3 worldToScreen();
	bool containsMouse();
};

