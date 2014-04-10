#include "MachineLevel.h"

MachineLevel::MachineLevel(){
	m_health = 100;
	m_gateHealth = 100;
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

void MachineLevel::Update(){
	/*
		if click on machine point
			check if machine exists
				if not, create machine
		endif	

		check what troops are in the level {needs collision engine}
		check collision with the gate {needs collision engine}

	*/
}

void MachineLevel::Render(){
	if (model){
		model->Render();
	}
	if (gateMod){
		gateMod->Render();
	}
	for (auto& mach : machines){
		mach.second->Render();
	}
}
