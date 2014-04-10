#include "TroopCreator.h"

TroopCreator::TroopCreator(){
}

TroopCreator::~TroopCreator(){
}

PlayerTroop* TroopCreator::CreateTroop(TROOPTYPE type){
	PlayerTroop* t_troop = NULL;
	switch (type)
	{
	case MILITIA:
		t_troop = new PlayerTroop(10, 2, 1, 2, 2, 4);
		t_troop->loadModel("Models/TestPlayer.obj");
		break;
	case SWORDSMAN:
		t_troop = new PlayerTroop(20, 5, 3, 4, 3, 4);
		t_troop->loadModel("Models/TestPlayer.obj");
		break;
	case ARCHER:
		t_troop = new PlayerTroop(15, 4, 2, 2, 14, 6);
		t_troop->loadModel("Models/TestPlayer.obj");
		break;
	default:
		break;
	}
	return t_troop;
}
