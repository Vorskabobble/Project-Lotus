#pragma once

//structures for holding mesh data used in a model

typedef struct{
	float x;
	float y;
}vect2;

typedef struct{
	float x;
	float y;
	float z;
}vect3;

typedef struct {
	int numVerts;
	int numFaces;

	vect3* vertexArray;
	vect3* normalArray;
	vect2* textUVArray;

	vect3* vertices;
}s_mesh;
