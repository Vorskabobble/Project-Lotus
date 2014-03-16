#pragma once
#include <iostream>
#include <map>

#include "utility.h"
#include "Scene.h"

class SceneManager{
private:
	static SceneManager* single;
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