#include "Collider.h"
#include "Object.h"

Collider::Collider(){
	m_position = new Vector(0, 0, 0);
	m_lastPosition = new Vector(0,0,0);
	boxMin = new Vector(0, 0, 0);
	boxMax = new Vector(0, 0, 0);
	m_canRender = false;
	attachedObject = NULL;
	AssimpLoader loader;
	if (loader.loadScene("Models/cube.obj")){
		renderObj = new Model(*loader.getModel());
		renderObj->setWireframe(true);
	}
	GAME = GameInfo::getInstance();
}

Collider::~Collider(){
	if (m_position){
		delete m_position;
	}
	if (m_lastPosition){
		delete m_lastPosition;
	}
	if (boxMin){
		delete boxMin;
	}
	if (boxMax){
		delete boxMax;
	}
}

bool Collider::CheckCollision(Collider* collider){
	bool collided = false;

	if (m_type == BOX){
		if (collider->m_type == BOX){
			collided = boxBoxCollision(collider);
		}
		else if (collider->m_type == SPHERE){
			collided = boxSphereCollision(collider);
		}
		else if (collider->m_type == CPOINT){
			collided = pointBoxCollision(*collider->m_position);
		}
	}
	else if (m_type == SPHERE){
		if (collider->m_type == BOX){
			collided = collider->boxSphereCollision(collider);
		}
		else if (collider->m_type == SPHERE){
			collided = SphereSphereCollision(collider);
		}
		else if (collider->m_type == CPOINT){
			collided = pointSphereCollision(*collider->m_position);
		}
	}
	else if (m_type == CPOINT){
		if (collider->m_type == BOX){
			collided = collider->pointBoxCollision(*m_position);
		}
		else if (collider->m_type == SPHERE){
			collided = collider->pointSphereCollision(*m_position);
		}
	}

	return collided;
}

void Collider::setPosition(Vector position){
	*m_lastPosition = *m_position;
	*m_position = position;

	if(m_type == BOX) calcMinMax();
}

void Collider::setCanRender(bool canRender){
	m_canRender = canRender;
}

void Collider::setDimensions(float w, float h, float d){
	m_width = w;
	m_height = h;
	m_depth = d;

	calcMinMax();
}

void Collider::setAttachedObject(Object* object){
	attachedObject = object;
}

void Collider::setType(COLLIDERTYPE type){
	m_type = type;

	if (m_type == CPOINT){
		setDimensions(0, 0, 0);
	}
	else if (m_type == SPHERE){
		setDimensions(m_width, m_width, m_width);
	}
}

Object* Collider::getAttachedObject(){
	return attachedObject;
}

Vector Collider::getPosition(){
	return *m_position;
}

Vector Collider::getDimensions(){
	Vector temp;
	temp.x = m_width;
	temp.y = m_height;
	temp.z = m_depth;
	return temp;
}

Vector Collider::getBoxMax(){
	return *boxMax;
}

Vector Collider::getBoxMin(){
	return *boxMin;
}

bool Collider::getRenderable(){
	return m_canRender;
}

bool Collider::boxSphereCollision(Collider* collider){
	Vector dir = collider->m_position - m_position;
	dir.Normalize();
	dir *= collider->m_width;
	return pointBoxCollision(dir);
}

bool Collider::boxBoxCollision(Collider* collider){
	if (boxMin->x > collider->boxMax->x) return false;
	if (boxMax->x < collider->boxMin->x) return false;
	if (boxMin->y > collider->boxMax->y) return false;
	if (boxMax->y < collider->boxMin->y) return false;
	if (boxMin->z > collider->boxMax->z) return false;
	if (boxMax->z < collider->boxMin->z) return false;

	return true;
}

bool Collider::SphereSphereCollision(Collider* collider){
	float dist = Vector::Dist2(*m_position, *collider->m_position);
	float crad = (m_width + collider->m_width) * (m_width + collider->m_width);

	if (dist < crad){
		return true;
	}
	return false;
}

