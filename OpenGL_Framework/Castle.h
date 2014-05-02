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

	float gold;
private:
	bool defeated;
public:
	Castle();
	virtual ~Castle();

	virtual void Initialise() = 0;

	//returns true when the throne level is occupied
	bool Defeated();

	void Update();
	void Render();

	//pass a gold value for purchases in the castle
	void setGold(float gold);
	//returns updated gold after castle update
	float getGold();
};