#include "PlayerTroop.h"

PlayerTroop::PlayerTroop(){
	m_canMove = false;
	stats = new Stats();
	model = NULL;
	m_target = NULL;
}

PlayerTroop::PlayerTroop(int health, int attack, int armour, int defence, int range, float speed){
	stats = new Stats(0, 0, health, health, attack, attack, armour, armour, defence, defence, range, speed);
	m_canMove = false;
	model = NULL;
	m_target = NULL;
}

PlayerTroop::~PlayerTroop(){
	if (stats){
		delete stats;
	}
	if (model){
		delete model;
	}
	if (m_target){
		delete m_target;
	}
}

void PlayerTroop::setCanMove(bool canMove){
	m_canMove = canMove;
}

void PlayerTroop::setMoveTarget(Vector target){
	*m_target = target;
}

void PlayerTroop::loadModel(const char* pFile){
	if (!model){
		model = new ObjModel();
		model->LoadModel(pFile);
	}
	else{
		delete model;
		model = NULL;
		loadModel(pFile);
	}
}

bool PlayerTroop::getCanMove(){
	return m_canMove;
}

Move* PlayerTroop::move(){
	if (model){
		return model->move();
	}
	else{
		return NULL;
	}
}

Stats* PlayerTroop::getStats(){
	return stats;
}

void PlayerTroop::Render(){
	model->Render();
}

void PlayerTroop::Update(){
	if (m_canMove && m_target){
		if (model->move()->position > m_target - 1 || model->move()->position < m_target + 1){
			if (model->move()->position->x < m_target->x){
				model->move()->move(X, stats->getSpeed());
			}
			else{
				model->move()->move(X, -stats->getSpeed());
			}
			if (model->move()->position->y < m_target->y){
				model->move()->move(Y, stats->getSpeed());
			}
			else{
				model->move()->move(Y, -stats->getSpeed());
			}
			if (model->move()->position->z < m_target->z){
				model->move()->move(Z, stats->getSpeed());
			}
			else{
				model->move()->move(Z, -stats->getSpeed());
			}
		}
	}
}

void PlayerTroop::Upgrade(float percent){
	stats->setMaxHealth(stats->getMaxHealth() * percent);
	stats->setMaxAttack(stats->getMaxAttack() * percent);
	stats->setMaxArmour(stats->getMaxArmour() * percent);
	stats->setMaxDefence(stats->getMaxDefence() * percent);

	stats->setHealth(stats->getHealth() * percent);
	stats->setAttack(stats->getAttack() * percent);
	stats->setArmour(stats->getArmour() * percent);
	stats->setDefence(stats->getDefence() * percent);

	stats->setRange(stats->getRange() * percent);
	stats->setSpeed(stats->getSpeed() * percent);
	stats->setLevel(stats->getLevel() + 1);
}

void PlayerTroop::ResolveBattle(PlayerTroop* enemy){
	if (stats->getAttack() > enemy->getStats()->getDefence()){
		int damage = stats->getAttack();
		damage -= enemy->getStats()->getArmour();
		enemy->DealDamage(damage);
	}
}

void PlayerTroop::DealDamage(int damage){
	stats->setHealth(stats->getHealth() - damage);
}