#pragma once
#include "SceneManager.h"

class SceneAdapter{
private:
	SceneManager* manager;
public:
	SceneAdapter();
	~SceneAdapter();

	void update();
	void render();
};

