#include "Scene.h"

Scene::Scene(){
	director = GameDirector::getInstance();
	Game = GameInfo::getInstance();
}

Scene::~Scene(){
}

void Scene::addObject(Object* object){
	m_objects.push_back(object);
}

void Scene::removeObject(Object* object){
	std::vector<Object*>::iterator it;
	for (it = m_objects.begin(); it != m_objects.end(); it++){
		if (*it = object){
			m_objects.erase(it);
		}
	}
}