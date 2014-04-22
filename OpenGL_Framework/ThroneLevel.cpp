#include "ThroneLevel.h"

ThroneLevel::ThroneLevel(std::string name): CastleLevel(name){
	troopHealth = guiHandle->newElement(STATUS, "throneHealth", 0, 0, 100, 10, name);
	troopHealth->setRender(false);
	troopHealth->set3D(true);
	kingsGaurd = NULL;
	throne = NULL;
}


ThroneLevel::~ThroneLevel(){
}

void ThroneLevel::setThrone(Object* obj){
	throne = obj;
}

void ThroneLevel::localUpdate(){
	if (model && model->getCollider()){

	}
	if (kingsGaurd){
		troopHealth->setPosition(kingsGaurd->getMove()->getPosition().x, kingsGaurd->getMove()->getPosition().y, kingsGaurd->getMove()->getPosition().z);
		kingsGaurd->Update();
	}
}

void ThroneLevel::localRender(){
	if (throne){
		throne->Render();
	}
	if (kingsGaurd){
		kingsGaurd->Render();
	}
}