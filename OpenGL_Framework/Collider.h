#pragma once

#include <string>

#include "vector.h"
#include "Model.h"
#include "AssimpLoader.h"
#include "GameInfo.h"

enum COLLIDERTYPE{
	BOX = 0,
	SPHERE,
	CPOINT
};

class Object;

class Collider{
private:
	bool m_canRender;
	float m_width, m_height, m_depth;
	Vector *m_position, *m_lastPosition, *m_offset;
	Vector *boxMin, *boxMax;

	Object* attachedObject;
	Model* renderObj;

	COLLIDERTYPE m_type;
	GameInfo* GAME;
public:
	~Collider();
	//process collisions with another collider
	bool CheckCollision(Collider* collider);
	
	void setPosition(Vector position);
	//set its offset from the attached object
	void setOffset(Vector offset);
	//set if to render the collider
	void setCanRender(bool canRender);
	//set collider dimensions
	void setDimensions(float w, float h, float d);
	//set the object that the collider is attached to
	void setAttachedObject(Object* object);
	//set type of collider
	void setType(COLLIDERTYPE type);

	Object* getAttachedObject();

	Vector getPosition();
	Vector getOffset();
	Vector getDimensions();
	//get the highest value corner
	Vector getBoxMax();
	//get the lowest value corner
	Vector getBoxMin();
	//check if it can render
	bool getRenderable();
	void Render();
	
	//checks if ray intersects the box collider
	bool clickCollision(Vector start, Vector end);
private:
	Collider();
	bool boxSphereCollision(Collider* collider);
	bool boxBoxCollision(Collider* collider);
	bool SphereSphereCollision(Collider* collider);
	bool pointBoxCollision(Vector point);
	bool pointSphereCollision(Vector point);


	void calcMinMax();

	friend class CollisionEngine;
};

