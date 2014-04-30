#include "BarracksLevel.h"

BarracksLevel::BarracksLevel(std::string name): CastleLevel(name){
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

void BarracksLevel::localUpdate(){
	if (Game->INPUT.keyPressed[VK_B]){
		PlayerTroop* temp = creator->CreateTroop(MILITIA);
		temp->getMove()->getPosition() = getPosition();
		troops.push_back(temp);
		Game->INPUT.keyPressed[VK_B] = false;
	}
	
	vector<PlayerTroop*>::iterator it;
	for (it = troops.begin(); it != troops.end(); it++){
		(*it)->Update();
	}
}

void BarracksLevel::localRender(){
	for (auto& troop : troops){
		troop->Render();
	}
}

void BarracksLevel::removeTroop(PlayerTroop* troop){
	if (troop){
		vector<PlayerTroop*>::iterator it;

		for (it = troops.begin(); it != troops.end(); it++){
			if ((*it) == troop){
				troops.erase(it);
				delete troop;
			}
		}
	}
}