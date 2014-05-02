#include "ThroneLevel.h"

ThroneLevel::ThroneLevel(std::string name): CastleLevel(name){
	troopHealth = guiHandle->newElement(STATUS, "throneHealth", 0, 0, 100, 10, name);
	troopHealth->setRender(false);
	troopHealth->set3D(true);
	kingsGaurd = NULL;
	throne = NULL;
}

ThroneLevel::~ThroneLevel(){
	if (throne){
		delete throne;
	}
	if (kingsGaurd){
		delete kingsGaurd;
	}
}

void ThroneLevel::setThrone(Object* obj){
	if (throne){
		delete throne;
	}
	throne = obj;
}

void ThroneLevel::localUpdate(){
	if (throne){
		throne->Update();
		if (throne->getStats()->getHealth() <= 0.0f){
			occupied = true;
		}
	}
	if (!gateMod && !kingsGaurd){
		kingsGaurd = creator.CreateTroop(KING);
		kingsGaurd->getMove()->getPosition().set(throne->getMove()->getPosition().x - 3, throne->getMove()->getPosition().y, throne->getMove()->getPosition().z);
		troopHealth->setRender(true);
	}

	if (kingsGaurd){
		troopHealth->setPosition(kingsGaurd->getMove()->getPosition().x , kingsGaurd->getMove()->getPosition().y, kingsGaurd->getMove()->getPosition().z);
		troopHealth->getState()->state = kingsGaurd->getStats()->getHealth() / kingsGaurd->getStats()->getMaxHealth();
	//	kingsGaurd->getMove()->move(X, -kingsGaurd->getStats()->getSpeed());
		kingsGaurd->Update();
		if (kingsGaurd->getStats()->getHealth() <= 0){
			delete kingsGaurd;
			kingsGaurd = NULL;
			troopHealth->setRender(false);
		}
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