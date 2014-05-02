#include "TroopCreator.h"

TroopCreator::TroopCreator(){
	loader = new ModelLoader();
	loader->LoadModel("militia", "Models/TestPlayer.obj");
	colEng = CollisionEngine::getInstance();
}

TroopCreator::~TroopCreator(){
	if (loader){
		delete loader;
	}
}

PlayerTroop* TroopCreator::CreateTroop(TROOPTYPE type){
	PlayerTroop* t_troop = NULL;
	switch (type)
	{
	case MILITIA:
		t_troop = new PTMilitia(10, 4, 1, 2, 2, 4);
		t_troop->setModel(loader->getModel("militia"));
		t_troop->setCollider(colEng->newBoxCollider(t_troop->getMove()->getPosition(), 2, 2, 2));
		t_troop->getCollider()->setOffset(Vector(0, 1, 0));
		break;
	case SWORDSMAN:
	//	t_troop = new PlayerTroop(20, 5, 3, 4, 3, 4);
	//	t_troop->setModel(loader->getModel("militia"));
		break;
	case ARCHER:
	//	t_troop = new PlayerTroop(15, 4, 2, 2, 14, 6);
	//	t_troop->setModel(loader->getModel("militia"));
		break;
	case KING:
		t_troop = new PTMilitia(10, 7, 5, 2, 2, 2);
		t_troop->setModel(loader->getModel("militia"));
		t_troop->setCollider(colEng->newBoxCollider(t_troop->getMove()->getPosition(), 2, 4, 2));
		t_troop->getCollider()->setOffset(Vector(0, 2, 0));
	default:
		break;
	}
	return t_troop;
}
