#pragma once
#include "Scene.h"
#include <irrKlang.h>
#include "ObjCube.h"
#include "TroopCreator.h"

using namespace irrklang;

class SceneGame : public Scene{
private:
	int numEnemy;
	ObjCube** enemy;
	ObjCube* target;

	TroopCreator creator;
	PlayerTroop* player;

	bool hasTroop;
	ISoundEngine* sndEngine;
public:
	SceneGame();
	~SceneGame();

	void Initialise();
	void Update();
	void Render();
};

