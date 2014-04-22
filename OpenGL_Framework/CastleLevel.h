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

	GameInfo* Game;
	GUI* guiHandle;

	GUIElement* gateHealth;
public:
	CastleLevel(std::string uniqueName);
	~CastleLevel();


	void setModel(Object* level);
	void setGate(Object* gate);

	void addMachPoint(std::string name, Collider* collider);

	void setPosition(Vector position);
	void setRotation(Vector rotation);

	bool getOccupied();
	std::string getName();

	Vector getPosition();
	Vector getRotation();

	void Update();
	void Render();

	virtual void localUpdate() = 0;
	virtual void localRender() = 0;
};

