#include "GUIWindow.h"

GUIWindow::GUIWindow(){
	canRender = true;
}

GUIWindow::~GUIWindow(){
	for (auto& element : elements){
		delete element.second;
		element.second = NULL;
	}
	elements.clear();
}

void GUIWindow::releaseElement(std::string ID){
	if (elements[ID]){
		delete elements[ID];
		elements[ID] = NULL;
	}
}

GUIElement* GUIWindow::getElement(std::string ID){
	if (elements[ID]){
		return elements[ID];
	}
	else{
		return NULL;
	}
}

void GUIWindow::setActive(bool active){
	isActive = active;
}

void GUIWindow::setRender(bool render){
	canRender = render;
}

bool GUIWindow::Update(){
	if (isActive){
		for (auto& element : elements){
			if(element.second->Update()){
				return true;
			}
		}
	}
	return false;
}

void GUIWindow::Render(){
	if (canRender){
		for (auto& element : elements){
			element.second->Render();
		}
	}
}

void GUIWindow::addElement(std::string ID, GUIElement* element){
	if (!elements[ID]){
		elements[ID] = element;
	}
}