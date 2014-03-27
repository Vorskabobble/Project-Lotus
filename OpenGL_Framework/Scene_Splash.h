#pragma once

#include "Scene.h"
#include "ObjCube.h"
#include "ObjModel.h"

#include "SceneMenu.h"

class Scene_Splash: public Scene{
private:
	ObjModel* model;
	SceneMenu* menu;

	float startTime;
public:
	Scene_Splash();
	~Scene_Splash();

	void Initialise();
	void Update();
	void Render();
};

