#include "GUI.h"

// (lower Bound + ((position/width) * Range))
// example for clicking in the middle of the screen
// mouse position range is 0 to 800
// mouse click is at 400
// opengl screen coords are -1 to 1 : the range would be 2
// (-1 + ((400/800) * 2);

GUI* GUI::instance = NULL;

GUI* GUI::getInstance(){
	if (!instance){
		instance = new GUI();
	}
	return instance;
}

GUI::GUI(){
	Game = GameInfo::getInstance();
	newWindow("base", 0, 0, Game->SCREEN.width, Game->SCREEN.height);
}

GUI::~GUI(){
	for (auto& window : windows){
		delete window.second;
		window.second = NULL;
	}
	windows.clear();
	instance = NULL;
}

GUIElement* GUI::newElement(GUITYPE type, std::string ID, int x, int y, int width, int height, std::string WinID){
	GUIElement* t_el = NULL;
	if (windows[WinID]){
		GUIElementCreator creator;
		t_el = creator.createElement(type);
		t_el->setPosition(x, y);
		t_el->setDimensions(width, height);
		windows[WinID]->addElement(ID, t_el);
	}
	return t_el;
}

GUIWindow* GUI::newWindow(std::string ID, int x, int y, int width, int height){
	GUIWindow* t_window = NULL;
	if (!windows[ID]){
		t_window = new GUIWindow();
		windows[ID] = t_window;
	}
	else{
		t_window = windows[ID];
	}
	return t_window;
}

GUIWindow* GUI::getWindow(std::string ID){
	if (windows[ID]){
		return windows[ID];
	}
	else{
		return NULL;
	}
}

void GUI::ReleaseWindow(std::string ID){
	if (windows[ID] && ID != "base"){
		delete windows[ID];
		windows[ID] = NULL;
	}
}

void GUI::Update(){
	for (auto& window : windows){
		if (window.second->Update()){
			return;
		}
	}
}

void GUI::Render(){
	for (auto& window : windows){
		window.second->Render();
	}
}