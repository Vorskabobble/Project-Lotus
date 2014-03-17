#include "Game.h"
#include "Move.h"

Game::Game(void){
}

Game::~Game(void){
	delete m_input;
	delete scene;
	delete timeControl;
	delete director;
}

void Game::InitOpenGL(){
	DebugOut("Game::InitOpenGL being called");
}

void Game::Initialise(){
	DebugOut("Game::Initialise being called");
	m_input = new InputAdapter();
	scene = new SceneAdapter();

	timeControl = TimeControl::getInstance();
	director = GameDirector::getInstance();
}

void Game::Shutdown(){
	DebugOut("Game::Shutdown being called");
	m_objects.clear();
}

void Game::Update(){
	timeControl->Update();
	char s[250];
	sprintf_s(s, "delta : %2.20f, current : %2.20f, last : %2.20f, FPS : %3.3f", GAME_TIME.delta, GAME_TIME.current, GAME_TIME.last, GAME_TIME.fps);
	if (GAME_INPUT.keyPressed[VK_SPACE]){
		DebugOut(s);
	}
	scene->update();
}

// Render the objects in their current state.
void Game::Render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(1.0f, 2.5f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	scene->update();
	scene->render();

	glFlush();
}
