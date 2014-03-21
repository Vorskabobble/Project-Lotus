#pragma once

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "vector.h"
#include "Color.h"
#include "Move.h"

class Object{
protected:
	int m_vertNum;

	float m_scale;

	Color m_color;

	Vector* m_verts;

	Move* m_move;
public:
	Object();
	Object(int vertNum, float scale = 1.0f);
	~Object();

	int getVertNum() const;

	float getScale() const;

	Color getColor() const;

	Vector* getAngle() const;
	Vector* getPos() const;

	void setScale(float scale);
	void setColor(Color color);

	Move* move();

	void drawFace(int v0, int v1, int v2, int v3);

	virtual void Render() = 0;
};

