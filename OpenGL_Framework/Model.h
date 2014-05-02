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
	//copy constructor
	Model(const Model& model);
	~Model();

	//returns the number of meshes
	int getNumMesh();
	//returns the specified mesh
	s_mesh& getMesh(int index = 0);

	//sets render mode to wireframe or solid
	void setWireframe(bool renderWireframe);

	//loads texture for the model
	void loadTexture(char* pFile);

	void Render();
};