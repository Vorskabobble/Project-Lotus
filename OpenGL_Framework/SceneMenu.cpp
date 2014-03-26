#include "SceneMenu.h"


SceneMenu::SceneMenu(){

}

SceneMenu::~SceneMenu(){
	if (cube){
		delete cube;
	}
}

void SceneMenu::Initialise(){
	cube = new ObjCube(1.0f);
	cube->move()->position->set(0.0f, 0.0f, -3.0f);
	cube->setColor(COLOR_WHITE);
}

void SceneMenu::Update(){
	if (Game->INPUT.keyPressed[VK_SPACE]){
		Game->INPUT.keyPressed[VK_SPACE] = false;
		director->changeScene("splash");
	}
}

void SceneMenu::Render(){
	cube->Render();
}