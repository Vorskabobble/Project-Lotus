#include "PlayerTroop.h"

PlayerTroop::PlayerTroop(){
	m_target = NULL;
}

PlayerTroop::PlayerTroop(int health, int attack, int armour, int defence, int range, float speed){
	getStats()->setHealth(health);
	getStats()->setAttack(attack);
	getStats()->setArmour(armour);
	getStats()->setDefence(defence);
	getStats()->setRange(range);
	getStats()->setSpeed(speed);

	getStats()->setMaxHealth(health);
	getStats()->setMaxAttack(attack);
	getStats()->setMaxArmour(armour);
	getStats()->setMaxDefence(defence);

	m_target = NULL;
}

PlayerTroop::~PlayerTroop(){
	if (m_target){
		delete m_target;
	}
}


void PlayerTroop::setMoveTarget(Vector target){
	if (!m_target){
		m_target = new Vector();
	}
	*m_target = target;
}

void PlayerTroop::localUpdate(){

}

void PlayerTroop::localRender(){
}

void PlayerTroop::Upgrade(float percent){
	getStats()->setMaxHealth(getStats()->getMaxHealth() * percent);
	getStats()->setMaxAttack(getStats()->getMaxAttack() * percent);
	getStats()->setMaxArmour(getStats()->getMaxArmour() * percent);
	getStats()->setMaxDefence(getStats()->getMaxDefence() * percent);

	getStats()->setHealth(getStats()->getHealth() * percent);
	getStats()->setAttack(getStats()->getAttack() * percent);
	getStats()->setArmour(getStats()->getArmour() * percent);
	getStats()->setDefence(getStats()->getDefence() * percent);

	getStats()->setRange(getStats()->getRange() * percent);
	getStats()->setSpeed(getStats()->getSpeed() * percent);
	getStats()->setLevel(getStats()->getLevel() + 1);
}

void PlayerTroop::ResolveBattle(PlayerTroop* enemy){
	if (getStats()->getAttack() > enemy->getStats()->getDefence()){
		int damage = getStats()->getAttack();
		damage -= enemy->getStats()->getArmour();
		enemy->DealDamage(damage);
	}
}

void PlayerTroop::DealDamage(int damage){
	getStats()->setHealth(getStats()->getHealth() - damage);
}