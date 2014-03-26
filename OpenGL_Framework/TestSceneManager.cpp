#include "SceneManager.h"
#include "SceneMenu.h"
#include "UnitTest++.h"

TEST(SceneManagerTest){
	SceneManager* SM = SceneManager::getInstance();
	CHECK(SM);

	SceneMenu* ScMe = new SceneMenu;
	CHECK_EQUAL(true, SM->addScene("TestScene", ScMe));
	CHECK_EQUAL(false, SM->addScene("TestScene", ScMe));
	CHECK_EQUAL(true, SM->removeScene("TestScene"));
	delete ScMe;
}