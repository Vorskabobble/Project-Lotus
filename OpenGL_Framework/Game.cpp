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

	startScene = new Scene_Splash();
	director->loadScene("splash", *startScene);
	director->changeScene("splash");
	char s[255];
	sprintf(s, "Version : %s", glGetString(GL_VERSION));
	DebugOut(s);
}

void Game::Shutdown(){
	DebugOut("Game::Shutdown being called");
	m_objects.clear();
}

void Game::Update(){
	timeControl->Update();
	scene->update();
}

// Render the objects in their current state.
void Game::Render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	scene->render();

	glFlush();
}
