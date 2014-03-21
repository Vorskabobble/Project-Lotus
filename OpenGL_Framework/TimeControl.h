#pragma once
#pragma once
#include "GameInfo.h"
#include "timer.h"

class TimeControl{
private:
	static TimeControl* instance; 
	timer::Timer* timer;
	GameInfo* Game;
public:
	~TimeControl();

	static TimeControl* getInstance();

	void Update();
private:
	TimeControl();

	void getCurrentTime();
	void calcDeltaTime();
	void calcFPS();
};

