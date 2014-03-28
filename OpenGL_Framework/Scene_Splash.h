#pragma once

#include "Scene.h"
#include "ObjCube.h"
#include "ObjModel.h"

#include <irrKlang.h>

#include "SceneMenu.h"

class Scene_Splash: public Scene{
private:
	ObjModel* model;
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

