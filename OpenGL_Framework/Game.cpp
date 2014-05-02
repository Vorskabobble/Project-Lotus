#include "Game.h"
#include "Move.h"

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

Game::Game(void){
}

Game::~Game(void){
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
	GInfo = GameInfo::getInstance();

	GUIHandle = GUI::getInstance();

	startScene = new Scene_Splash();
	director->loadScene("splash", *startScene);
	director->changeScene("splash");
	Text = new BFont(hDC, "Courier", 14);

	GInfo->SCREEN.width = m_width;
	GInfo->SCREEN.height = m_height;
	GInfo->SCREEN.hDC = hDC;

	lightPos[0] = 0; lightPos[1] = 1; lightPos[2] = 5; lightPos[3] = 1.0f;
	float whiteLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float ambLight[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, whiteLight);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambLight);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void Game::Shutdown(){
	DebugOut("Game::Shutdown being called");

	if (startScene){
		director->unloadScene("splash");
		delete startScene;
	}
	if (scene){
		delete scene;
	}
	if (timeControl){
		delete timeControl;
	}
	if (director){
		delete director;
	}
	if (Text){
		delete Text;
	}
	if (m_input){
		delete m_input;
	}
	if (GUIHandle){
		delete GUIHandle;
	}
	if (GInfo){
//		delete GInfo;
	}
}

void Game::Update(){
	timeControl->Update();

	GUIHandle->Update();

	scene->update();

//	GInfo->INPUT.lmouseX = 0;
//	GInfo->INPUT.lmouseY = 0;
}

// Render the objects in their current state.
void Game::Render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	scene->render();

	glGetIntegerv(GL_VIEWPORT, GInfo->GL.viewport);
	glGetDoublev(GL_MODELVIEW_MATRIX, GInfo->GL.modelView);
	glGetDoublev(GL_PROJECTION_MATRIX, GInfo->GL.projection);

	Render2D();

	glFlush();
}

void Game::Render2D(){
	// Change to 2D view and use 1:1 pixel resolution with
	// [0,0] origin being at the top-left corner.
	Set2D(0, m_width, m_height, 0);
	// Disable depth testing so the HUD will not be hidden
	// by the 3D graphics
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
//#####################################

	GUIHandle->Render();

//#####################################
	
	// Set back to 3D
	Set3D();
}
