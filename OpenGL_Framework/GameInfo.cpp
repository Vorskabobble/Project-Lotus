#include "GameInfo.h"

GameInfo* GameInfo::instance = NULL;

GameInfo::GameInfo(){
	INPUT = { { false }, 0, 0 };
	TIME = { 0, 0, 0, 0, 0 };
	MANAGER = { false, false, false, NULL, "", "", "" };
	SCREEN = { 0, 0, NULL };

}

GameInfo::~GameInfo(){
	MANAGER.scene = NULL;
	instance = NULL;
}

GameInfo* GameInfo::getInstance(){
	if (!instance){
		instance = new GameInfo;
	}
	return instance;
}