bool Collider::pointBoxCollision(Vector point){
	if (point.x > boxMax->x) return false;
	if (point.x < boxMin->x) return false;
	if (point.y > boxMax->y) return false;
	if (point.y < boxMin->y) return false;
	if (point.z > boxMax->z) return false;
	if (point.z < boxMin->z) return false;

	return true;
}

bool Collider::pointSphereCollision(Vector point){
	float dist = Vector::Dist2(*m_position, point);
	if (dist < m_width){
		return true;
	}
	return false;
}

bool Collider::clickCollision(Vector start, Vector end){
	// Check for point inside box, trivial reject, and determine parametric distance to each front face
	float xt, yt, zt;
	Vector rayDelta = end - start;
	bool inside = true;

	if (start.x < boxMin->x) {
		xt = boxMin->x - start.x;
		if (xt > rayDelta.x) return false;
		xt /= rayDelta.x;
		inside = false;
	}
	else if (start.x > boxMax->x) {
		xt = boxMax->x - start.x;
		if (xt < rayDelta.x) return false;
		xt /= rayDelta.x;
		inside = false;
	}
	else
		xt = -1.0f;

	if (start.y < boxMin->y) {
		yt = boxMin->y - start.y;
		if (yt > rayDelta.y) return false;
		yt /= rayDelta.y;
		inside = false;
	}
	else if (start.y > boxMax->y) {
		yt = boxMax->y - start.y;
		if (yt < rayDelta.y) return false;
		yt /= rayDelta.y;
		inside = false;
	}
	else
		yt = -1.0f;

	if (start.z < boxMin->z) {
		zt = boxMin->z - start.z;
		if (zt > rayDelta.z) return false;
		zt /= rayDelta.z;
		inside = false;
	}
	else if (start.z > boxMax->z) {
		zt = boxMax->z - start.z;
		if (zt < rayDelta.z) return false;
		zt /= rayDelta.z;
		inside = false;
	}
	else
		zt = -1.0f;

	if (inside)
		return true;

	int which = 0;  // Select farthest plane - this is the plane of intersection.
	float t = xt;
	if (yt > t) {
		which = 1;
		t = yt;
	}
	if (zt > t) {
		which = 2;
		t = zt;
	}

	switch (which) {
	case 0:{ // intersect with yz plane
			   float y = start.y + rayDelta.y*t;
			   if (y < boxMin->y || y > boxMax->y) return false;
			   float z = start.z + rayDelta.z*t;
			   if (z < boxMin->z || z > boxMax->z) return false;
	} break;

	case 1:{ // intersect with xz plane
			   float x = start.x + rayDelta.x*t;
			   if (x < boxMin->x || x > boxMax->x) return false;
			   float z = start.z + rayDelta.z*t;
			   if (z < boxMin->z || z > boxMax->z) return false;
	} break;

	case 2:{ // intersect with xy plane
			   float x = start.x + rayDelta.x*t;
			   if (x < boxMin->x || x > boxMax->x) return false;
			   float y = start.y + rayDelta.y*t;
			   if (y < boxMin->y || y > boxMax->y) return false;
	} break;
	}  // t is parametric point of intersection
	return true;
}

void Collider::calcMinMax(){
	boxMin->x = m_position->x - (m_width / 2);
	boxMin->y = m_position->y - (m_height / 2);
	boxMin->z = m_position->z - (m_depth / 2);

	boxMax->x = m_position->x + (m_width / 2);
	boxMax->y = m_position->y + (m_height / 2);
	boxMax->z = m_position->z + (m_depth / 2);
}

void Collider::Render(){
	if (m_canRender){
		glPushMatrix();
		glColor3f(0, 1, 0);
		glTranslatef(m_position->x, m_position->y, m_position->z);
		glScalef(m_width, m_depth, m_height);
		renderObj->Render();
		glPopMatrix();
	}
}