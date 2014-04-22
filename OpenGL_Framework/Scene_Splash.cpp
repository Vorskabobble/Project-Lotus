#include "Scene_Splash.h"

Scene_Splash::Scene_Splash(){
	model = NULL;
	menu = NULL;
}

Scene_Splash::~Scene_Splash(){
	if (model){
		delete model;
	}
	if (menu){
		director->unloadScene("menu");
		delete menu;
	}
	if (Game){
		delete Game;
	}
	sndEngine->drop();
}

void Scene_Splash::Initialise(){
	modelLoader->LoadModel("troop", "Models/banana.obj");
	model = new Object("troop");
	model->setModel(modelLoader->getModel("troop"));
	model->getModel()->loadTexture("Images/Banana body.bmp");

	model->getMove()->getPosition().set(4.0f, 0.0f, 5.0f);
	model->setScale(0.05f);

	mainCamera->getMove()->setTargetDistance(10.0f);
	mainCamera->getMove()->getPosition().set(0, 2, 0);
	startTime = Game->TIME.current;
	director->setGameInfo("ShowDiff", 1.0f);
	
	sndEngine = createIrrKlangDevice();
	sndEngine->setSoundVolume(0.3f);

	sndEngine->play2D("Sounds/Discovery Hit.mp3");
}

void Scene_Splash::Update(){
	model->getMove()->move(X, -1.0f);
	model->Update();
	if (Game->TIME.current > startTime + 12 || Game->INPUT.keyPressed[VK_RETURN]){
		delete model;
		model = NULL;
		sndEngine->stopAllSounds();
		menu = new SceneMenu;
		director->loadScene("Menu", *menu);
		director->changeScene("Menu");
		director->setGameInfo("ShowDiff", 0.0f);
	}
	director->setGameInfo("Diff", Game->TIME.current - startTime);
}

void Scene_Splash::Render(){
	mainCamera->Update();
	model->Render();
}