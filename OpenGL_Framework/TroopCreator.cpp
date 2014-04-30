#include "TroopCreator.h"

TroopCreator::TroopCreator(){
	loader = new ModelLoader();
	loader->LoadModel("militia", "Models/TestPlayer.obj");
	colEng = CollisionEngine::getInstance();
}

TroopCreator::~TroopCreator(){
}

PlayerTroop* TroopCreator::CreateTroop(TROOPTYPE type){
	PlayerTroop* t_troop = NULL;
	switch (type)
	{
	case MILITIA:
		t_troop = new PTMilitia(10, 2, 1, 2, 2, 4);
		t_troop->setModel(loader->getModel("militia"));
		t_troop->setCollider(colEng->newBoxCollider(t_troop->getMove()->getPosition(), 1, 1, 1));
		break;
	case SWORDSMAN:
	//	t_troop = new PlayerTroop(20, 5, 3, 4, 3, 4);
	//	t_troop->setModel(loader->getModel("militia"));
		break;
	case ARCHER:
	//	t_troop = new PlayerTroop(15, 4, 2, 2, 14, 6);
	//	t_troop->setModel(loader->getModel("militia"));
		break;
	default:
		break;
	}
	return t_troop;
}
