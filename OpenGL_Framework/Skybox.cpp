#include "Skybox.h"

Skybox::Skybox(){
	loader.LoadModel("skybox", "Models/UVCube.obj");
	model = loader.getModel("skybox");
	model->loadTexture("Images/sky.bmp");
}

Skybox::~Skybox(){
	loader.UnLoadModel("skybox");
	model = NULL;
}

void Skybox::setPosition(Vector pos){
	position = pos;
}

void Skybox::Render(){
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glColor3f(1, 1, 1);
		glScalef(500, 500, 500);
		model->Render();
	glPopMatrix();
	glEnable(GL_LIGHTING);
}