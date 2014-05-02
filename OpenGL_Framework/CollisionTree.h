#pragma once

#include "CollisionPart.h"

class CollisionTree{
private:
	CollisionPart* root;
public:
	CollisionTree();
	~CollisionTree();

	//initialises the tree
	void buildFullTree(int nbrLevels, float x, float y, float z, float w, float h, float d);
	//checks all collisions in the tree
	void processCollisions();

	//adds a collider ot the tree
	void addCollider(Collider* collider);
	//removes a collider from the tree
	void removeCollider(Collider* collider);

	void Render();
};

