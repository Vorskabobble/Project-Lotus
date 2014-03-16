#include "SceneMenu.h"


SceneMenu::SceneMenu(){

}

SceneMenu::~SceneMenu(){
	if (cube){
		delete cube;
	}
}

void SceneMenu::Initialise(){
	cube = new ObjCube(2.0);
	cube->setColor(COLOR_WHITE);
}

void SceneMenu::Update(){

}

void SceneMenu::Render(){
	cube->Render();
}