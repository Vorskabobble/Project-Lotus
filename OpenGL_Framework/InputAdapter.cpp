#include "InputAdapter.h"


InputAdapter::InputAdapter(){
	m_input = new Input;
}

InputAdapter::~InputAdapter(){
//	delete m_input;
}

void InputAdapter::processKeyDown(unsigned int key){
	m_input->processKeyDown(key);
}

void InputAdapter::processKeyUp(unsigned int key){
	m_input->processKeyUp(key);
}

void InputAdapter::processMouseMove(int x, int y){
	m_input->processMouseAxis(x, y);
}

void InputAdapter::processMouseDown(unsigned int button){
	m_input->processKeyDown(button);
}

void InputAdapter::processMouseUp(unsigned int button){
	m_input->processKeyUp(button);
}