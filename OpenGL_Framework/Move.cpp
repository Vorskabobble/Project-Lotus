#include "Move.h"


Move::Move(){
	position = new Vector(0.0f, 0.0f, 0.0f);
	rotation = new Vector(0.0f, 0.0f, 0.0f);
	m_forward = new Vector(0.0f, 0.0f, 1.0f);
	m_left = new Vector(1.0f, 0.0f, 0.0f);
	m_up = new Vector(0.0f, 1.0f, 0.0f);

	m_moveX = m_moveY = m_moveZ = false;
	m_rotX = m_rotY = m_rotZ = false;

	m_lMoveX = m_lMoveY = m_lMoveZ = false;
	m_lRotX = m_lRotY = m_lRotZ = false;

	m_lerpRotX = m_lerpRotY = m_lerpRotZ = 0;
	m_lerpX = m_lerpY = m_lerpZ = 0;

	m_lLerpX = m_lLerpY = m_lLerpZ = 0;
	m_lLerpRotX = m_lLerpRotY = m_lLerpRotZ = 0;

	fCountw = fCountl = fCountrw = fCountrl = 0;
}

Move::~Move(){
	if (position){
		delete position;
	}
	if (rotation){
		delete rotation;
	}
	if (m_forward){
		delete m_forward;
	}
	if (m_left){
		delete m_left;
	}
	if (m_up){
		delete m_up;
	}
}

void Move::move(AXIS axis, float speed){
	switch (axis)
	{
	case X:
		position->x += speed;
		break;
	case Y:
		position->y += speed;
		break;
	case Z:
		position->z += speed;
		break;
	default:
		break;
	}
}

void Move::smoothMove(AXIS axis, float speed, float accel){
	fCountw = 0;
	switch (axis)
	{
	case X:
		m_moveX = true;
		m_lerpX += accel * GAME_TIME.delta;
		position->x += lerp(0, speed, m_lerpX);
		break;
	case Y:
		m_moveY = true;
		m_lerpY += accel * GAME_TIME.delta;
		position->y += lerp(0, speed, m_lerpY);
		break;
	case Z:
		m_moveZ = true;
		m_lerpZ += accel * GAME_TIME.delta;
		position->z += lerp(0, speed, m_lerpY);
		break;
	default:
		break;
	}
}

void Move::localMove(AXIS axis, float speed){
	switch (axis)
	{
	case X:
		position->x += m_left->x * speed * GAME_TIME.delta;
		position->y += m_left->y * speed * GAME_TIME.delta;
		position->z += m_left->z * speed * GAME_TIME.delta;
		break;
	case Y:
		position->x += m_up->x * speed * GAME_TIME.delta;
		position->y += m_up->y * speed * GAME_TIME.delta;
		position->z += m_up->z * speed * GAME_TIME.delta;
		break;
	case Z:
		position->x += m_forward->x * speed * GAME_TIME.delta;
		position->y += m_forward->y * speed * GAME_TIME.delta;
		position->z += m_forward->z * speed * GAME_TIME.delta;
		break;
	default:
		break;
	}
}

void Move::localSmoothMove(AXIS axis, float speed, float accel){
	fCountl = 0;
	switch (axis)
	{
	case X:
		m_lMoveX = true;
		m_lLerpX = accel * GAME_TIME.delta;
		position->x += m_left->x * speed * GAME_TIME.delta;
		position->y += m_left->y * speed * GAME_TIME.delta;
		position->z += m_left->z * speed * GAME_TIME.delta;
		break;
	case Y:
		m_lMoveY = true;
		m_lLerpY = accel * GAME_TIME.delta;
		position->x += m_up->x * speed * GAME_TIME.delta;
		position->y += m_up->y * speed * GAME_TIME.delta;
		position->z += m_up->z * speed * GAME_TIME.delta;
		break;
	case Z:
		m_lMoveZ = true;
		m_lLerpZ = accel * GAME_TIME.delta;
		position->x += m_forward->x * speed * GAME_TIME.delta;
		position->y += m_forward->y * speed * GAME_TIME.delta;
		position->z += m_forward->z * speed * GAME_TIME.delta;
		break;
	default:
		break;
	}
}

void Move::rotateBy(AXIS axis, float angle){
	switch (axis)
	{
	case X:
		rotation->x += angle;
		break;
	case Y:
		rotation->y += angle;
		break;
	case Z:
		rotation->z += angle;
		break;
	default:
		break;
	}
}

void Move::smoothRotateBy(AXIS axis, float angle, float speed){
	fCountrl = 0;
	switch (axis)
	{
	case X:
		m_rotX = true;
		m_lerpRotX += speed;
		rotation->x += lerp(0, angle, m_lerpRotX);
		break;
	case Y:
		m_rotY = true;
		m_lerpRotY += speed;
		rotation->y += lerp(0, angle, m_lerpRotY);
		break;
	case Z:
		m_rotZ = true;
		m_lerpRotZ += speed;
		rotation->z += lerp(0, angle, m_lerpRotZ);
		break;
	default:
		break;
	}
}

void Move::rotateTo(AXIS axis, float angle){
	switch (axis)
	{
	case X:
		rotation->x = angle;
		break;
	case Y:
		rotation->y = angle;
		break;
	case Z:
		rotation->z = angle;
		break;
	default:
		break;
	}
}

void Move::smoothRotateTo(AXIS axis, float angle, float speed){
	switch (axis)
	{
	case X:
		smoothRotateBy(X, angle - rotation->x, speed);
		break;
	case Y:
		smoothRotateBy(Y, angle - rotation->y, speed);
		break;
	case Z:
		smoothRotateBy(Z, angle - rotation->z, speed);
		break;
	default:
		break;
	}
}

void Move::Update(){
	//stops 
	if(fCount > 100){
		if (!m_moveX){
			m_lerpX = 0.0f;
		}
		if (!m_moveY){
			m_lerpY = 0.0f;
		}
		if (!m_moveZ){
			m_lerpZ = 0.0f;
		}

		if (!m_lMoveX){
			m_lerpX = 0.0f;
		}
		if (!m_lMoveY){
			m_lLerpX = 0.0f;
		}
		if (!m_lMoveZ){
			m_lLerpZ = 0.0f;
		}

		if (!m_rotX){
			m_lerpRotX = 0.0f;
		}
		if (!m_rotY){
			m_lerpRotY = 0.0f;
		}
		if (!m_rotZ){
			m_lerpZ = 0.0f;
		}



		m_moveX = false;
		m_moveY = false;
		m_moveZ = false;
		m_rotX = false;
		m_rotY = false;
		m_rotZ = false;
		fCount = 0;
	}
	fCount++;
}
