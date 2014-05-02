#include "ModelLoader.h"

ModelLoader::ModelLoader(){
}

ModelLoader::~ModelLoader(){
	for (auto& model : models){
		delete model.second;
	}
	models.clear();
}

bool ModelLoader::LoadModel(std::string name, const char* pFile){
	AssimpLoader loader;
	if (!models[name]){
		if (loader.loadScene(pFile)){
			models[name] = new Model(*loader.getModel());
			return true;
		}
	}
	return false;
}

bool ModelLoader::UnLoadModel(std::string name){
	if (models[name]){
		delete models[name];
		models.erase(name);
		return true;
	}
	return false;
}

Model* ModelLoader::getModel(std::string name){
	if (models[name]){
		return models[name];
	}
	return NULL;
}


