#include "TimeControl.h"
#include "DebugPrint.h"

TimeControl* TimeControl::instance = NULL;

TimeControl::TimeControl(){
	timer = new timer::Timer();
	Game = GameInfo::getInstance();
	Game->TIME.current = timer->getElapsedTime();
}

TimeControl::~TimeControl(){
	if (timer){
		delete timer;
	}
	instance = NULL;
}

TimeControl* TimeControl::getInstance(){
	if (!instance){
		instance = new TimeControl();
	}
	return instance;
}

void TimeControl::Update(){
	while (timer->getElapsedTime() - Game->TIME.last - (1.0f / 60.0f) < 0.001f);
	getCurrentTime();
	calcDeltaTime();
	calcFPS();

}

void TimeControl::getCurrentTime(){
	Game->TIME.last = Game->TIME.current;
	Game->TIME.current = timer->getElapsedTime();
}

void TimeControl::calcDeltaTime(){
	Game->TIME.delta = Game->TIME.current - Game->TIME.last;
}

void TimeControl::calcFPS(){
	Game->TIME.fps = 1.0f / Game->TIME.delta;
	if (Game->TIME.fps < 100000){
		Game->TIME.avgFps += Game->TIME.fps;
		Game->TIME.avgFps /= 2.0f;
	}
}
