//Corey Bradford, University of Bolton

#pragma once

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "vector.h"
#include "Mesh.h"
#include "LoadTextures.h"

class Model{
private:
	int numMesh;
	unsigned int texID;
	s_mesh* meshes;
	bool wireframe;
public:
	Model();
	Model(int numMeshes, s_mesh* mesh);
	~Model();

	int getNumMesh();
	s_mesh& getMesh(int index = 0);

	void setWireframe(bool renderWireframe);

	void loadTexture(char* pFile);

	void Render();
};