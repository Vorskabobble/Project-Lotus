#pragma once

#include "Scene.h"
#include "ObjCube.h"
#include "ObjModel.h"

#include "SceneMenu.h"

class Scene_Splash: public Scene{
	ObjCube* cube;
	ObjModel* model;
	SceneMenu* menu;
public:
	Scene_Splash();
	~Scene_Splash();

	void Initialise();
	void Update();
	void Render();
};

