//Corey Bradford

#pragma once

#include "vector.h"

#include <stdlib.h>
#include <string>

#include "assimp\Importer.hpp"
#include "assimp\scene.h"
#include "assimp\postprocess.h"

typedef struct{
	int numIndices;
	int* vertIndices;
}FACE;

typedef struct{
	int numVerts;
	int numTris;
	Vector* vertices;
	FACE* triangles;
	Vector* UVCoords;
	Vector* normals;
}MODEL;

class AssimpLoader{
private:
	int numModels;
	MODEL* models;
public:
	AssimpLoader();
	~AssimpLoader();

	int getNumModels();
	MODEL* getModel(int index = 0);
	bool loadScene(const std::string& pFile);
private:
	void processScene(const aiScene* scene);
	void processModel(const aiMesh* mesh, MODEL& model);
};

