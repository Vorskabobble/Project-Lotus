#include "SceneManager.h"

SceneManager* SceneManager::single = NULL;

SceneManager::SceneManager(){
	m_curScene = NULL;
}

SceneManager::~SceneManager(){
	single = NULL;
}

SceneManager* SceneManager::getInstance(){
	if (!single){
		single = new SceneManager();
	}
	return single;
}

bool SceneManager::addScene(std::string name, Scene* scene){
	if (m_scenes[name]){
		return false;
	}
	m_scenes[name] = scene;
	return true;
}

bool SceneManager::removeScene(std::string name){
	if (m_scenes[name]){
		m_scenes[name] = NULL;
		return true;
	}
	return false;
}

void SceneManager::changeScene(std::string name){
	if (m_scenes[name]){
		m_curScene = m_scenes[name];
		m_curScene->Initialise();
	}
}

Scene* SceneManager::getCurrentScene(){
	return m_curScene;
}

void SceneManager::Update(){
	if (GAME_MANAGER.load){
		if (GAME_MANAGER.scene){
			addScene(GAME_MANAGER.loadName, GAME_MANAGER.scene);
		}
		GAME_MANAGER.load = false;
	}
	if (GAME_MANAGER.unload){
		removeScene(GAME_MANAGER.unloadName);
		GAME_MANAGER.unload = false;
	}
	if (GAME_MANAGER.change){
		changeScene(GAME_MANAGER.changeName);
		GAME_MANAGER.change = false;
	}
}