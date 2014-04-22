#include "PlayerMachine.h"


PlayerMachine::PlayerMachine(){
}

PlayerMachine::PlayerMachine(int health, int attack, int defence, int range, int speed){
	getStats()->setHealth(health);
	getStats()->setAttack(attack);
	getStats()->setDefence(defence);
	getStats()->setRange(range);
	getStats()->setSpeed(speed);

	getStats()->setMaxHealth(health);
	getStats()->setMaxAttack(attack);
	getStats()->setMaxDefence(defence);
}

PlayerMachine::~PlayerMachine(){
}

void PlayerMachine::DealDamage(int damage){
	getStats()->setHealth(getStats()->getHealth() - damage);
}

void PlayerMachine::Upgrade(float percent){
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

void PlayerMachine::localUpdate(){

}

void PlayerMachine::localRender(){

}