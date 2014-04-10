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
		loader.loadScene(pFile);
		*models[name] = *loader.getModel();
		return true;
	}
	return false;
}

bool ModelLoader::UnLoadModel(std::string name){
	if (models[name]){
		delete models[name];
		models[name] = NULL;
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


