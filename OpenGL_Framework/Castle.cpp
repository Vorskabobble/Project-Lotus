#include "Castle.h"

Castle::Castle(){
	loader = new ModelLoader();
	collision = CollisionEngine::getInstance();
	defeated = false;
}

Castle::~Castle(){
	for (auto& level : levels){
		delete level.second;
		level.second = NULL;
	}
	levels.clear();

	if (loader){
		delete loader;
	}
}

bool Castle::Defeated(){
	return defeated;
}

void Castle::Update(){
	for (auto& level : levels){
		level.second->setGold(gold);
		level.second->Update();
		if (level.second->getName() == "throneLevel"){
			if (level.second->getOccupied() == true){
				defeated = true;
			}
		}
		setGold(level.second->getGold());
	}
}

void Castle::Render(){
	for (auto& level : levels){
		level.second->Render();
	}
}

void Castle::setGold(float gold){
	this->gold = gold;
}

float Castle::getGold(){
	return gold;
}
