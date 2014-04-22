#pragma once

#include "Scene.h"

#include <irrKlang.h>

#include "SceneMenu.h"

class Scene_Splash: public Scene{
private:
	Object* model;
	SceneMenu* menu;
	ISoundEngine* sndEngine;
	float startTime;
public:
	Scene_Splash();
	~Scene_Splash();

	void Initialise();
	void Update();
	void Render();
};

