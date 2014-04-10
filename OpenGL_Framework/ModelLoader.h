#pragma once

#include "AssimpLoader.h"
#include <map>

class ModelLoader{
private:
	std::map<std::string, Model*> models;
public:
	bool LoadModel(std::string name, const char* pFile);
	bool UnLoadModel(std::string name);
	Model* getModel(std::string name);

	ModelLoader();
	~ModelLoader();
};

