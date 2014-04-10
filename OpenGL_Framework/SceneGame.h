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

	GUIElement* spawnButton;
	GUIElement* playerHealth;
	GUIElement* troopHealth;

	bool hasTroop;
	ISoundEngine* sndEngine;
public:
	SceneGame();
	~SceneGame();

	void Initialise();
	void Update();
	void Render();
};

