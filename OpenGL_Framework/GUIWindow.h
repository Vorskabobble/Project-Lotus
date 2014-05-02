#pragma once

#include <map>
#include "GUIElement.h"

//container for GUI elements

class GUIWindow{
private:
	bool isActive, canRender;
	
	std::map<std::string, GUIElement*> elements;
public:
	~GUIWindow();

	//deletes memory of GUI element
	void releaseElement(std::string ID);
	//returns specified GUI element if it exists
	GUIElement* getElement(std::string ID);

	//set whether to process this window and its elements
	void setActive(bool active);
	//set whether to render this window and its elements
	void setRender(bool render);

	bool Update();
	void Render();
private:
	void addElement(std::string ID, GUIElement* element);
	GUIWindow();

	friend class GUI;
};

