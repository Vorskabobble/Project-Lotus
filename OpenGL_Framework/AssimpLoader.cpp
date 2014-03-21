#include "AssimpLoader.h"

AssimpLoader::AssimpLoader(){
	numModels = 0;
	models = NULL;
}

AssimpLoader::~AssimpLoader(){
	if (models){
		delete models;
	}
}

int AssimpLoader::getNumModels(){
	return numModels;
}

MODEL* AssimpLoader::getModel(int index){
	if (index < numModels && index >= 0){
		return &models[index];
	}
	return NULL;
}

bool AssimpLoader::loadScene(const std::string& pFile){
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(pFile,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);

	if (!scene){
		return false;
	}

	processScene(scene);

	return true;
}

void AssimpLoader::processScene(const aiScene* scene){
	if (scene->HasMeshes()){
		numModels = scene->mNumMeshes;
		models = new MODEL[numModels];
		for (int i = 0; i < numModels; i++){
			processModel(scene->mMeshes[i], models[i]);
		}
	}
}

void AssimpLoader::processModel(const aiMesh* mesh, MODEL& model){
	model.numVerts = mesh->mNumVertices;
	model.vertices = new Vector[model.numVerts];
	model.UVCoords = new Vector[model.numVerts];
	model.normals = new Vector[model.numVerts];
	for (int i = 0; i < model.numVerts; i++){
		model.vertices[i].x = mesh->mVertices->x;
		model.vertices[i].y = mesh->mVertices->y;
		model.vertices[i].z = mesh->mVertices->z;

		model.UVCoords[i].x = mesh->mTextureCoords[i]->x;
		model.UVCoords[i].y = mesh->mTextureCoords[i]->y;
		model.UVCoords[i].z = mesh->mTextureCoords[i]->z;

		model.normals[i].x = mesh->mNormals->x;
		model.normals[i].y = mesh->mNormals->y;
		model.normals[i].z = mesh->mNormals->z;
	}
	model.numTris = mesh->mNumFaces;
	model.triangles = new FACE[model.numTris];
	for (int i = 0; i < model.numTris; i++){
		model.triangles[i].numIndices = mesh->mFaces->mNumIndices;
		model.triangles[i].vertIndices = new float[model.triangles[i].numIndices];
		for (int j = 0; j < model.triangles[i].numIndices; j++){
			model.triangles[i].vertIndices[j] = mesh->mFaces->mIndices[j];
		}
	}
}