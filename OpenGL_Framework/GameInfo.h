#ifndef UTILITY_H
#define UTILITY_H

#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>

#include <stdlib.h>
#include <string>

#include "key_codes.h"

class Scene;

class GameInfo{
private:
	typedef struct{
		bool keyPressed[256];
		int mouseX;
		int mouseY;
	}GAME_INPUT;

	typedef struct{
		float current;
		float last;
		float delta;
		float fps;
		float avgFps;
	}GAME_TIME;

	typedef struct{
		bool load;
		bool unload;
		bool change;
		Scene* scene;
		std::string loadName;
		std::string unloadName;
		std::string changeName;
	}GAME_MANAGER;

	typedef struct{
		int width;
		int height;
		HDC hDC;
	}GAME_SCREEN;

	typedef struct{
		GLint viewport[4];
		GLdouble projection[16];
		GLdouble modelView[16];
	}GL_MATRICES;

	GameInfo();
	static GameInfo* instance;
public:
	~GameInfo();
	static GameInfo* getInstance();

	GAME_INPUT INPUT;
	GAME_MANAGER MANAGER;
	GAME_TIME TIME;
	GAME_SCREEN SCREEN;
	GL_MATRICES GL;
};
#endif //!UTILITY_H