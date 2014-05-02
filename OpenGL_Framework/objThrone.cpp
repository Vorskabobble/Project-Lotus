#include "objThrone.h"

objThrone::objThrone() : Object("throne"){
}

objThrone::~objThrone(){
}

void objThrone::Collided(Collider* collider){
	if (collider->getAttachedObject()->getName() == "barbarian"){
		getStats()->setHealth(0.0f);
	}
}