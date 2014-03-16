#pragma once
#include "Scene.h"

#include "ObjCube.h"

class SceneMenu : public Scene{
private:
	ObjCube* cube;
public:
	SceneMenu();
	~SceneMenu();

	void Initialise();
	void Update();
	void Render();
};

