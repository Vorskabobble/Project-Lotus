#pragma once

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "Move.h"
#include "Skybox.h"

class Camera{
private:
	Move* move;
	Skybox* skybox;
public:
	Camera();
	~Camera();

	Move* getMove();

	void Update();
};

