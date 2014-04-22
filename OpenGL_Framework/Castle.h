#pragma once

#include "MachineLevel.h"
#include "BarracksLevel.h"
#include "ThroneLevel.h"

#include "ModelLoader.h"
#include "CollisionEngine.h"

class Castle{
protected:
	std::map<std::string, CastleLevel*> levels;

	ModelLoader* loader;
	CollisionEngine* collision;
private:
	bool defeated;
public:
	Castle();
	~Castle();

	virtual void Initialise() = 0;

	bool Defeated();

	void Update();
	void Render();
};