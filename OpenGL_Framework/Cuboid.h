#pragma once

#include "LoadTextures.h"
#include <gl\GL.h>
#include <gl\GLU.h>
#include "vector.h"
//#include "HavokInit.h"
#include "DebugPrint.h"
class Cuboid{
	float verts[24], texCoords[8], m_width, m_height, m_length, m_angle, m_alpha;
	unsigned int indices[24], texture;
	Vector m_pos, m_dir, m_color;
public:
	Cuboid(float w = 0.2f, float h = 0.2f, float l = 0.2f);
	Cuboid(char* image, float w = 0.2f, float h = 0.2f, float l = 0.2f);
	~Cuboid(void);

	float getWidth(){return m_width;};
	float getHeight(){return m_height;};
	float getLength(){return m_length;};
	float getAlpha(){return m_alpha;};
	Vector getColor(){return m_color;};
	Vector getPos(){return m_pos;};

	void setPos(Vector pos);
	void setColor(Vector color);
	void setAlpha(float alpha);

	void render();

	void setDimensions(float w, float h, float l);

	void setTexture(char* image);

	//void update(hkpRigidBody* rb);

	bool checkCollision(Vector pos);
};

