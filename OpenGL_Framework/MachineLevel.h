#pragma once

#include "CastleLevel.h"
#include "MachineCreator.h"

class MachineLevel : public CastleLevel{
private:
	int m_health;

	MachineCreator* creator;
	map<std::string, PlayerMachine*> machines;
public:
	MachineLevel(std::string name);
	~MachineLevel();

	void localUpdate();
	void localRender();
};