#include "Input.h"

Input::Input(){
	Game = GameInfo::getInstance();
}

Input::~Input(){
}

void Input::processKeyDown(unsigned int key){
	Game->INPUT.keyPressed[key] = true;
}

void Input::processKeyUp(unsigned int key){
	Game->INPUT.keyPressed[key] = false;
}

void Input::processMouseAxis(int x, int y){
	Game->INPUT.mouseX = x;
	Game->INPUT.mouseY = y;
}