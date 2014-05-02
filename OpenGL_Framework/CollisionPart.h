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

	//create children of this collision part
	void createSubPartitions(int nbrLevels);
	//add a collider to this collision part
	void addCollider(Collider* collider);
	//check of collider is contained within the part
	bool contains(Collider* collider);
	//remove collider from this part and all children
	bool removeCollider(Collider* collider);
	//check collisions of colliders in the part
	void processCollisions();
	//check collisions of colliders in the part against colliders in border parts
	void processBorderCollisions(CollisionPart* part);

	//returns root of tree
	CollisionPart* getRoot();

	void Render();

	bool hasChildren(){ return m_child[0] != NULL; }

private:
	CollisionPart();
};

