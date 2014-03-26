#include "Move.h"
#include "UnitTest++.h"

TEST(MoveTest){
	Move M;
	GameInfo* GI = GameInfo::getInstance();
	GI->TIME.delta = 1.0f;
	M.position = &Vector( 0.0f, 0.0f, 0.0f );
	M.rotation = &Vector(0.0f, 0.0f, 0.0f);
	M.target = &Vector(0.0f, 0.0f, 0.0f);

	M.move(X, 71.7f);
	CHECK_EQUAL(71.7f, M.position->x);
	M.move(Y, 7.1f);
	CHECK_EQUAL(7.1f, M.position->y);
	M.move(Z, 17.1f);
	CHECK_EQUAL(17.1f, M.position->z);

	M.position->set(0, 0, 0);
	M.smoothMove(X, 7, 1);
	CHECK_EQUAL(7, M.position->x);
	M.smoothMove(Y, 71.7f, 1);
	CHECK_EQUAL(71.7f, M.position->y);
	M.smoothMove(Z, 17.1f, 1);
	CHECK_EQUAL(17.1f, M.position->z);

	M.position->set(0, 0, 0);
	M.localMove(X, 71.7f);
	CHECK_EQUAL(71.7f, M.position->x);
	M.localMove(Y, 7.1f);
	CHECK_EQUAL(7.1f, M.position->y);
	M.localMove(Z, 17.1f);
	CHECK_EQUAL(17.1f, M.position->z);

	M.position->set(0, 0, 0);
	M.localSmoothMove(X, 7, 1);
	CHECK_EQUAL(7, M.position->x);
	M.localSmoothMove(Y, 71.7f, 1);
	CHECK_EQUAL(71.7f, M.position->y);
	M.localSmoothMove(Z, 17.1f, 1);
	CHECK_EQUAL(17.1f, M.position->z);

	M.rotateBy(X, 17.1f);
	CHECK_EQUAL(17.1f, M.rotation->x);
	M.rotateBy(Y, 71.7f);
	CHECK_EQUAL(71.7f, M.rotation->y);
	M.rotateBy(Z, 7.1f);
	CHECK_EQUAL(7.1f, M.rotation->z);

	M.rotation->set(0, 0, 0);
	M.smoothRotateBy(X, 7.1f, 1);
	CHECK_EQUAL(7.1f, M.rotation->x);
	M.smoothRotateBy(Y, 17.1f, 1);
	CHECK_EQUAL(17.1f, M.rotation->y);
	M.smoothRotateBy(Z, 7.17f, 1);
	CHECK_EQUAL(7.17f, M.rotation->z);

	M.rotateTo(X, 0.0f);
	CHECK_EQUAL(0.0f, M.rotation->x);
	M.rotateTo(Y, 0.0f);
	CHECK_EQUAL(0.0f, M.rotation->y);
	M.rotateTo(Z, 0.0f);
	CHECK_EQUAL(0.0f, M.rotation->z);

	M.rotation->set(0, 0, 0);
	M.smoothRotateTo(X, 10.0f, 1);
	CHECK_EQUAL(10.0f, M.rotation->x);
	M.smoothRotateTo(Y, 10.0f, 1);
	CHECK_EQUAL(10.0f, M.rotation->y);
	M.smoothRotateTo(Z, 10.0f, 1);
	CHECK_EQUAL(10.0f, M.rotation->z);
}