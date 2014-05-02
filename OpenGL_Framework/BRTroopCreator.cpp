#include "BRTroopCreator.h"


BRTroopCreator::BRTroopCreator(){
	loader = new ModelLoader();
	loader->LoadModel("militia", "Models/TestPlayer.obj");
	colEng = CollisionEngine::getInstance();
}


BRTroopCreator::~BRTroopCreator(){
	if (loader){
		delete loader;
	}
}

PlayerTroop* BRTroopCreator::CreateTroop(BRTROOPTYPE type){
	PlayerTroop* t_troop = NULL;
	switch (type)
	{
	case BRMILITIA:
		t_troop = new BRMilitia(10, 3, 1, 2, 2, 4);
		t_troop->setModel(loader->getModel("militia"));
		t_troop->setCollider(colEng->newBoxCollider(t_troop->getMove()->getPosition(), 2, 2, 2));
		t_troop->getCollider()->setOffset(Vector(0, 1, 0));
		break;
	case BRSWORDSMAN:
		//	t_troop = new PlayerTroop(20, 5, 3, 4, 3, 4);
		//	t_troop->setModel(loader->getModel("militia"));
		break;
	case BRARCHER:
		//	t_troop = new PlayerTroop(15, 4, 2, 2, 14, 6);
		//	t_troop->setModel(loader->getModel("militia"));
		break;
	default:
		break;
	}
	return t_troop;
}
