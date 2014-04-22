#include "Scene.h"

Scene::Scene(){
	director = GameDirector::getInstance();
	Game = GameInfo::getInstance();
	GUIHandle = GUI::getInstance();
	mainCamera = new Camera();
	modelLoader = new ModelLoader();
	collisionEngine = new CollisionEngine();
	
	sndEngine = createIrrKlangDevice();
	sndEngine->setSoundVolume(0.3f);
}

Scene::~Scene(){
	if (mainCamera){
		delete mainCamera;
	}
	if (modelLoader){
		delete modelLoader;
	}
	if (collisionEngine){
		delete collisionEngine;
	}
}