#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include "vector.h"
#include "utility.h"

//Z axis is forward

enum AXIS {X = 0, Y, Z};

class Move{
public:
	Vector* position;
	Vector* rotation;
private:
	//bools used for lerp functions for world movement
	bool m_moveX, m_moveY, m_moveZ;
	bool m_rotX, m_rotY, m_rotZ;

	//bools used for lerp functions for local movement
	bool m_lMoveX, m_lMoveY, m_lMoveZ;
	bool m_lRotX, m_lRotY, m_lRotZ;

	//percentage for smooth move and rotate functions for world movement
	float m_lerpX, m_lerpY, m_lerpZ;
	float m_lerpRotX, m_lerpRotY, m_lerpRotZ;

	//percentage for smooth move and rotate functions for local movement
	float m_lLerpX, m_lLerpY, m_lLerpZ;
	float m_lLerpRotX, m_lLerpRotY, m_lLerpRotZ;

	//frame counts so smooth movement doesn't keep resetting
	int fCountw, fCountl, fCountrw, fCountrl;

	//Forward vector of the object
	Vector* m_forward;
	Vector* m_left;
	Vector* m_up;

public:
	Move();
	Move(Vector& pos, Vector& angle);
	~Move();

	//Moves an object on world axis
	void move(AXIS axis, float speed);
	//Moves an object on world axis with accceleration
	void smoothMove(AXIS axis, float speed, float accel);

	//Moves an object on the local axis
	void localMove(AXIS axis, float speed);
	//Moves an objecy on the local axis with acceleration
	void localSmoothMove(AXIS axis, float speed, float accel);

	//Rotate an object by an angle on the world axis
	void rotateBy(AXIS axis, float angle);
	//Rotate an object by an angle on the world axis with acceleration
	void smoothRotateBy(AXIS axis, float angle, float speed);

	//Rotate an object to an angle on the world axis
	void rotateTo(AXIS axis, float angle);
	//Rotate an object to an angle on the world axis with acceleration
	void smoothRotateTo(AXIS axis, float angle, float speed);

	void Update();
};