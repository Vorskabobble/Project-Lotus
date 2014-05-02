#pragma once

#include "vector.h"
#include "Object.h"
#include "GameInfo.h"
#include "GUI.h"

#include <map>

typedef struct{
	Vector point;
	bool occupied;
}MACHPOINT;

class CastleLevel{
protected:
	Object* model;
	Object* gateMod;
	map<std::string, Collider*> points;
	map<std::string, bool> hasMachine;

	bool occupied;
	std::string name;

	float gold;

	GameInfo* Game;
	GUI* guiHandle;

	GUIElement* gateHealth;
public:
	CastleLevel(std::string uniqueName);
	virtual ~CastleLevel();

	//set the model of the castle level
	void setModel(Object* level);
	//set the model object of the castle gate
	void setGate(Object* gate);

	//add a point for machine placing
	void addMachPoint(std::string name, Collider* collider);

	//sets position of model and gate
	void setPosition(Vector position);
	//sets rotation of model and gate
	void setRotation(Vector rotation);

	//returns occupied - evaluation specified in derived classes
	bool getOccupied();
	std::string getName();

	Vector getPosition();
	Vector getRotation();

	void setGold(float gold);
	float getGold();

	void Update();
	void Render();

	virtual void localUpdate() = 0;
	virtual void localRender() = 0;
};

