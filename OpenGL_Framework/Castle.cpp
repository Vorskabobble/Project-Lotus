#include "Castle.h"

Castle::Castle(){
	loader = new ModelLoader();
	collision = CollisionEngine::getInstance();
	defeated = false;
}

Castle::~Castle(){
	for (auto& level : levels){
		delete level.second;
	}
	levels.clear();
}

bool Castle::Defeated(){
	return defeated;
}

void Castle::Update(){
	for (auto& level : levels){
		level.second->Update();
		if (level.second->getName() == "throneLevel"){
			if (level.second->getOccupied() == true){
				defeated = true;
			}
		}
	}
}

void Castle::Render(){
	for (auto& level : levels){
		level.second->Render();
	}
}
