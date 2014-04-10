//Corey Bradford

#pragma once

#include <stdlib.h>
#include <string>

#include "assimp\Importer.hpp"
#include "assimp\scene.h"
#include "assimp\postprocess.h"

#include "Model.h"

class AssimpLoader{
private:
	Model* model;
public:
	AssimpLoader();
	~AssimpLoader();

	Model* getModel();
	bool loadScene(const std::string& pFile);
private:
	void processScene(const aiScene* scene);
	s_mesh* processModel(const aiMesh* mesh);
};

