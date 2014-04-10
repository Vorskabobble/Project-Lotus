#include "Castle.h"

Castle::Castle(){
}

Castle::~Castle(){
	if (throne){
		delete throne;
	}
	if (barracks){
		delete barracks;
	}
	for (auto& level : levels){
		delete level.second;
	}
	levels.clear();
}

bool Castle::Defeated(){
	return throne->getOccupied();
}

void Castle::Update(){
	throne->Update();
	barracks->Update();
	for (auto& level : levels){
		level.second->Update();
	}
}

void Castle::Render(){
	throne->Render();
	barracks->Render();
	for (auto& level : levels){
		level.second->Render();
	}
}
