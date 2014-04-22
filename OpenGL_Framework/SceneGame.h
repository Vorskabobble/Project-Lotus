#pragma once
#include "Scene.h"
#include "SmallCastle.h"

class SceneGame : public Scene{
private:
	SmallCastle* castle;
public:
	SceneGame();
	~SceneGame();

	void Initialise();
	void Update();
	void Render();
};

