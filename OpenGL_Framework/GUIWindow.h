#pragma once

#include <map>
#include "GUIElement.h"

class GUIWindow{
private:
	bool isActive, canRender;
	std::map<std::string, GUIElement*> elements;
public:
	~GUIWindow();

	void releaseElement(std::string ID);
	GUIElement* getElement(std::string ID);

	void setActive(bool active);
	void setRender(bool render);

	bool Update();
	void Render();
private:
	void addElement(std::string ID, GUIElement* element);
	GUIWindow();

	friend class GUI;
};

