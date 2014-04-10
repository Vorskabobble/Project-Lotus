#include "CastleLevel.h"

CastleLevel::CastleLevel(){
	gatePos = NULL;
	gateMod = NULL;
	model = NULL;
	occupied = false;
	Game = GameInfo::getInstance();
}

CastleLevel::~CastleLevel(){
	if (gatePos){
		delete gatePos;
	}
	if (gateMod){
		delete gateMod;
	}
	if (model){
		delete model;
	}
	for (auto& point : points){
		delete point.second;
	}
	points.clear();
}

void CastleLevel::LoadModel(const char* pFile){
	if (model){
		delete model;
		model = NULL;
	}
	model = new ObjModel();
	model->LoadModel(pFile);
}

void CastleLevel::LoadGate(const char* pFile){
	if (gateMod){
		delete gateMod;
		gateMod = NULL;
	}
	gateMod = new ObjModel();
	gateMod->LoadModel(pFile);
}

void CastleLevel::addMachPoint(std::string name, Vector point){
	if (!points[name]){
		MACHPOINT* t_point = new MACHPOINT{ point, false };
		points[name] = t_point;
	}
}

void CastleLevel::SetGatePosition(Vector point){
	if (!gatePos){
		gatePos = new Vector;
	}
	*gatePos = point;
}

void CastleLevel::setPosition(Vector position){
	if (model){
		*model->move()->position = position;
	}
}

void CastleLevel::setRotation(Vector rotation){
	if (model){
		*model->move()->position = rotation;
	}
}

bool CastleLevel::getOccupied(){
	return occupied;
}

Vector CastleLevel::getPosition(){
	return *model->getPos();
}

Vector CastleLevel::getRotation(){
	return *model->move()->rotation;
}