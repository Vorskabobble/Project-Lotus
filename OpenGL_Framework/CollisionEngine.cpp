#include "CollisionEngine.h"

CollisionEngine* CollisionEngine::instance = NULL;

CollisionEngine::CollisionEngine(){ 
	tree = NULL;
}

CollisionEngine::~CollisionEngine(){
	DeleteTree();
	while (!colliders.empty()){
		delete colliders[colliders.size() - 1];
		colliders.pop_back();
	}
}

CollisionEngine* CollisionEngine::getInstance(){
	if (!instance){
		instance = new CollisionEngine();
	}
	return instance;
}

bool CollisionEngine::CreateTree(float x, float y, float z, float w, float h, float d){
	if (tree){
		return false;
	}
	tree = new CollisionTree();
	tree->buildFullTree(3, x, y, z, w, h, d);
	return true;
}

bool CollisionEngine::DeleteTree(){
	if (tree){
		delete tree;
		return true;
	}
	return false;
}

void CollisionEngine::Update(){
	tree->processCollisions();
}

void CollisionEngine::Render(){
	tree->Render();
}

Collider* CollisionEngine::newBoxCollider(Vector position, float w, float h, float d){
	Collider* temp = new Collider();
	temp->setType(BOX);
	temp->setPosition(position);
	temp->setDimensions(w, h, d);
	tree->addCollider(temp);
	colliders.push_back(temp);
	return temp;
}

Collider* CollisionEngine::newSphereCollider(Vector position, float radius){
	Collider* temp = new Collider();
	temp->setType(SPHERE);
	temp->setPosition(position);
	temp->setDimensions(radius, radius, radius);
	tree->addCollider(temp);
	colliders.push_back(temp);
	return temp;
}

Collider* CollisionEngine::newPointCollider(Vector position){
	Collider* temp = new Collider();
	temp->setType(CPOINT);
	temp->setPosition(position);
	temp->setDimensions(0, 0, 0);
	tree->addCollider(temp);
	colliders.push_back(temp);
	return temp;
}

void CollisionEngine::releaseCollider(Collider* collider){
	if (collider){
		tree->removeCollider(collider);

		std::vector<Collider*>::iterator it;
		for (it = colliders.begin(); it != colliders.end(); it++){
			if ((*it) == collider){
				delete collider;
				colliders.erase(it);
			}
		}
	}
}