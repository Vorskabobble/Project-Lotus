#pragma once

#include "Model.h"
#include "ModelLoader.h"

class Skybox{
private:
	ModelLoader loader;
	Model* model;
	Vector position;
public:
	Skybox();
	~Skybox();

	void setPosition(Vector pos);
	void Render();
};

