#pragma once

#include "Object.h"
#include "Stats.h"

class PlayerTroop : public Object{
private:
	Vector* m_target;
public:
	PlayerTroop();
	PlayerTroop(int health, int attack, int armour, int defence, int range, float speed, std::string name);
	~PlayerTroop();

	void setMoveTarget(Vector target);

	virtual void localUpdate(){};
	virtual void localRender(){};

	virtual void Collided(Collider* hitObj) = 0;

	void Upgrade(float percent);
	void ResolveBattle(PlayerTroop* enemy);
	void DealDamage(int damage);
};

