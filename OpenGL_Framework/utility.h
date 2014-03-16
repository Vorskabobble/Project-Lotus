#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>
#include <string>

class Scene;

struct tagGameInput{
	bool keyPressed[256];
	int mouseX;
	int mouseY;
}static GAME_INPUT = { false, 0, 0 };

struct tagGameTime{
	double current;
	double last;
	double delta;
}static GAME_TIME = { 0, 0, 0 };

struct tagManageScene{
	bool load;
	bool unload;
	bool change;
	Scene* scene;
	std::string loadName;
	std::string unloadName;
	std::string changeName;
}static GAME_MANAGER = { false, false, false, NULL, "", "", "" };

static float lerp(float start, float end, float percent){
	if (percent > 1.0f){
		percent = 1.0f;
	}
	else if (percent < 0.0f){
		percent = 0.0f;
	}
	return (start + (percent * (end - start)));
}

#endif //!UTILITY_H