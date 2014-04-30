#pragma once
#include "PlayerTroop.h"
class PTMilitia : public PlayerTroop{
public:
	PTMilitia(int health, int attack, int armour, int defence, int range, float speed);
	~PTMilitia();

	void Collided(Collider* hitObj);
};

