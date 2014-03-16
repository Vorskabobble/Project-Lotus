#include "Game.h"
#include "Move.h"

Game::Game(void){
}

Game::~Game(void){
}

void Game::InitOpenGL(){
	DebugOut("Game::InitOpenGL being called");
}

void Game::Initialise(){
	DebugOut("Game::Initialise being called");
	m_input = new InputAdapter();
	scene = new SceneAdapter();
}

void Game::Shutdown(){
	DebugOut("Game::Shutdown being called");
}

void Game::Update(){
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
