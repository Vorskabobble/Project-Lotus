#include "BRMilitia.h"

BRMilitia::BRMilitia(int health, int attack, int armour, int defence, int range, float speed) : PlayerTroop(health, attack, armour, defence, range, speed, "barbarian"){
}

BRMilitia::~BRMilitia(){
}

void BRMilitia::Collided(Collider* hitObj){
	if (hitObj->getAttachedObject()->getName() == "gate"){
		getMove()->stop();
		hitObj->getAttachedObject()->getStats()->setHealth(hitObj->getAttachedObject()->getStats()->getHealth() - ((getStats()->getAttack() / 2) * Game->TIME.delta));
	}
	if (hitObj->getAttachedObject()->getName() == "troop"){
		ResolveBattle(dynamic_cast<PlayerTroop*>(hitObj->getAttachedObject()));
		getMove()->stop();
	}
}