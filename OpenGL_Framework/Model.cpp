#include "Model.h"

Model::Model(){
	numMesh = 0;
	meshes = NULL;
	wireframe = false;
	texID = 0;
}

Model::Model(int numMeshes, s_mesh* mesh){
	numMesh = numMeshes;
	wireframe = false;
	texID = 0;

	meshes = new s_mesh[numMesh];
	for (int i = 0; i < numMesh; i++){
		meshes[i].numVerts = mesh[i].numVerts;
		meshes[i].numFaces = mesh[i].numFaces;
		meshes[i].vertexArray = new vect3[meshes[i].numFaces * 3];
		memcpy(meshes[i].vertexArray, mesh[i].vertexArray, sizeof(vect3)* meshes[i].numFaces * 3);

		if (mesh[i].normalArray){
			meshes[i].normalArray = new vect3[meshes[i].numFaces * 3];
			memcpy(meshes[i].normalArray, mesh[i].normalArray, sizeof(vect3)* meshes[i].numFaces * 3);
		}
		else{
			meshes[i].normalArray = NULL;
		}

		if (mesh[i].textUVArray){
			meshes[i].textUVArray = new vect2[meshes[i].numFaces * 3];
			memcpy(meshes[i].textUVArray, mesh[i].textUVArray, sizeof(vect2)* meshes[i].numFaces * 3);
		}
		else{
			meshes[i].textUVArray = NULL;
		}

		if (mesh[i].vertices){
			meshes[i].vertices = new vect3[meshes[i].numVerts];
			memcpy(meshes[i].vertices, mesh[i].vertices, sizeof(vect3)* meshes[i].numVerts);
		}
		else{
			meshes[i].vertices = NULL;
		}
	}
}

Model::Model(const Model& model){
	numMesh = model.numMesh;
	texID = model.texID;
	wireframe = model.wireframe;

	meshes = new s_mesh[numMesh];
	for (int i = 0; i < numMesh; i++){
		meshes[i].numVerts = model.meshes[i].numVerts;
		meshes[i].numFaces = model.meshes[i].numFaces;
		meshes[i].vertexArray = new vect3[meshes[i].numFaces * 3];
		memcpy(meshes[i].vertexArray, model.meshes[i].vertexArray, sizeof(vect3)* meshes[i].numFaces * 3);

		if (model.meshes[i].normalArray){
			meshes[i].normalArray = new vect3[meshes[i].numFaces * 3];
			memcpy(meshes[i].normalArray, model.meshes[i].normalArray, sizeof(vect3)* meshes[i].numFaces * 3);
		}
		else{
			meshes[i].normalArray = NULL;
		}

		if (model.meshes[i].textUVArray){
			meshes[i].textUVArray = new vect2[meshes[i].numFaces * 3];
			memcpy(meshes[i].textUVArray, model.meshes[i].textUVArray, sizeof(vect2)* meshes[i].numFaces * 3);
		}
		else{
			meshes[i].textUVArray = NULL;
		}

		if (model.meshes[i].vertices){
			meshes[i].vertices = new vect3[meshes[i].numVerts];
			memcpy(meshes[i].vertices, model.meshes[i].vertices, sizeof(vect3)* meshes[i].numVerts);
		}
		else{
			meshes[i].vertices = NULL;
		}
	}
}

Model::~Model(){
	if (meshes){
		for (int i = 0; i < numMesh; i++){
			if (meshes[i].vertexArray){
				delete[] meshes[i].vertexArray;
				meshes[i].vertexArray = NULL;
			}
			if (meshes[i].normalArray){
				delete[] meshes[i].normalArray;
				meshes[i].normalArray = NULL;
			}
			if (meshes[i].textUVArray){
				delete[] meshes[i].textUVArray;
				meshes[i].textUVArray = NULL;
			}
			if (meshes[i].vertices){
				delete[] meshes[i].vertices;
				meshes[i].vertices = NULL;
			}
		}
		delete[] meshes;
		meshes = NULL;
	}
}

int Model::getNumMesh(){
	return numMesh;
}

s_mesh& Model::getMesh(int index){
	if (index < 0 && index >= numMesh){
		index = 0;
	}
	return meshes[index];
}

void Model::setWireframe(bool renderWireframe){
	wireframe = renderWireframe;
}

void Model::Render(){
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glBindTexture(GL_TEXTURE_2D, texID);

	for (int i = 0; i < numMesh; i++){
		glVertexPointer(3, GL_FLOAT, 0, meshes[i].vertexArray);
		
		if (meshes[i].normalArray){
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, 0, meshes[i].normalArray);
		}
		if (meshes[i].textUVArray){
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(2, GL_FLOAT, 0, meshes[i].textUVArray);
		}

		if (wireframe){
			glDrawArrays(GL_LINE_LOOP, 0, meshes[i].numFaces * 3);
		}
		else{
			glDrawArrays(GL_TRIANGLES, 0, meshes[i].numFaces * 3);
		}
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
}

void Model::loadTexture(char* pFile){
//	glDeleteTextures(1, &texID);
	LoadTextures* lt = new LoadTextures(pFile);
	texID = lt->getTexture();
	delete lt;
}

