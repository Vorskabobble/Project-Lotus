#pragma once

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "Move.h"

class Camera{
public:
	Move* move;
public:
	Camera();
	~Camera();

	void Update();
};

