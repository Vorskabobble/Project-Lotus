#include "SceneMenu.h"


SceneMenu::SceneMenu(){
	cube = NULL;
	game = NULL;
}

SceneMenu::~SceneMenu(){
	if (cube){
		delete cube;
	}
	if (game){
		delete game;
	}
}

void SceneMenu::Initialise(){
	modelLoader->LoadModel("cube", "Models/cube.obj");
	cube = new Object("cube");
	cube->setModel(modelLoader->getModel("cube"));
	cube->getModel()->loadTexture("Images/sky.bmp");
	cube->getMove()->getPosition().set(2.0f, -0.5f, -6.0f);
//	cube->setColor(COLOR_BLUE);
	director->setGameInfo("Menu", 1.0f);
}

void SceneMenu::Update(){
	cube->getMove()->rotateBy(Y, 20.0f);
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