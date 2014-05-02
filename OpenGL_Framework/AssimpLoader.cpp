#include "AssimpLoader.h"
#include "DebugPrint.h"

AssimpLoader::AssimpLoader(){
	model = NULL;
}

AssimpLoader::~AssimpLoader(){
	if (model){
		delete model;
	}
}

Model* AssimpLoader::getModel(){
	return model;
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
		s_mesh* meshes = new s_mesh[scene->mNumMeshes];

		for (int i = 0; i < scene->mNumMeshes; i++){
			s_mesh* temp = processModel(scene->mMeshes[i]);
			meshes[i] = *temp;
			delete temp;
		}
		model = new Model(scene->mNumMeshes, meshes);
		delete[] meshes;
	}
}

s_mesh* AssimpLoader::processModel(const aiMesh* mesh){
	//#############################
	//Mesh initialisation
	s_mesh* t_mesh = new s_mesh;
	t_mesh->numVerts = mesh->mNumVertices;
	t_mesh->numFaces = mesh->mNumFaces;

	t_mesh->vertexArray = NULL;
	t_mesh->normalArray = NULL;
	t_mesh->textUVArray = NULL;
	t_mesh->vertices = NULL;
	//#############################

	if (mesh->HasPositions()){
		t_mesh->vertices = new vect3[t_mesh->numVerts];
		memcpy(t_mesh->vertices, mesh->mVertices, sizeof(vect3));

		t_mesh->vertexArray = new vect3[t_mesh->numFaces * 3];
		for (int i = 0; i < t_mesh->numFaces; i++){
			for (int j = 0; j < 3; j++){
				aiVector3D vertAPos = mesh->mVertices[mesh->mFaces[i].mIndices[j]];
				memcpy(t_mesh->vertexArray, &vertAPos, sizeof(vect3));
				t_mesh->vertexArray++;
			}
		}
		t_mesh->vertexArray -= t_mesh->numFaces * 3;
	}

	if (mesh->HasNormals()){
		t_mesh->normalArray = new vect3[t_mesh->numFaces * 3];
		for (int i = 0; i < t_mesh->numFaces; i++){
			for (int j = 0; j < 3; j++){
				aiVector3D normAPos = mesh->mNormals[mesh->mFaces[i].mIndices[j]];
				memcpy(t_mesh->normalArray, &normAPos, sizeof(vect3));
				t_mesh->normalArray++;
			}
		}
		t_mesh->normalArray -= t_mesh->numFaces * 3;
	}

	if (mesh->HasTextureCoords(0)){
		t_mesh->textUVArray = new vect2[t_mesh->numFaces * 3];
		for (int i = 0; i < t_mesh->numFaces; i++){
			for (int j = 0; j < 3; j++){
				aiVector3D textAPos = mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[j]];
				memcpy(t_mesh->textUVArray, &textAPos, sizeof(vect2));
				t_mesh->textUVArray++;
			}
		}
		t_mesh->textUVArray -= t_mesh->numFaces * 3;
	}
	return t_mesh;
}