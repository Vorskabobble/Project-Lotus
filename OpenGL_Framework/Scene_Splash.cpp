#include "Scene_Splash.h"


Scene_Splash::Scene_Splash(){
}

Scene_Splash::~Scene_Splash(){
	if (cube){
		delete cube;
	}
	if (menu){
		delete menu;
	}
}

void Scene_Splash::Initialise(){
	cube = new ObjCube(0.7f);
	cube->setColor(COLOR_PURPLE);
	*cube->move()->position = Vector(3.0f, 0.0f, 3.0f);
	addObject(cube);

	model = new ObjModel();

	model->LoadModel("Models/MultiObj.obj");

	*model->move()->position = Vector(0.0f, 0.0f, 3.0f);
	model->setScale(0.3f);

	mainCamera->move->setTargetDistance(10.0f);
}

void Scene_Splash::Update(){
	if (Game->INPUT.keyPressed[VK_D]){
		mainCamera->move->move(X, -1.0f);
	}
	if (Game->INPUT.keyPressed[VK_A]){
		mainCamera->move->move(X, 1.0f);
	}
	if (Game->INPUT.keyPressed[VK_T]){
		model->setScale(model->getScale() + (1.0f * Game->TIME.delta));
	}
	if (Game->INPUT.keyPressed[VK_G]){
		model->setScale(model->getScale() - (1.0f * Game->TIME.delta));
	}
	if (Game->INPUT.keyPressed[VK_W]){
		mainCamera->move->move(Z, 1.0f);

	}
	if (Game->INPUT.keyPressed[VK_S]){
		mainCamera->move->move(Z, -1.0f);
	}
	if (Game->INPUT.keyPressed[VK_Q]){
		//cube->move()->rotateBy(Y, 25.0f);
		mainCamera->move->move(Y, 1.0f);
	}
	if (Game->INPUT.keyPressed[VK_F]){
		//cube->move()->localMove(Z, 10.0f);
		mainCamera->move->move(Y, -1.0f);
		model->vertPos();
		Game->INPUT.keyPressed[VK_F] = false;
	}
	if (Game->INPUT.keyPressed[VK_SPACE]){
		Game->INPUT.keyPressed[VK_SPACE] = false;
		menu = new SceneMenu;
		director->loadScene("MenuScene", *menu);
		director->changeScene("MenuScene");
	}
	if (Game->INPUT.keyPressed[VK_P]){
		director->unloadScene("MenuScene");
		delete menu;
	}
}

void Scene_Splash::Render(){
	mainCamera->Update();
	cube->Render();
	model->Render();
}