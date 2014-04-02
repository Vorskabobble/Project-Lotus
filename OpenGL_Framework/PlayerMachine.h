#pragma once

#include "Stats.h"
#include "ObjModel.h"

class PlayerMachine{
private:
	ObjModel* model;
	Stats* stats;
public:
	PlayerMachine();
	PlayerMachine(int health, int attack, int defence, int range, int speed);
	~PlayerMachine();

	Vector getPos();
	Vector getRot();

	Stats* getStats();

	void setPos(Vector position);
	void setRot(Vector rotation);

	void DealDamage(int damage);
	void LoadModel(const char* pFile);
	void Upgrade(float percent);
};

