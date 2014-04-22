#include "Camera.h"


Camera::Camera(){
	move = new Move();
	skybox = new Skybox();
}

Camera::~Camera(){
	if (move){
		delete move;
	}
	if (skybox){
		delete skybox;
	}
}

Move* Camera::getMove(){
	return move;
}

void Camera::Update(){
	move->Update();
	skybox->setPosition(move->getPosition());
	gluLookAt(move->getPosition().x, move->getPosition().y, move->getPosition().z, move->getTarget().x, move->getTarget().y, move->getTarget().z, 0.0f, 1.0f, 0.0f);
	skybox->Render();
}