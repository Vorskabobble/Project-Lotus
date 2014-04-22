#include "Move.h"
#include "UnitTest++.h"

TEST(MoveTest){
	Move M;
	GameInfo* GI = GameInfo::getInstance();
	GI->TIME.delta = 1.0f;
	M.getRotation().set( 0.0f, 0.0f, 0.0f );
	M.getRotation().set(0.0f, 0.0f, 0.0f);

	M.move(X, 71.7f);
	M.Update();
	CHECK_EQUAL(71.7f, M.getPosition().x);
	M.move(Y, 7.1f);
	M.Update();
	CHECK_EQUAL(7.1f, M.getPosition().y);
	M.move(Z, 17.1f);
	M.Update();
	CHECK_EQUAL(17.1f, M.getPosition().z);

	M.getPosition().set(0, 0, 0);
	M.smoothMove(X, 7, 1);
	M.Update();
	CHECK_EQUAL(7, M.getPosition().x);
	M.smoothMove(Y, 71.7f, 1);
	M.Update();
	CHECK_EQUAL(71.7f, M.getPosition().y);
	M.smoothMove(Z, 17.1f, 1);
	M.Update();
	CHECK_EQUAL(17.1f, M.getPosition().z);

	M.getPosition().set(0, 0, 0);
	M.localMove(X, 71.7f);
	M.Update();
	CHECK_EQUAL(71.7f, M.getPosition().x);
	M.localMove(Y, 7.1f);
	M.Update();
	CHECK_EQUAL(7.1f, M.getPosition().y);
	M.localMove(Z, 17.1f);
	M.Update();
	CHECK_EQUAL(17.1f, M.getPosition().z);

	M.getPosition().set(0, 0, 0);
	M.localSmoothMove(X, 7, 1);
	M.Update();
	CHECK_EQUAL(7, M.getPosition().x);
	M.localSmoothMove(Y, 71.7f, 1);
	M.Update();
	CHECK_EQUAL(71.7f, M.getPosition().y);
	M.localSmoothMove(Z, 17.1f, 1);
	M.Update();
	CHECK_EQUAL(17.1f, M.getPosition().z);

	M.rotateBy(X, 17.1f);
	M.Update();
	CHECK_EQUAL(17.1f, M.getRotation().x);
	M.rotateBy(Y, 71.7f);
	M.Update();
	CHECK_EQUAL(71.7f, M.getRotation().y);
	M.rotateBy(Z, 7.1f);
	M.Update();
	CHECK_EQUAL(7.1f, M.getRotation().z);

	M.getRotation().set(0, 0, 0);
	M.smoothRotateBy(X, 7.1f, 1);
	M.Update();
	CHECK_EQUAL(7.1f, M.getRotation().x);
	M.smoothRotateBy(Y, 17.1f, 1);
	M.Update();
	CHECK_EQUAL(17.1f, M.getRotation().y);
	M.smoothRotateBy(Z, 7.17f, 1);
	M.Update();
	CHECK_EQUAL(7.17f, M.getRotation().z);

	M.rotateTo(X, 0.0f);
	M.Update();
	CHECK_EQUAL(0.0f, M.getRotation().x);
	M.rotateTo(Y, 0.0f);
	M.Update();
	CHECK_EQUAL(0.0f, M.getRotation().y);
	M.rotateTo(Z, 0.0f);
	M.Update();
	CHECK_EQUAL(0.0f, M.getRotation().z);

	M.getRotation().set(0, 0, 0);
	M.smoothRotateTo(X, 10.0f, 1);
	M.Update();
	CHECK_EQUAL(10.0f, M.getRotation().x);
	M.smoothRotateTo(Y, 10.0f, 1);
	M.Update();
	CHECK_EQUAL(10.0f, M.getRotation().y);
	M.smoothRotateTo(Z, 10.0f, 1);
	M.Update();
	CHECK_EQUAL(10.0f, M.getRotation().z);
}