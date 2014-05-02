#include "PTMilitia.h"

PTMilitia::PTMilitia(int health, int attack, int armour, int defence, int range, float speed) : PlayerTroop(health, attack, armour, defence, range, speed, "troop"){
}

PTMilitia::~PTMilitia(){
}

void PTMilitia::Collided(Collider* hitObj){
	if (hitObj->getAttachedObject()->getName() == "barbarian"){
		ResolveBattle(dynamic_cast<PlayerTroop*>(hitObj->getAttachedObject()));
		getMove()->stop();
	}
}