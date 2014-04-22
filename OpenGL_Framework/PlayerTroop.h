#pragma once

#include "Object.h"
#include "Stats.h"

class PlayerTroop : public Object{
private:
	Vector* m_target;
public:
	PlayerTroop();
	PlayerTroop(int health, int attack, int armour, int defence, int range, float speed);
	~PlayerTroop();

	void setMoveTarget(Vector target);

	void localUpdate();
	void localRender();
	void Upgrade(float percent);
	void ResolveBattle(PlayerTroop* enemy);
	void DealDamage(int damage);
};

