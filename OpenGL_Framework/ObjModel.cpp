#include "ObjModel.h"

ObjModel::ObjModel(){
}

ObjModel::~ObjModel(){
}

bool ObjModel::LoadModel(const std::string& pFile){
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(pFile,
		aiProcess_CalcTangentSpace		|
		aiProcess_Triangulate			|
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);

	if (!scene){
		return false;
	}

	processModel(scene);

	return true;
}

bool ObjModel::processModel(const aiScene* scene){
	return false;
}
