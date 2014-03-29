#include "Camera.h"


Camera::Camera(){
	move = new Move();
}

Camera::~Camera(){
	if (move){
		delete move;
	}
}

void Camera::Update(){
	move->Update();
	gluLookAt(move->position->x, move->position->y, move->position->z, move->target->x, move->target->y, move->target->z, 0.0f, 1.0f, 0.0f);
}
