#include "CollisionPart.h"
#include "Object.h"

CollisionPart::CollisionPart(){
}

CollisionPart::CollisionPart(CollisionPart* parent, int level, float x, float y, float z, float w, float h, float d){
	m_parent = parent;
	m_level = level;

	Centre.x = x;
	Centre.y = y;
	Centre.z = z;

	boxMin.x = x - (w / 2);
	boxMin.y = y - (h / 2);
	boxMin.z = z - (d / 2);
	boxMax.x = x + (w / 2);
	boxMax.y = y + (h / 2);
	boxMax.z = z + (d / 2);

//	renderBox = new ObjCube(w, h, d);
//	renderBox->move()->position->set(x, y, z);
//	renderBox->setColor(Color{ 1.0f, 0.2f * level, 0.0f, 0.1f });

	m_child[0] = NULL;
	m_child[1] = NULL;
	m_child[2] = NULL;
	m_child[3] = NULL;
}


CollisionPart::~CollisionPart(){
	colliders.clear();
	if (hasChildren()){
		delete m_child[0];
		delete m_child[1];
		delete m_child[2];
		delete m_child[3];
	}
}

void CollisionPart::createSubPartitions(int nbrLevels){
	if (m_level < nbrLevels - 1){
		float newSizeX = (boxMax.x - boxMin.x) / 2;
		float newSizeY = boxMax.y - boxMin.y;
		float newSizeZ = (boxMax.z - boxMin.z) / 2;

		m_child[0] = new CollisionPart(this, m_level + 1, Centre.x + (newSizeX / 2), Centre.y, Centre.z - (newSizeZ / 2), newSizeX, newSizeY, newSizeZ);
		m_child[1] = new CollisionPart(this, m_level + 1, Centre.x + (newSizeX / 2), Centre.y, Centre.z + (newSizeZ / 2), newSizeX, newSizeY, newSizeZ);
		m_child[2] = new CollisionPart(this, m_level + 1, Centre.x - (newSizeX / 2), Centre.y, Centre.z - (newSizeZ / 2), newSizeX, newSizeY, newSizeZ);
		m_child[3] = new CollisionPart(this, m_level + 1, Centre.x - (newSizeX / 2), Centre.y, Centre.z + (newSizeZ / 2), newSizeX, newSizeY, newSizeZ);

		m_child[0]->createSubPartitions(nbrLevels);
		m_child[1]->createSubPartitions(nbrLevels);
		m_child[2]->createSubPartitions(nbrLevels);
		m_child[3]->createSubPartitions(nbrLevels);
	}
}

void CollisionPart::addCollider(Collider* collider){
	if (!hasChildren()){
		colliders.push_back(collider);
		return;
	}
	
	int index = 0;
	index += (collider->getPosition().x > Centre.x) ? 0 : 2;
	index += (collider->getPosition().z < Centre.z) ? 0 : 1;

	if (m_child[index]->contains(collider)){
		m_child[index]->addCollider(collider);
	}
	else{
		colliders.push_back(collider);
	}
}

bool CollisionPart::contains(Collider* collider){
	if (collider->getBoxMax().x > boxMax.x) return false;
	if (collider->getBoxMin().x < boxMin.x) return false;
	if (collider->getBoxMax().y > boxMax.y) return false;
	if (collider->getBoxMin().y < boxMin.y) return false;
	if (collider->getBoxMax().z > boxMax.z) return false;
	if (collider->getBoxMin().z < boxMin.z) return false;
	return true;
}

bool CollisionPart::removeCollider(Collider* collider){
	std::vector<Collider*>::iterator it;
	for (it = colliders.begin(); it != colliders.end(); it++){
		if ((*it) == collider){
			colliders.erase(it);
			return true;
		}
	}
	if (m_child[0]->removeCollider(collider)) return true;
	if (m_child[1]->removeCollider(collider)) return true;
	if (m_child[2]->removeCollider(collider)) return true;
	if (m_child[3]->removeCollider(collider)) return true;
	return false;
}

void CollisionPart::processCollisions(){
	if (hasChildren()){
		m_child[0]->processCollisions();
		m_child[1]->processCollisions();
		m_child[2]->processCollisions();
		m_child[3]->processCollisions();
	}
	
	for (int i = 0; i < colliders.size(); i++){
		if (contains(colliders[i])){
			if (hasChildren()){
				for (int j = 0; j < 4; j++){
					if (m_child[j]->contains(colliders[i])){
						Collider* temp;
						temp = colliders[i];
						removeCollider(colliders[i]);
						m_child[j]->addCollider(temp);
						if (i > 0) i--;
						if (colliders.size() == 0) break;
					}
				}
			}
		}
		else{
			Collider* temp;
			temp = colliders[i];
			removeCollider(colliders[i]);
			getRoot()->addCollider(temp);
		}
	}

	int numCol = colliders.size();
	
	if (numCol > 1){
		for (int i = 0; i < numCol - 1; i++){
			for (int j = i+1; j < numCol; j++){
				if (colliders[i]->CheckCollision(colliders[j])){
					colliders[i]->getAttachedObject()->Collided(colliders[j]);
					colliders[j]->getAttachedObject()->Collided(colliders[i]);
				}
			}
		}
	}
	if (numCol > 0 && m_parent){
		m_parent->processBorderCollisions(this);
	}
}

void CollisionPart::processBorderCollisions(CollisionPart* part){
	if (colliders.size() > 0){
		for (auto& collider : colliders){
			for (auto& collider2 : part->colliders){
				if (collider->CheckCollision(collider2)){
					collider->getAttachedObject()->Collided(collider2);
					collider2->getAttachedObject()->Collided(collider);
				}
			}
		}
	}
	if (m_parent){
		m_parent->processBorderCollisions(part);
	}
}

CollisionPart* CollisionPart::getRoot(){
	if (m_parent == NULL){
		return this;
	}
	else{
		return m_parent->getRoot();
	}
}

void CollisionPart::Render(){
	if (colliders.size() > 0){
//		renderBox->Render();
	}

	if (hasChildren()){
		m_child[0]->Render();
		m_child[1]->Render();
		m_child[2]->Render();
		m_child[3]->Render();
	}
}