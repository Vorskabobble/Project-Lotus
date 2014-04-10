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
	model = new ObjModel();
	model->LoadModel("Models/TestPlayer.obj");

	*model->move()->position = Vector(3.0f, -1.0f, 3.0f);
	model->setScale(0.3f);

	mainCamera->move->setTargetDistance(10.0f);
	startTime = Game->TIME.current;
	director->setGameInfo("ShowDiff", 1.0f);
	
	sndEngine = createIrrKlangDevice();
	sndEngine->setSoundVolume(0.3f);

	sndEngine->play2D("Sounds/Discovery Hit.mp3");
}

void Scene_Splash::Update(){
	model->move()->move(X, -0.6f);
	if (Game->TIME.current > startTime + 2){
		delete model;
		model = NULL;
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