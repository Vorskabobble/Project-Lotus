#pragma once
#include "Scene.h"
#include "SmallCastle.h"
#include "Cuboid.h"
#include "TerrainGenerator.h"

class SceneGame : public Scene{
private:
	SmallCastle* castle;
	Cuboid* cube;
	TerrainGenerator* tGen;
public:
	SceneGame();
	~SceneGame();

	void Initialise();
	void Update();
	void Render();
};

