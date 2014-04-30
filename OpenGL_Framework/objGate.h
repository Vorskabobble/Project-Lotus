#pragma once
#include "Object.h"
class objGate : public Object{
public:
	objGate();
	~objGate();

	void Collided(Collider* collider);
};

