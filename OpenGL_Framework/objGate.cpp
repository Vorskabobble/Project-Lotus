#include "objGate.h"

objGate::objGate() : Object("gate"){
}

objGate::~objGate(){
}

void objGate::Collided(Collider* collider){
	if (collider->getAttachedObject()->getName() == "barbarian"){
	}
}
