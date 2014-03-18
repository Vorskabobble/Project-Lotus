#pragma once
#include <iostream>
#include <map>

#include "GameInfo.h"
#include "Scene.h"

class SceneManager{
private:
	static SceneManager* single;
	GameInfo* Game;
	std::map<std::string, Scene*> m_scenes;
	
	Scene *m_curScene;
public:
	~SceneManager();
	static SceneManager* getInstance();

	bool addScene(std::string name, Scene* scene);
	bool removeScene(std::string name);
	void changeScene(std::string name);

	Scene* getCurrentScene();
	
	void Update();
private:
	SceneManager();
};