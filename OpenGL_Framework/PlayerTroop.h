#pragma once

#include "OBjModel.h"
#include "Stats.h"

class PlayerTroop{
private:
	bool m_canMove;
	Stats* stats;

	ObjModel* model;
	Vector* m_target;
public:
	PlayerTroop();
	PlayerTroop(int health, int attack, int armour, int defence, int range, float speed);
	~PlayerTroop();

	void setCanMove(bool canMove);
	void setMoveTarget(Vector target);

	void loadModel(const char* pFile);

	bool getCanMove();

	Move* move();
	Stats* getStats();

	void Render();
	void Update();
	void Upgrade(float percent);
	void ResolveBattle(PlayerTroop* enemy);
	void DealDamage(int damage);
};

