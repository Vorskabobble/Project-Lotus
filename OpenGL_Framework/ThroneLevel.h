#pragma once
#include "CastleLevel.h"
#include "TroopCreator.h"

class ThroneLevel : public CastleLevel{
private:
	Object* throne;
	PlayerTroop* kingsGaurd;
	GUIElement* troopHealth;
public:
	ThroneLevel(std::string name);
	~ThroneLevel();

	void setThrone(Object* obj);

	void localUpdate();
	void localRender();
};

