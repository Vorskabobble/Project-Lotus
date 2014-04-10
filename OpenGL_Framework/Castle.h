#pragma once

#include "MachineLevel.h"
#include "BarracksLevel.h"
#include "ThroneLevel.h"

class Castle{
private:
	CastleLevel* throne;
	CastleLevel* barracks;
	map<std::string, CastleLevel*> levels;
public:
	Castle();
	~Castle();

	virtual void Initialise() = 0;

	bool Defeated();

	void Update();
	void Render();
};

