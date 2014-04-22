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

	std::string elementText;

	Color m_color;
	Color m_subColor;
	BFont* Text;

	GUIState* state;
	GameInfo* Game;
public:
	GUIElement();
	~GUIElement();

	void setActive(bool active);
	void set3D(bool render3D);
	void setRender(bool render);

	void setFont(int size = 12, char* font = "Courier");
	void setText(std::string text = "");

	void setPosition(int x, int y, int z = 1);
	void setDimensions(int w, int h);
	void setColor(Color color);
	void setSubColor(Color color);

	GUIState* getState();

	virtual bool Update() = 0;
	virtual void lRender(){};
	void Render();
	void boxRender(int x, int y, int w, int h, Color color);

	vector3 worldToScreen();
	bool containsMouse();
};

