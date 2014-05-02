#pragma once
#include "CastleLevel.h"
#include "TroopCreator.h"

class ThroneLevel : public CastleLevel{
private:
	Object* throne;
	PlayerTroop* kingsGaurd;
	GUIElement* troopHealth;
	TroopCreator creator;
public:
	ThroneLevel(std::string name);
	~ThroneLevel();

	//set the throne that is the main objective of the barbarians
	void setThrone(Object* obj);

	void localUpdate();
	void localRender();
};

