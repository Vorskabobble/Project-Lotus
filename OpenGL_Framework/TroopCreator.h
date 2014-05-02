#pragma once
#include "PlayerTroop.h"
#include "ModelLoader.h"
#include "CollisionEngine.h"

#include "PTMilitia.h"

enum TROOPTYPE{
	MILITIA = 0,
	SWORDSMAN,
	ARCHER,
	KING
};

class TroopCreator{
private:
	ModelLoader* loader;
	CollisionEngine* colEng;
public:
	TroopCreator();
	~TroopCreator();

	PlayerTroop* CreateTroop(TROOPTYPE type);
};