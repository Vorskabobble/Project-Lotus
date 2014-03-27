#include "SceneMenu.h"


SceneMenu::SceneMenu(){

}

SceneMenu::~SceneMenu(){
	if (cube){
		delete cube;
	}
}

void SceneMenu::Initialise(){
	cube = new ObjCube(0.8f);
	cube->move()->position->set(1.0f, -0.5f, -3.0f);
	cube->setColor(COLOR_BLUE);
	director->setGameInfo("Menu", 1.0f);
}

void SceneMenu::Update(){
	cube->move()->rotateBy(Y, 20.0f);
	if (Game->INPUT.keyPressed[VK_SPACE]){
		game = new SceneGame();
		director->setGameInfo("Menu", 0.0f);
		director->loadScene("Game", *game);
		director->changeScene("Game");
	}
}

void SceneMenu::Render(){
	cube->Render();
}