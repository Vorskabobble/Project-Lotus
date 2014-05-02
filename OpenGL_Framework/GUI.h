#pragma once

#include <string>
#include <map>

#include "GameInfo.h"
#include "GUIWindow.h"
#include "GUIElementCreator.h"

class GUI{
private:
	std::map<std::string, GUIWindow*> windows;
	GameInfo* Game;

	static GUI* instance;
public:
	static GUI* getInstance();
	~GUI();

	//creates a new element that is stored in the GUI instance
	GUIElement* newElement(GUITYPE type, std::string ID, int x, int y, int width, int height, std::string WinID = "base");
	//creates a window that elements can be apart of
	GUIWindow* newWindow(std::string ID, int x, int y, int width, int height);

	//returns a gui window - default is base
	GUIWindow* getWindow(std::string ID = "base");

	//releases and deletes a window - cannot release base window
	void ReleaseWindow(std::string ID);

	//updates all GUI elements and windows
	void Update();
	//renders all GUI elements and windows
	void Render();
private:
	GUI();
};