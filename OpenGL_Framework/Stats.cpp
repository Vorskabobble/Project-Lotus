#include "Stats.h"

Stats::Stats(){
	m_level = 1;
	m_playerID = 1;
	m_health = 1;
	m_maxHealth = 1;
	m_attack = 1;
	m_maxAttack = 1;
	m_armour = 1;
	m_maxArmour = 1;
	m_defence = 1;
	m_maxDefence = 1;
	m_maxRange = 1;
	m_maxSpeed = 1;
}

Stats::Stats(int level, int playerID, int health, int maxHealth, int attack, int maxAttack, int armour, int maxArmour, int defence, int maxDefence, int range, int speed){
	m_level = level;
	m_playerID = playerID;
	m_health = health;
	m_maxHealth = maxHealth;
	m_attack = attack;
	m_maxAttack = maxAttack;
	m_armour = armour;
	m_maxArmour = maxArmour;
	m_defence = defence;
	m_maxDefence = maxDefence;
	m_maxRange = range;
	m_maxSpeed = speed;
}


Stats::~Stats(){

}

void Stats::setLevel(int level){
	m_level = level;
}

void Stats::setPlayerID(int playerID){
	m_playerID = playerID;
}

void Stats::setHealth(float health){
	m_health = health;
}

void Stats::setMaxHealth(float health){
	m_maxHealth = health;
}

void Stats::setAttack(float attack){
	m_attack = attack;
}

void Stats::setMaxAttack(float attack){
	m_maxAttack = attack;
}

void Stats::setArmour(float armour){
	m_armour = armour;
}

void Stats::setMaxArmour(float armour){
	m_maxArmour = armour;
}

void Stats::setDefence(float defence){
	m_defence = defence;
}

void Stats::setMaxDefence(float defence){
	m_maxDefence = defence;
}

void Stats::setRange(float range){
	m_maxRange = range;
}

void Stats::setSpeed(float speed){
	m_maxSpeed = speed;
}

int Stats::getLevel(){
	return m_level;
}

float Stats::getHealth(){
	return m_health;
}

float Stats::getMaxHealth(){
	return m_maxHealth;
}

float Stats::getAttack(){
	return m_attack;
}

float Stats::getMaxAttack(){
	return m_maxAttack;
}

float Stats::getArmour(){
	return m_armour;
}

float Stats::getMaxArmour(){
	return m_maxArmour;
}

float Stats::getDefence(){
	return m_defence;
}

float Stats::getMaxDefence(){
	return m_maxDefence;
}

float Stats::getRange(){
	return m_maxRange;
}

float Stats::getSpeed(){
	return m_maxSpeed;
}