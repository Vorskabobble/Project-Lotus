#pragma once

#include "Object.h"

class PlayerMachine : public Object{
private:
public:
	PlayerMachine();
	PlayerMachine(int health, int attack, int defence, int range, int speed);
	~PlayerMachine();

	void DealDamage(int damage);
	void Upgrade(float percent);

	void localUpdate();
	void localRender();
};

