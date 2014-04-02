#pragma once
#include "PlayerTroop.h"

enum TROOPTYPE{
	MILITIA = 0,
	SWORDSMAN,
	ARCHER
};

class TroopCreator{
public:
	TroopCreator();
	~TroopCreator();

	PlayerTroop* CreateTroop(TROOPTYPE type);
};

