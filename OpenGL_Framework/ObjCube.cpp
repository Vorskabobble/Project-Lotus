#include "ObjCube.h"


ObjCube::ObjCube(){
	m_xSize = m_ySize = m_zSize = 0;
}

ObjCube::ObjCube(float size, float scale) : Object(8, scale){
	m_xSize = m_ySize = m_zSize = size;
	setSize();
}

ObjCube::ObjCube(float xSize, float ySize, float zSize, float scale) : Object(8, scale){
	m_xSize = xSize;
	m_ySize = ySize;
	m_zSize = zSize;
	setSize();
}

ObjCube::~ObjCube(){
}

void ObjCube::setSize(){
	float hsx = (m_xSize / 2) * m_scale;
	float hsy = (m_ySize / 2) * m_scale;
	float hsz = (m_zSize / 2) * m_scale;
	m_verts[0].set(-hsx, hsy, hsz);
	m_verts[1].set(hsx, hsy, hsz);
	m_verts[2].set(hsx, hsy, -hsz);
	m_verts[3].set(-hsx, hsy, -hsz);
	m_verts[4].set(-hsx, -hsy, hsz);
	m_verts[5].set(hsx, -hsy, hsz);
	m_verts[6].set(hsx, -hsy, -hsz);
	m_verts[7].set(-hsx, -hsy, -hsz);
}

void ObjCube::resize(float size){
	m_xSize = m_ySize = m_zSize = size;
	setSize();
}

void ObjCube::resize(float xSize, float ySize, float zSize){
	m_xSize = xSize;
	m_ySize = ySize;
	m_zSize = zSize;
	setSize();
}

void ObjCube::Render(){
	m_move->Update();
	glPushMatrix();
		glScalef(m_scale, m_scale, m_scale);
		glTranslatef(m_move->position->x, m_move->position->y, m_move->position->z);
		glRotatef(m_move->rotation->y, 0.0f, 1.0f, 0.0f);
		glRotatef(m_move->rotation->x, 1.0f, 0.0f, 0.0f);
		glRotatef(m_move->rotation->z, 0.0f, 0.0f, 1.0f);
		glColor3f(m_color.r, m_color.g, m_color.b);
		drawFace(0, 4, 5, 1);
		drawFace(3, 7, 4, 0);
		drawFace(2, 6, 7, 3);
		drawFace(1, 5, 6, 2);
		drawFace(3, 0, 1, 2);
		drawFace(4, 7, 6, 5);
	glPopMatrix();
}