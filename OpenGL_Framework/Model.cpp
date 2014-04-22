#include "Model.h"

Model::Model(){
	numMesh = 0;
	meshes = NULL;
	wireframe = false;
	texID = 0;
}

Model::Model(int numMeshes, s_mesh* mesh){
	numMesh = numMeshes;
	meshes = new s_mesh[numMesh];
	memcpy(meshes, mesh, sizeof(s_mesh)* numMesh);
	wireframe = false;
	texID = 0;
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

