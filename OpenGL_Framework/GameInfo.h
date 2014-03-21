#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>
#include <string>

class Scene;

class GameInfo{
private:
	typedef struct tagGameInput{
		bool keyPressed[256];
		int mouseX;
		int mouseY;
	}GAME_INPUT;

	typedef struct tagGameTime{
		float current;
		float last;
		float delta;
		float fps;
		float avgFps;
	}GAME_TIME;

	typedef struct tagManageScene{
		bool load;
		bool unload;
		bool change;
		Scene* scene;
		std::string loadName;
		std::string unloadName;
		std::string changeName;
	}GAME_MANAGER;

	GameInfo();
	static GameInfo* instance;
public:
	~GameInfo();
	static GameInfo* getInstance();

	GAME_INPUT INPUT;
	GAME_MANAGER MANAGER;
	GAME_TIME TIME;
};
#endif //!UTILITY_H