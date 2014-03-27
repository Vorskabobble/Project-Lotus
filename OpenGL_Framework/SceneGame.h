#pragma once
#include "Scene.h"
#include <irrKlang.h>
#include "ObjCube.h"

using namespace irrklang;

class SceneGame : public Scene{
private:
	int numEnemy;
	ObjCube** enemy;
	ObjCube* troop;
	ObjCube* target;

	bool hasTroop;
	ISoundEngine* sndEngine;
public:
	SceneGame();
	~SceneGame();

	void Initialise();
	void Update();
	void Render();
};

