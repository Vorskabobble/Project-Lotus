#pragma once
#include "PlayerTroop.h"
class BRMilitia :
	public PlayerTroop
{
public:
	BRMilitia(int health, int attack, int armour, int defence, int range, float speed);
	~BRMilitia();

	void Collided(Collider* hitObj);
};

