#include "GameInfo.h"

GameInfo* GameInfo::instance = NULL;

GameInfo::GameInfo(){
	INPUT = { { false }, 0, 0 };
	TIME = { 0, 0, 0, 0, 0 };
	MANAGER = { false, false, false, NULL, "", "", "" };
}

GameInfo::~GameInfo(){

}

GameInfo* GameInfo::getInstance(){
	if (!instance){
		instance = new GameInfo;
	}
	return instance;
}