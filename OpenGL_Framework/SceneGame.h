#pragma once
#include "Scene.h"
#include "SmallCastle.h"
#include "Cuboid.h"

#include "TerrainGenerator.h"
#include "Terrain.h"

#include "BRTroopCreator.h"

class SceneGame : public Scene{
private:
	SmallCastle* castle;
	TerrainGenerator* tGen;

	BRTroopCreator* spawner;
	std::vector<PlayerTroop*> barbarians;

	float spawnTimer;
	float spawnSpeed;
	float guitimer;

	Terrain* terrain;

	float gameTime;
	int numEnemies;
public:
	SceneGame();
	~SceneGame();

	void Initialise();
	void Update();
	void Render();
};

