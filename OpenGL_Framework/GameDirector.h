#pragma once
#include <stdlib.h>
#include <map>
#include "utility.h"

class GameDirector{
private:
	static GameDirector* instance;
	std::map<std::string, float> m_gameInfo;
public:
	~GameDirector();
	static GameDirector* getInstance();

	void loadScene(std::string name, Scene& scene);
	void unloadScene(std::string name);
	void changeScene(std::string name);

	void setGameInfo(std::string infoName, float value);
	float getGameInfo(std::string infoName);

private:
	GameDirector();
};

