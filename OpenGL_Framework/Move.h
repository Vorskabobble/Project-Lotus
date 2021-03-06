#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include "vector.h"
#include "GameInfo.h"
#include "MathFunctions.h"

//Z axis is forward

enum AXIS {X = 0, Y, Z};

class Move{
private:
	float targetDis;

	bool physicsEnabled, stopMove;
	float m_gravity;

	//bools used for lerp functions for world movement
	bool m_moveX, m_moveY, m_moveZ;
	bool m_rotX, m_rotY, m_rotZ;

	//bools used for lerp functions for local movement
	bool m_lMoveX, m_lMoveY, m_lMoveZ;

	//percentage for smooth move and rotate functions for world movement
	float m_lerpX, m_lerpY, m_lerpZ;
	float m_lerpRotX, m_lerpRotY, m_lerpRotZ;

	//percentage for smooth move functions for local movement
	float m_lLerpX, m_lLerpY, m_lLerpZ;

	//frame counts so smooth movement doesn't keep resetting
	int fCountw, fCountl, fCountrw;

	//Translation vectors
	Vector position;
	Vector rotation;
	Vector target;

	Vector velocity;
	Vector lvelocity;

	//Forward vector of the object
	Vector m_forward;
	Vector m_left;
	Vector m_up;

	GameInfo* Game;
public:
	Move();
	~Move();

	void stop();

	//Retrive position, can be used for setting
	Vector& getPosition();
	//Retrive rotation, can be used for setting
	Vector& getRotation();
	//Retrive target based on forward vector
	Vector getTarget() const;

	Vector& getVelocity();

	void enablePhysics(bool enabled);
	void setGravity(float gravity);

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

	void calculateLocalVectors();

	void setTargetDistance(float distance);

	void Update();
};