#pragma once
#include "PlayerTroop.h"
#include "ModelLoader.h"

enum TROOPTYPE{
	MILITIA = 0,
	SWORDSMAN,
	ARCHER
};

class TroopCreator{
private:
	ModelLoader* loader;
public:
	TroopCreator();
	~TroopCreator();

	PlayerTroop* CreateTroop(TROOPTYPE type);
};

