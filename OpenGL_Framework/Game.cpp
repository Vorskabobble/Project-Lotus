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
	char s[255];
	sprintf(s, "Version : %s", glGetString(GL_VERSION));
	DebugOut(s);
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
	Text = new BFont(hDC, "Courier", 14);
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

	Set2D();
	if (director->getGameInfo("ShowDiff")){
		char s[255];
		sprintf(s, "Time : %4.4f ;", director->getGameInfo("Diff"));
		Text->printString(-1, -1, s);
		Text->printString(-1, 0.95f, "Corey Bradford - University of Bolton");
	}
	if (director->getGameInfo("Menu")){
		Text->printString(-1, 0, "Press SPACE to start Game");
	}
	if (director->getGameInfo("Game")){
		Text->printString(-1, -1, "Press B to buy a troop");
		char s[255];
		sprintf(s, "Health : %4.4f ;\nTroop : %4.4f ;\nScore : %4.4f ;", director->getGameInfo("Health"), director->getGameInfo("tHealth"), director->getGameInfo("Score"));
		Text->printString(-1, 0.8, s);
	}
	Set3D();

	glFlush();
}
