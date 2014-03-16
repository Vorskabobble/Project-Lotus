#include "SceneAdapter.h"

SceneAdapter::SceneAdapter(){
	manager = SceneManager::getInstance();
}

SceneAdapter::~SceneAdapter(){
	delete manager;
}

void SceneAdapter::update(){
	if (manager->getCurrentScene()){
		manager->getCurrentScene()->Update();
	}
	manager->Update();
}

void SceneAdapter::render(){
	if (manager->getCurrentScene()){
		manager->getCurrentScene()->Render();
	}
}