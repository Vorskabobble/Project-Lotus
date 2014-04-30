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

	bool CreateTree(float x, float y, float z, float w, float h, float d);
	bool DeleteTree();
	
	void Update();
	void Render();

	Collider* newBoxCollider(Vector position, float w, float h, float d);
	Collider* newSphereCollider(Vector position, float radius);
	Collider* newPointCollider(Vector position);

	void releaseCollider(Collider* collider);

	static CollisionEngine* getInstance();
private:
	CollisionEngine();
};

