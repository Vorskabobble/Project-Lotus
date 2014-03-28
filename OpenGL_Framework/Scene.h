#pragma once
#include <vector>

#include "Object.h"
#include "Camera.h"
#include "GameDirector.h"
#include "GameInfo.h"
#include "key_codes.h"
#include "BFont.h"

class Scene{
private:
	std::vector<Object*> m_objects;
protected:
	GameDirector* director;
	GameInfo* Game;
	Camera* mainCamera;
public:
	Scene();
	virtual ~Scene();

	void addObject(Object* object);
	void removeObject(Object* object);
	
	virtual void Initialise() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};