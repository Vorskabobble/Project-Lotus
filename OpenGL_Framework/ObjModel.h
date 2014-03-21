#pragma once
#include "Object.h"

#include "assimp\Importer.hpp"
#include "assimp\scene.h"
#include "assimp\postprocess.h"

class ObjModel : public Object{
public:
	ObjModel();
	~ObjModel();

	bool LoadModel(const std::string& pFile);
private:
	bool processModel(const aiScene* scene);
};

