#pragma once

#include "CollisionTree.h"
#include <vector>

class CollisionEngine{
private:
	CollisionTree* tree;
	static CollisionEngine* instance;

	std::vector<Collider*> colliders;
public:
	~CollisionEngine();

	//creates a new quadtree for processing collisions
	bool CreateTree(float x, float y, float z, float w, float h, float d);
	//deletes the current quadtree
	bool DeleteTree();
	
	void Update();
	void Render();

	//returns a new box collider that's been added to the tree
	Collider* newBoxCollider(Vector position, float w = 1.0f, float h = 1.0f, float d = 1.0f);
	Collider* newSphereCollider(Vector position, float radius = 0.5f);
	Collider* newPointCollider(Vector position);

	//removes collider from the tree and deletes its memory
	void releaseCollider(Collider* collider);

	static CollisionEngine* getInstance();
private:
	CollisionEngine();
};

