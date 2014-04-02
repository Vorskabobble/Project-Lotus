#pragma once

#include "CastleLevel.h"
#include "MachineCreator.h"

class MachineLevel : public CastleLevel{
private:
	int m_health;
	int m_gateHealth;

	MachineCreator* creator;
	map<std::string, PlayerMachine*> machines;
public:
	MachineLevel();
	~MachineLevel();

	void Update();
	void Render();
};

