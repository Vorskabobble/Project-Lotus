#include "GameDirector.h"
#include "SceneMenu.h"
#include "UnitTest++.h"

TEST(GameDirectorTest){
	GameDirector* GD = GameDirector::getInstance();
	GameInfo* GI = GameInfo::getInstance();
	CHECK(GD);

	SceneMenu* ScMe = new SceneMenu;
	GD->loadScene("TestScene", *ScMe);
	CHECK_EQUAL(true, GI->MANAGER.load);
	CHECK_EQUAL("TestScene", GI->MANAGER.loadName);
	CHECK_EQUAL(ScMe, GI->MANAGER.scene);

	GD->unloadScene("TestScene");
	CHECK_EQUAL(true, GI->MANAGER.unload);
	CHECK_EQUAL("TestScene", GI->MANAGER.unloadName);

	GD->changeScene("TestScene");
	CHECK_EQUAL(true, GI->MANAGER.change);
	CHECK_EQUAL("TestScene", GI->MANAGER.changeName);

	GD->setGameInfo("TestInfo", 71.7f);
	CHECK_EQUAL(71.7f, GD->getGameInfo("TestInfo"));
}