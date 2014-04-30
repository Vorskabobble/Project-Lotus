#pragma once

#include "CollisionPart.h"

class CollisionTree{
private:
	CollisionPart* root;
public:
	CollisionTree();
	~CollisionTree();

	void buildFullTree(int nbrLevels, float x, float y, float z, float w, float h, float d);
	void processCollisions();

	void addCollider(Collider* collider);
	void removeCollider(Collider* collider);

	void Render();
};

