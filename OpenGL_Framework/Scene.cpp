#include "Scene.h"

Scene::Scene(){
	director = GameDirector::getInstance();
	Game = GameInfo::getInstance();
	GUIHandle = GUI::getInstance();
	mainCamera = new Camera();
	modelLoader = new ModelLoader();
	collisionEngine = CollisionEngine::getInstance();
	
	//sndEngine = createIrrKlangDevice();
	//sndEngine->setSoundVolume(0.3f);
}

Scene::~Scene(){
	if (mainCamera){
		delete mainCamera;
	}
	if (modelLoader){
		delete modelLoader;
	}
}