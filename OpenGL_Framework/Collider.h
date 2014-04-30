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
	Vector *m_position, *m_lastPosition;
	Vector *boxMin, *boxMax;

	Object* attachedObject;
	Model* renderObj;

	COLLIDERTYPE m_type;
	GameInfo* GAME;
public:
	~Collider();
	bool CheckCollision(Collider* collider);
	
	void setPosition(Vector position);
	void setCanRender(bool canRender);
	void setDimensions(float w, float h, float d);
	void setAttachedObject(Object* object);
	void setType(COLLIDERTYPE type);

	Object* getAttachedObject();

	Vector getPosition();
	Vector getDimensions();
	Vector getBoxMax();
	Vector getBoxMin();
	bool getRenderable();
	void Render();
	
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

