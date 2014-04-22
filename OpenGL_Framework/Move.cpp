#include "Move.h"

Move::Move(){
	position = Vector(0.0f, 0.0f, 0.0f);
	rotation = Vector(0.0f, 0.0f, 0.0f);
	target = Vector(0.0f, 0.0f, 0.0f);
	m_forward = Vector(0.0f, 0.0f, 1.0f);
	m_left = Vector(-1.0f, 0.0f, 0.0f);
	m_up = Vector(0.0f, 1.0f, 0.0f);

	velocity = Vector(0.0f, 0.0f, 0.0f);
	lvelocity = Vector(0.0f, 0.0f, 0.0f);

	physicsEnabled = false;
	m_gravity = 9.8f;

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

}

Vector& Move::getPosition(){
	return position;
}

Vector& Move::getRotation(){
	return rotation;
}

Vector Move::getTarget() const{
	return target;
}

Vector& Move::getVelocity(){
	return lvelocity;
}

void Move::enablePhysics(bool enabled){
	physicsEnabled = enabled;
}

void Move::setGravity(float gravity){
	m_gravity = gravity;
}

void Move::move(AXIS axis, float speed){
	switch (axis)
	{
	case X:
		velocity.x += speed * Game->TIME.delta;
		break;
	case Y:
		velocity.y += speed * Game->TIME.delta;
		break;
	case Z:
		velocity.z += speed * Game->TIME.delta;
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
		velocity.x += lerp(0, speed, m_lerpX);
		break;
	case Y:
		m_moveY = true;
		m_lerpY += accel * Game->TIME.delta;
		velocity.y += lerp(0, speed, m_lerpY);
		break;
	case Z:
		m_moveZ = true;
		m_lerpZ += accel * Game->TIME.delta;
		velocity.z += lerp(0, speed, m_lerpY);
		break;
	default:
		break;
	}
}

void Move::localMove(AXIS axis, float speed){
	switch (axis)
	{
	case X:
		velocity += m_left * speed * Game->TIME.delta;
		break;
	case Y:
		velocity += m_up * speed * Game->TIME.delta;
		break;
	case Z:
		velocity += m_forward * speed * Game->TIME.delta;
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
		velocity += m_left * lerp(0, speed, m_lLerpX) * Game->TIME.delta;
		break;
	case Y:
		m_lMoveY = true;
		m_lLerpY += accel * Game->TIME.delta;
		velocity += m_up * lerp(0, speed, m_lLerpY) * Game->TIME.delta;
		break;
	case Z:
		m_lMoveZ = true;
		m_lLerpZ += accel * Game->TIME.delta;
		velocity += m_forward * lerp(0, speed, m_lLerpZ) * Game->TIME.delta;
		break;
	default:
		break;
	}
}

void Move::rotateBy(AXIS axis, float angle){
	switch (axis)
	{
	case X:
		rotation.x += angle * Game->TIME.delta;
		break;
	case Y:
		rotation.y += angle * Game->TIME.delta;
		break;
	case Z:
		rotation.z += angle * Game->TIME.delta;
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
		rotation.x += lerp(0, angle, m_lerpRotX);
		break;
	case Y:
		m_rotY = true;
		m_lerpRotY += speed * Game->TIME.delta;
		rotation.y += lerp(0, angle, m_lerpRotY);
		break;
	case Z:
		m_rotZ = true;
		m_lerpRotZ += speed * Game->TIME.delta;
		rotation.z += lerp(0, angle, m_lerpRotZ);
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
		rotation.x = angle;
		break;
	case Y:
		rotation.y = angle;
		break;
	case Z:
		rotation.z = angle;
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
		smoothRotateBy(X, angle - rotation.x, speed);
		break;
	case Y:
		smoothRotateBy(Y, angle - rotation.y, speed);
		break;
	case Z:
		smoothRotateBy(Z, angle - rotation.z, speed);
		break;
	default:
		break;
	}
}

void Move::calculateLocalVectors(){
	Vector t_rotation = rotation;

	//converts angles to radians by multiplying degrees by radians in a degree
	t_rotation *= 0.017745329252;

	float cosY = cos(t_rotation.y);
	float sinY = sin(t_rotation.y);
	float cosX = cos(t_rotation.x);
	float sinX = sin(t_rotation.x);

	m_forward.x = sinY * cosX;
	m_forward.y = sinX;
	m_forward.z = cosY * cosX;

	m_left = m_forward ^ m_up;
}

void Move::setTargetDistance(float distance){
	targetDis = distance;
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

	if (physicsEnabled){
		velocity.y -= m_gravity * Game->TIME.delta;
	}

	position += velocity;

	m_moveX = false;
	m_moveY = false;
	m_moveZ = false;
	m_lMoveX = false;
	m_lMoveY = false;
	m_lMoveZ = false;
	m_rotX = false;
	m_rotY = false;
	m_rotZ = false;

	target = position + (m_forward * targetDis);

	lvelocity = velocity;
	velocity = 0;
}
