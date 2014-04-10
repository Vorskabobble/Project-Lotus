#include "ThroneLevel.h"


ThroneLevel::ThroneLevel(){
	throne = NULL;
	creator = NULL;
}


ThroneLevel::~ThroneLevel(){
}

void ThroneLevel::Update(){
	/*
		Check if enemy enters the throne area

		if entered in throne room
			create kings guard troopss
		
	*/
}

void ThroneLevel::Render(){
	if (throne){
		throne->Render();
	}
}