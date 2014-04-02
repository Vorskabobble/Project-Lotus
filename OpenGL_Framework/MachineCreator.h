#pragma once

#include "PlayerMachine.h"

enum MACHINETYPE{
	CATAPULT = 0,
	BALISTA,
	GATE
};

class MachineCreator{
public:
	MachineCreator();
	~MachineCreator();

	PlayerMachine* createMachine(MACHINETYPE type);
};

