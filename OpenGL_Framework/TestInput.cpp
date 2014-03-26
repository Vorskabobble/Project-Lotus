#include "Input.h"
#include "UnitTest++.h"

TEST(InputTest){
	Input I;
	GameInfo* GI = GameInfo::getInstance();

	for (int i = 0; i < 256; i++){
		I.processKeyDown(i);
		CHECK_EQUAL(true, GI->INPUT.keyPressed[i]);
	}
	for (int i = 0; i < 256; i++){
		I.processKeyUp(i);
		CHECK_EQUAL(false, GI->INPUT.keyPressed[i]);
	}
	I.processMouseAxis(71, 17);
	CHECK_EQUAL(71, GI->INPUT.mouseX);
	CHECK_EQUAL(17, GI->INPUT.mouseY);
}
