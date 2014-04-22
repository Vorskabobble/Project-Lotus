#include "MachineCreator.h"

MachineCreator::MachineCreator(){
	loader = new ModelLoader();

	loader->LoadModel("machine", "Models/cube.obj");
}

MachineCreator::~MachineCreator(){
	if (loader){
		delete loader;
	}
}

PlayerMachine* MachineCreator::createMachine(MACHINETYPE type){
	PlayerMachine* t_mach = NULL;
	switch (type)
	{
	case CATAPULT:
		t_mach = new PlayerMachine(10, 15, 5, 20, 3);
		t_mach->setModel(loader->getModel("machine"));
		break;
	case BALISTA:
		t_mach = new PlayerMachine(5, 10, 10, 30, 10);
		t_mach->setModel(loader->getModel("machine"));
		break;
	case GATE:
		t_mach = new PlayerMachine(20, 0, 10, 0, 0);
		t_mach->setModel(loader->getModel("machine"));
		break;
	default:
		break;
	}
	return t_mach;
}
