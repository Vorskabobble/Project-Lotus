#include "SceneManager.h"

SceneManager* SceneManager::single = NULL;

SceneManager::SceneManager(){
	m_curScene = NULL;
	Game = GameInfo::getInstance();
}

SceneManager::~SceneManager(){
	single = NULL;
	m_curScene = NULL;
	m_scenes.clear();
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
	if (Game->MANAGER.load){
		if (Game->MANAGER.scene){
			addScene(Game->MANAGER.loadName, Game->MANAGER.scene);
		}
		Game->MANAGER.load = false;
	}
	if (Game->MANAGER.unload){
		removeScene(Game->MANAGER.unloadName);
		Game->MANAGER.unload = false;
	}
	if (Game->MANAGER.change){
		changeScene(Game->MANAGER.changeName);
		Game->MANAGER.change = false;
	}
}