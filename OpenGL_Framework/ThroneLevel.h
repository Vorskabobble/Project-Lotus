#pragma once
#include "CastleLevel.h"
#include "TroopCreator.h"

class ThroneLevel : public CastleLevel{
private:
	ObjModel* throne;
	TroopCreator* creator;
public:
	ThroneLevel();
	~ThroneLevel();

	void LoadThrone(const char* pFile);

	void Update();
	void Render();
};

