#pragma once
#include "BaseGame.h"
#include "DebugPrint.h"

#include <string>
#include <vector>
using namespace std;

#include "InputAdapter.h"
#include "SceneAdapter.h"

#include "TimeControl.h"
#include "GameDirector.h"
#include "GameInfo.h"

#include "GUI.h"

#include "Scene_Splash.h"

// forward declaration
class BaseObject;

/**
The class inherits from BaseGame and provides the game data model and the game logic
*/
class Game : public BaseGame{
	// Allow event handler direct access to these attributes
	// (copied from BaseGame since friendship is not inherited)
	friend LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
	// HERE WE DECLARE ANY FONTS, TIMERS OR OTHER VARIABLES WE WANT
	InputAdapter* m_input;
	SceneAdapter* scene;

	TimeControl* timeControl;
	GameDirector* director;
	GameInfo* GInfo;

	GUI* GUIHandle;

	Scene_Splash* startScene;

	BFont* Text;

	float lightPos[4];

	// HERE WE DECLARE ANY GAME OBJECTS ("BASEOBJECTS") AND CREATE THEM
	// IN THE INITIALISE METHOD

public:
	Game(void);
	virtual ~Game(void);

	/**
	Use this method to perform any first time initialisation of OpenGL
	*/
	void InitOpenGL();

	/**
	Use this method to create timers, fonts and all game objects. Do NOT 
	execute any OpenGL commands in this method, use initOpenGL instead.
	*/
	void Initialise();

	/**
	Use this method to perform any clean up of objects created for 
	the game - including fonts and timers.
	*/
	void Shutdown();

	/**
	Use this method to create any game objects and initialise the
	game's state
	*/
	bool InitGame();

	/**
	Use this method to update the game's state, but do not use it for rendering
	*/
	void Game::Update();

	/**
	The main rendering method - renders a single frame
	*/
	void Game::Render();

	void Render2D();
};
