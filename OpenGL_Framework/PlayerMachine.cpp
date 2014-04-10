#include "PlayerMachine.h"


PlayerMachine::PlayerMachine(){
}

PlayerMachine::PlayerMachine(int health, int attack, int defence, int range, int speed){
	stats = new Stats(0, 0, health, health, attack, attack, defence, defence, defence, defence, range, speed);
	model = NULL;
}

PlayerMachine::~PlayerMachine(){
}

Vector PlayerMachine::getPos(){
	return *model->move()->position;
}

Vector PlayerMachine::getRot(){
	return *model->move()->rotation;
}

Stats* PlayerMachine::getStats(){
	return stats;
}

void PlayerMachine::setPos(Vector position){
	model->move()->position->set(position.x, position.y, position.z);
}

void PlayerMachine::setRot(Vector rotation){
	model->move()->position->set(rotation.x, rotation.y, rotation.z);
}

void PlayerMachine::DealDamage(int damage){
	stats->setHealth(stats->getHealth() - damage);
}

void PlayerMachine::LoadModel(const char* pFile){
	if (!model){
		model = new ObjModel();
		model->LoadModel(pFile);
	}
	else{
		delete model;
		model = NULL;
		LoadModel(pFile);
	}
}


void PlayerMachine::Upgrade(float percent){
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

void PlayerMachine::Render(){
	if (model){
		model->Render();
	}
}