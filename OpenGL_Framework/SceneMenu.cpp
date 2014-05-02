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
		director->unloadScene("Game");
		delete game;
	}
}

void SceneMenu::Initialise(){
	modelLoader->LoadModel("cube", "Models/cube.obj");
	cube = new Object("cube");
	cube->setModel(modelLoader->getModel("cube"));
	cube->getModel()->loadTexture("Images/sky.bmp");
	cube->getMove()->getPosition().set(2.0f, -0.5f, -6.0f);

	//set GUI for the scene menu
	GUIHandle->newWindow("menu", 0, 0, Game->SCREEN.width, Game->SCREEN.height);
	GUIHandle->newElement(BUTTON, "start", Game->SCREEN.width / 2 - 77.5, Game->SCREEN.height/2 - 37.5, 155, 75, "menu");
	GUIHandle->getWindow("menu")->getElement("start")->setFont(50);
	GUIHandle->getWindow("menu")->getElement("start")->setText("Start");
}

void SceneMenu::Update(){
	if (game){
		delete game;
		game = NULL;
	}
	GUIHandle->getWindow("menu")->setActive(true);
	GUIHandle->getWindow("menu")->setRender(true);
	cube->getMove()->rotateBy(Y, 20.0f);

	//change scene if button is clicked
	if (GUIHandle->getWindow("menu")->getElement("start")->getState()->used){
		game = new SceneGame();
		director->setGameInfo("Menu", 0.0f);
		director->loadScene("Game", *game);
		director->changeScene("Game");
		GUIHandle->getWindow("menu")->setActive(false);
		GUIHandle->getWindow("menu")->setRender(false);
		GUIHandle->getWindow("menu")->getElement("start")->getState()->used = false;
	}
}

void SceneMenu::Render(){
	cube->Render();
}