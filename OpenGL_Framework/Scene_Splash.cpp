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
	addObject(cube);
}

void Scene_Splash::Update(){
}

void Scene_Splash::Render(){
	cube->Render();
}