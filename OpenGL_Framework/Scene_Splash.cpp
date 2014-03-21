#include "Scene_Splash.h"


Scene_Splash::Scene_Splash(){
}

Scene_Splash::~Scene_Splash(){
	if (cube){
		delete cube;
	}
}

void Scene_Splash::Initialise(){
	cube = new ObjCube(0.7f);
	cube->setColor(COLOR_PURPLE);
	*cube->move()->position = Vector(0.0f, 0.0f, 3.0f);
	addObject(cube);

	mainCamera->move->setTargetDistance(10.0f);
}

void Scene_Splash::Update(){
	if (Game->INPUT.keyPressed[VK_D]){
		mainCamera->move->move(X, -1.0f);
	}
	if (Game->INPUT.keyPressed[VK_A]){
		mainCamera->move->move(X, 1.0f);
	}
	if (Game->INPUT.keyPressed[VK_W]){
		mainCamera->move->move(Y, 1.0f);
	}
	if (Game->INPUT.keyPressed[VK_S]){
		mainCamera->move->move(Y, -1.0f);
	}
	if (Game->INPUT.keyPressed[VK_Q]){
		cube->move()->rotateBy(Y, 25.0f);
	}
	if (Game->INPUT.keyPressed[VK_F]){
		cube->move()->localMove(Z, 10.0f);
	}
}

void Scene_Splash::Render(){
	mainCamera->Update();
	cube->Render();
}