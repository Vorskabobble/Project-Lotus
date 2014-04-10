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

	GUIElement* newElement(GUITYPE type, std::string ID, int x, int y, int width, int height, std::string WinID = "base");
	GUIWindow* newWindow(std::string ID, int x, int y, int width, int height);

	GUIWindow* getWindow(std::string ID);

	void ReleaseWindow(std::string ID);

	void Update();
	void Render();
private:
	GUI();
};