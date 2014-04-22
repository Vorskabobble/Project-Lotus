#include "MachineLevel.h"

MachineLevel::MachineLevel(std::string name): CastleLevel(name){
	m_health = 100;
	creator = new MachineCreator;
}

MachineLevel::~MachineLevel(){
	if (creator){
		delete creator;
	}
	for (auto& mach : machines){
		delete mach.second;
	}
	machines.clear();
}

void MachineLevel::localUpdate(){
	/*
		if click on machine point
			check if machine exists
				if not, create machine
		endif	

		check what troops are in the level {needs collision engine}
		check collision with the gate {needs collision engine}

	*/

	for (auto& point : points){
		if (point.second){
			if (hasMachine[point.first] == false){
//				machines[point.first] = creator->createMachine(0);
			}
		}
	}
}

void MachineLevel::localRender(){
	for (auto& mach : machines){
		mach.second->Render();
	}
}
