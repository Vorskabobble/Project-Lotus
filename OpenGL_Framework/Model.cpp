#include "Model.h"

Model::Model(){
	numMesh = 0;
	meshes = NULL;
}

Model::Model(int numMeshes, s_mesh* mesh){
	numMesh = numMeshes;
	meshes = new s_mesh[numMesh];
	memcpy(meshes, mesh, sizeof(s_mesh)* numMesh);
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

void Model::Render(){
	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_NORMAL_ARRAY);
//	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	for (int i = 0; i < numMesh; i++){
		glVertexPointer(3, GL_FLOAT, 0, meshes[i].vertexArray);
//		glNormalPointer(GL_FLOAT, 3, meshes[i].normalArray);
//		glTexCoordPointer(2, GL_FLOAT, 2, meshes[i].textUVArray);

		glDrawArrays(GL_TRIANGLES, 0, meshes[i].numFaces * 3);
	}

	glDisableClientState(GL_VERTEX_ARRAY);
//	glDisableClientState(GL_NORMAL_ARRAY);
//	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

