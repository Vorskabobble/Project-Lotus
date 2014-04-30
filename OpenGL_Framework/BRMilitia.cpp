#include "BRMilitia.h"

BRMilitia::BRMilitia(int health, int attack, int armour, int defence, int range, float speed) : PlayerTroop(health, attack, armour, defence, range, speed, "barbarian"){
}

BRMilitia::~BRMilitia(){
}

void BRMilitia::Collided(Collider* hitObj){
	if (hitObj->getAttachedObject()->getName() == "gate"){
		getMove()->stop();
	}
}