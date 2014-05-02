#pragma once
#include "CastleLevel.h"
#include "TroopCreator.h"
#include <vector>

class BarracksLevel : public CastleLevel{
private:
	Vector* m_spawn;

	float spawnWait;
	float guitimer;

	bool captured, occupied;
	TroopCreator* creator;
	vector<PlayerTroop*> troops;

	int milupgr;
public:
	BarracksLevel(std::string name);
	~BarracksLevel();
	
	//sets the spawn of the player troops
	void setSpawn(Vector position);
	
	//returns the spawn of the player troops
	Vector getSpawn();

	void localUpdate();
	void localRender();
private:
	void removeTroop(PlayerTroop* troop);
};

