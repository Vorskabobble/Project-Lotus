#include "CollisionTree.h"

CollisionTree::CollisionTree(){
	root = NULL;
}

CollisionTree::~CollisionTree(){
	delete root;
}

void CollisionTree::buildFullTree(int nbrLevels, float x, float y, float z, float w, float h, float d){
	root = new CollisionPart(NULL, 0, x, y, z, w, h, d);
	root->createSubPartitions(nbrLevels);
}

void CollisionTree::processCollisions(){
	root->processCollisions();
}

void CollisionTree::addCollider(Collider* collider){
	root->addCollider(collider);
}

void CollisionTree::removeCollider(Collider* collider){
	root->removeCollider(collider);
}

void CollisionTree::Render(){
	root->Render();
}
