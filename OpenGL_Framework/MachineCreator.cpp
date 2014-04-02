#include "MachineCreator.h"

MachineCreator::MachineCreator(){
}

MachineCreator::~MachineCreator(){
}

PlayerMachine* MachineCreator::createMachine(MACHINETYPE type){
	PlayerMachine* t_mach = NULL;
	switch (type)
	{
	case CATAPULT:
		t_mach = new PlayerMachine(10, 15, 5, 20, 3);
		break;
	case BALISTA:
		t_mach = new PlayerMachine(5, 10, 10, 30, 10);
		break;
	case GATE:
		t_mach = new PlayerMachine(20, 0, 10, 0, 0);
		break;
	default:
		break;
	}
	return t_mach;
}
