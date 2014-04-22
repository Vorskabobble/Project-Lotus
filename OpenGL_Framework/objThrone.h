#pragma once
#include "Object.h"
class objThrone : public Object{
public:
	objThrone();
	~objThrone();

	void Collided(Collider* collider);
};

