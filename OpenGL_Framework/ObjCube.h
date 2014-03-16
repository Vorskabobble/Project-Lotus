#pragma once
#include "Object.h"
class ObjCube : public Object{
private:
	float m_xSize, m_ySize, m_zSize;

	void setSize();
public:
	ObjCube();
	ObjCube(float size, float scale = 1.0f);
	ObjCube(float xSize, float ySize, float zSize, float scale = 1.0f);
	~ObjCube();

	void resize(float size);
	void resize(float xSize, float ySize, float zSize);

	void Render();
};

