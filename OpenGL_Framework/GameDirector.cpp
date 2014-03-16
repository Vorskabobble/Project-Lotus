#include "GameDirector.h"

GameDirector* GameDirector::instance = NULL;

GameDirector::GameDirector(){
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
	GAME_MANAGER.load = true;
	GAME_MANAGER.loadName = name;
	GAME_MANAGER.scene = &scene;
}

void GameDirector::unloadScene(std::string name){
	GAME_MANAGER.unload = true;
	GAME_MANAGER.unloadName = name;
}

void GameDirector::changeScene(std::string name){
	GAME_MANAGER.change = true;
	GAME_MANAGER.changeName = name;
}

void GameDirector::setGameInfo(std::string infoName, float value){
	m_gameInfo[infoName] = value;
}

float GameDirector::getGameInfo(std::string infoName){
	return m_gameInfo[infoName];
}