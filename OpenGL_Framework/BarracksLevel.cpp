#include "BarracksLevel.h"

BarracksLevel::BarracksLevel(){
	m_spawn = NULL;
	captured = false;
	occupied = false;
	creator = new TroopCreator;
}

BarracksLevel::~BarracksLevel(){
	if (m_spawn){
		delete m_spawn;
	}
	if (creator){
		delete creator;
	}
}

void BarracksLevel::setSpawn(Vector position){
	if (!m_spawn){
		m_spawn = new Vector(0, 0, 0);
	}
	*m_spawn = position;
}

Vector BarracksLevel::getSpawn(){
	if (m_spawn){
		return *m_spawn;
	}
	return NULL;
}

void BarracksLevel::Render(){
	if (model){
		model->Render();
	}
	if (gateMod){
		gateMod->Render();
	}
	for (auto& troop : troops){
		troop->Render();
	}
}

void BarracksLevel::Update(){
	if (Game->INPUT.keyPressed[VK_B]){
		PlayerTroop* temp = creator->CreateTroop(MILITIA);
		troops.push_back(temp);
		Game->INPUT.keyPressed[VK_B] = false;
	}
	for (auto& troop : troops){
		troop->Update();
	}
}
