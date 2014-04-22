#pragma once
#include <vector>
#include <irrKlang.h>

#include "Object.h"
#include "Camera.h"
#include "GameDirector.h"
#include "GameInfo.h"
#include "GUI.h"
#include "CollisionEngine.h"
#include "ModelLoader.h"

using namespace irrklang;

class Scene{
protected:
	GameDirector* director;
	GameInfo* Game;
	GUI* GUIHandle;
	Camera* mainCamera;
	ModelLoader* modelLoader;
	CollisionEngine* collisionEngine;
	ISoundEngine* sndEngine;
public:
	Scene();
	virtual ~Scene();
	
	virtual void Initialise() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};