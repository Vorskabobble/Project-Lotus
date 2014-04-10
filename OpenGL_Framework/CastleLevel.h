#pragma once

#include "vector.h"
#include "ObjModel.h"
#include "GameInfo.h"

#include <map>

typedef struct{
	Vector point;
	bool occupied;
}MACHPOINT;

class CastleLevel{
protected:
	Vector* gatePos;
	ObjModel* model;
	ObjModel* gateMod;
	map<std::string, MACHPOINT*> points;

	bool occupied;

	GameInfo* Game;
public:
	CastleLevel();
	~CastleLevel();

	void LoadModel(const char* pFile);
	void LoadGate(const char* pFile);

	void addMachPoint(std::string name, Vector point);

	void SetGatePosition(Vector point);
	void setPosition(Vector position);
	void setRotation(Vector rotation);

	bool getOccupied();

	Vector getPosition();
	Vector getRotation();

	virtual void Render() = 0;
	virtual void Update() = 0;
};

