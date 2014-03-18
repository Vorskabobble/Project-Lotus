#include "GameDirector.h"

GameDirector* GameDirector::instance = NULL;

GameDirector::GameDirector(){
	Game = GameInfo::getInstance();
}

GameDirector::~GameDirector(){
	instance = NULL;
}

GameDirector* GameDirector::getInstance(){
	if (!instance){
		instance = new GameDirector();
	}
	return instance;
}

void GameDirector::loadScene(std::string name, Scene& scene){
	Game->MANAGER.load = true;
	Game->MANAGER.loadName = name;
	Game->MANAGER.scene = &scene;
}

void GameDirector::unloadScene(std::string name){
	Game->MANAGER.unload = true;
	Game->MANAGER.unloadName = name;
}

void GameDirector::changeScene(std::string name){
	Game->MANAGER.change = true;
	Game->MANAGER.changeName = name;
}

void GameDirector::setGameInfo(std::string infoName, float value){
	m_gameInfo[infoName] = value;
}

float GameDirector::getGameInfo(std::string infoName){
	return m_gameInfo[infoName];
}