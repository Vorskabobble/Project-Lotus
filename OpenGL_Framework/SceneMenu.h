#pragma once
#include "Scene.h"
#include "SceneGame.h"
//#include "ObjCube.h"

class SceneMenu : public Scene{
private:
	Object* cube;
	SceneGame* game;
public:
	SceneMenu();
	~SceneMenu();

	void Initialise();
	void Update();
	void Render();
};

