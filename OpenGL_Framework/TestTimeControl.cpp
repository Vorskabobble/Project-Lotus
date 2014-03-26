#include "TimeControl.h"
#include "UnitTest++.h"

TEST(TimeControlTest){
	TimeControl* TC = TimeControl::getInstance();

	CHECK(TC);

	GameInfo* GI = GameInfo::getInstance();
	TC->Update();
	
	float curTime = GI->TIME.current;

	TC->Update();
	float delta = GI->TIME.delta;

	//Checking if delta and current time are calculated correctly
	CHECK_EQUAL(curTime + delta, GI->TIME.current);

	CHECK_EQUAL(1.0f / delta, GI->TIME.fps);
}