//Corey Bradford, University of Bolton

#pragma once

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "vector.h"
#include "Mesh.h"

class Model{
private:
	int numMesh;
	s_mesh* meshes;
public:
	Model();
	Model(int numMeshes, s_mesh* mesh);
	~Model();

	int getNumMesh();
	s_mesh& getMesh(int index = 0);

	void Render();
};