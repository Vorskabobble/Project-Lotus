#pragma once
#include "CastleLevel.h"
#include "TroopCreator.h"
#include <vector>

class BarracksLevel : public CastleLevel{
private:
	Vector* m_spawn;
	bool captured, occupied;
	TroopCreator* creator;
	vector<PlayerTroop*> troops;
public:
	BarracksLevel();
	~BarracksLevel();
	
	void setSpawn(Vector position);
	
	Vector getSpawn();

	void Render();
	void Update();
};

