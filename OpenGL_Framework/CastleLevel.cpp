#include "CastleLevel.h"

CastleLevel::CastleLevel(std::string uniqueName){
	gateMod = NULL;
	model = NULL;
	occupied = false;
	Game = GameInfo::getInstance();
	guiHandle = GUI::getInstance();

	name = uniqueName;
	
	guiHandle->newWindow(name, 0, 0, 100, 100);
	gateHealth = guiHandle->newElement(STATUS, "gateHealth", 0, 0, 100, 10, name);
	gateHealth->set3D(true);
	gateHealth->setRender(false);
}

CastleLevel::~CastleLevel(){
	gateHealth = NULL;
	guiHandle->ReleaseWindow(name);

	for (auto& point : points){
		delete point.second;
		point.second = NULL;
	}
	points.clear();

	if (model){
		delete model;
	}
	if (gateMod){
		delete gateMod;
	}
}

void CastleLevel::setModel(Object* level){
	if (model){
		delete model;
	}
	model = new Object(*level);
}

void CastleLevel::setGate(Object* gate){
	if (gateMod){
		delete gateMod;
	}
	gateMod = new Object(*gate);
	gateHealth->setPosition(gateMod->getMove()->getPosition().x, gateMod->getMove()->getPosition().y, gateMod->getMove()->getPosition().z);
	gateHealth->setRender(true);
}

void CastleLevel::addMachPoint(std::string name, Collider* collider){
	if (!points[name]){
		points[name] = collider;
		hasMachine[name] = false;
		GUIElement* temp;
		temp = guiHandle->newElement(STATUS, name, 0, 0, 100, 10, name);
		temp->set3D(true);
		temp->setPosition(collider->getPosition().x, collider->getPosition().y, collider->getPosition().z);
		temp->setRender(false);

	}
}

void CastleLevel::setPosition(Vector position){
	if (model){
		model->getMove()->getPosition().set(position.x, position.y, position.z);
	}
	if (gateMod){
		gateMod->getMove()->getPosition().set(position.x, position.y, position.z);
	}
}

void CastleLevel::setRotation(Vector rotation){
	if (model){
		model->getMove()->getRotation().set(rotation.x, rotation.y, rotation.z);
	}
}

bool CastleLevel::getOccupied(){
	return occupied;
}

std::string CastleLevel::getName(){
	return name;
}

Vector CastleLevel::getPosition(){
	return model->getMove()->getPosition();
}

Vector CastleLevel::getRotation(){
	return model->getMove()->getRotation();
}

void CastleLevel::Update(){
	for (auto& collider : points){
		if (hasMachine[collider.first]){
			guiHandle->getWindow(name)->getElement(collider.first)->setRender(true);
			guiHandle->getWindow(name)->getElement(collider.first)->getState()->state = collider.second->getAttachedObject()->getStats()->getHealth() / collider.second->getAttachedObject()->getStats()->getMaxHealth();
		}
		else{
			guiHandle->getWindow(name)->getElement(collider.first)->setRender(false);
		}
	}
	if (gateMod){
		gateHealth->getState()->state = gateMod->getStats()->getHealth() / gateMod->getStats()->getMaxHealth();
	}
	if (gateMod->getStats()->getHealth() <= 0){
		gateHealth->setRender(false);
	}

	localUpdate();
}

void CastleLevel::Render(){
	if (model){
		model->Render();
	}
	if (gateMod){
		gateMod->Render();
	}
	localRender();
}