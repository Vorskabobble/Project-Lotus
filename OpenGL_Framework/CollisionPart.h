#pragma once

#include <vector>
#include "vector.h"
#include "Collider.h"

class CollisionPart{
private:
	CollisionPart* m_parent;
	CollisionPart* m_child[4];

	std::vector<Collider*> colliders;

	Model* renderBox;

	Vector boxMin, boxMax, Centre;

	int m_level;
public:
	CollisionPart(CollisionPart* parent, int level, float x, float y, float z, float w, float h, float d);
	~CollisionPart();

	void createSubPartitions(int nbrLevels);
	void addCollider(Collider* collider);
	bool contains(Collider* collider);
	bool removeCollider(Collider* collider);
	void processCollisions();
	void processBorderCollisions(CollisionPart* part);

	CollisionPart* getRoot();

	void Render();

	bool hasChildren(){ return m_child[0] != NULL; }

private:
	CollisionPart();
};

