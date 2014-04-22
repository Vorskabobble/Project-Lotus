#pragma once

#include <stdlib.h>

#include "PlayerMachine.h"
#include "ModelLoader.h"

enum MACHINETYPE{
	CATAPULT = 0,
	BALISTA,
	GATE
};

class MachineCreator{
private:
	ModelLoader* loader;
public:
	MachineCreator();
	~MachineCreator();

	PlayerMachine* createMachine(MACHINETYPE type);
};

