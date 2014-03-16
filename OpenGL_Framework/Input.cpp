#include "Input.h"

Input::Input(){
}

Input::~Input(){
}

void Input::processKeyDown(unsigned int key){
	GAME_INPUT.keyPressed[key] = true;
}

void Input::processKeyUp(unsigned int key){
	GAME_INPUT.keyPressed[key] = false;
}

void Input::processMouseAxis(int x, int y){
	GAME_INPUT.mouseX = x;
	GAME_INPUT.mouseY = y;
}