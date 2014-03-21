#include "Object.h"


Object::Object(){
	m_scale = m_vertNum = 0;
	m_color = COLOR_WHITE;
	m_verts = NULL;
	m_move = NULL;
}

Object::Object(int vertNum, float scale){
	m_vertNum = vertNum;
	m_scale = scale;

	m_color = COLOR_WHITE;
	m_verts = new Vector[m_vertNum];
	m_move = new Move();
}


Object::~Object(){
	if (m_verts){
		delete[] m_verts;
	}
}

int Object::getVertNum() const{
	return m_vertNum;
}

float Object::getScale() const{
	return m_scale;
}

Color Object::getColor() const{
	return m_color;
}

Vector* Object::getAngle() const{
	return m_move->rotation;
}

Vector* Object::getPos() const{
	return m_move->position;
}

void Object::setScale(float scale){
	m_scale = scale;
}

void Object::setColor(Color color){
	m_color = color;
}

Move* Object::move(){
	return m_move;
}

void Object::drawFace(int v0, int v1, int v2, int v3){
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(m_verts[v0].x, m_verts[v0].y, m_verts[v0].z);
		glVertex3f(m_verts[v1].x, m_verts[v1].y, m_verts[v1].z);
		glVertex3f(m_verts[v2].x, m_verts[v2].y, m_verts[v2].z);
		glVertex3f(m_verts[v2].x, m_verts[v2].y, m_verts[v2].z);
		glVertex3f(m_verts[v0].x, m_verts[v0].y, m_verts[v0].z);
		glVertex3f(m_verts[v3].x, m_verts[v3].y, m_verts[v3].z);
	glEnd();
}