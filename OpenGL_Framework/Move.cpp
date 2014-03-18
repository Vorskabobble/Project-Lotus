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

	m_lerpRotX = m_lerpRotY = m_lerpRotZ = 0;
	m_lerpX = m_lerpY = m_lerpZ = 0;

	m_lLerpX = m_lLerpY = m_lLerpZ = 0;

	fCountw = fCountl = fCountrw = 0;

	Game = GameInfo::getInstance();
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
		position->x += speed * Game->TIME.delta;
		break;
	case Y:
		position->y += speed * Game->TIME.delta;
		break;
	case Z:
		position->z += speed * Game->TIME.delta;
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
		m_lerpX += accel * Game->TIME.delta;
		position->x += lerp(0, speed, m_lerpX);
		break;
	case Y:
		m_moveY = true;
		m_lerpY += accel * Game->TIME.delta;
		position->y += lerp(0, speed, m_lerpY);
		break;
	case Z:
		m_moveZ = true;
		m_lerpZ += accel * Game->TIME.delta;
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
		position->x += m_left->x * speed * Game->TIME.delta;
		position->y += m_left->y * speed * Game->TIME.delta;
		position->z += m_left->z * speed * Game->TIME.delta;
		break;
	case Y:
		position->x += m_up->x * speed * Game->TIME.delta;
		position->y += m_up->y * speed * Game->TIME.delta;
		position->z += m_up->z * speed * Game->TIME.delta;
		break;
	case Z:
		position->x += m_forward->x * speed * Game->TIME.delta;
		position->y += m_forward->y * speed * Game->TIME.delta;
		position->z += m_forward->z * speed * Game->TIME.delta;
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
		m_lLerpX += accel * Game->TIME.delta;
		position->x += m_left->x * lerp(0, speed, m_lLerpX) * Game->TIME.delta;
		position->y += m_left->y * lerp(0, speed, m_lLerpX) * Game->TIME.delta;
		position->z += m_left->z * lerp(0, speed, m_lLerpX) * Game->TIME.delta;
		break;
	case Y:
		m_lMoveY = true;
		m_lLerpY += accel * Game->TIME.delta;
		position->x += m_up->x * lerp(0, speed, m_lLerpY) * Game->TIME.delta;
		position->y += m_up->y * lerp(0, speed, m_lLerpY) * Game->TIME.delta;
		position->z += m_up->z * lerp(0, speed, m_lLerpY) * Game->TIME.delta;
		break;
	case Z:
		m_lMoveZ = true;
		m_lLerpZ += accel * Game->TIME.delta;
		position->x += m_forward->x * lerp(0, speed, m_lLerpZ) * Game->TIME.delta;
		position->y += m_forward->y * lerp(0, speed, m_lLerpZ) * Game->TIME.delta;
		position->z += m_forward->z * lerp(0, speed, m_lLerpZ) * Game->TIME.delta;
		break;
	default:
		break;
	}
}

void Move::rotateBy(AXIS axis, float angle){
	switch (axis)
	{
	case X:
		rotation->x += angle * Game->TIME.delta;
		break;
	case Y:
		rotation->y += angle * Game->TIME.delta;
		break;
	case Z:
		rotation->z += angle * Game->TIME.delta;
		break;
	default:
		break;
	}
	calculateLocalVectors();
}

void Move::smoothRotateBy(AXIS axis, float angle, float speed){
	fCountrw = 0;
	switch (axis)
	{
	case X:
		m_rotX = true;
		m_lerpRotX += speed * Game->TIME.delta;
		rotation->x += lerp(0, angle, m_lerpRotX);
		break;
	case Y:
		m_rotY = true;
		m_lerpRotY += speed * Game->TIME.delta;
		rotation->y += lerp(0, angle, m_lerpRotY);
		break;
	case Z:
		m_rotZ = true;
		m_lerpRotZ += speed * Game->TIME.delta;
		rotation->z += lerp(0, angle, m_lerpRotZ);
		break;
	default:
		break;
	}
	calculateLocalVectors();
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
	calculateLocalVectors();
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

void Move::calculateLocalVectors(){
	Vector t_rotation = *rotation;

	//converts angles to radians by dividing by number of degrees in a radian
	t_rotation /= 57.2957795f;

	float cosX = cos(t_rotation.x);
	float cosY = cos(t_rotation.y);
	float cosZ = cos(t_rotation.z);
	float rad90 = 1.570796327f;
	float cos90X = cos(rad90 + t_rotation.x);
	float cos90Y = cos(rad90 + t_rotation.y);
	float cos90Z = cos(rad90 + t_rotation.z);

	m_forward->x = cosY * cosZ;
	m_forward->y = cosX * cosZ;
	m_forward->z = cosX * cosY;

	m_left->x = cos90Y * cos90Z;
	m_left->y = cos90X * cos90Z;
	m_left->z = cos90X * cos90Y;

	*m_up = m_forward->CrossProduct(*m_left);
}

void Move::Update(){
	if (fCountw){
		if (!m_moveX){
			m_lerpX = 0.0f;
		}
		if (!m_moveY){
			m_lerpY = 0.0f;
		}
		if (!m_moveZ){
			m_lerpZ = 0.0f;
		}
	}
	if (fCountl){
		if (!m_lMoveX){
			m_lLerpX = 0.0f;
		}
		if (!m_lMoveY){
			m_lLerpX = 0.0f;
		}
		if (!m_lMoveZ){
			m_lLerpZ = 0.0f;
		}
	}
	if (fCountrw){
		if (!m_rotX){
			m_lerpRotX = 0.0f;
		}
		if (!m_rotY){
			m_lerpRotY = 0.0f;
		}
		if (!m_rotZ){
			m_lerpRotZ = 0.0f;
		}
	}
	m_moveX = false;
	m_moveY = false;
	m_moveZ = false;
	m_lMoveX = false;
	m_lMoveY = false;
	m_lMoveZ = false;
	m_rotX = false;
	m_rotY = false;
	m_rotZ = false;
}
