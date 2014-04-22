#include "SceneGame.h"

SceneGame::SceneGame(){
	castle = new SmallCastle();
}

SceneGame::~SceneGame(){

}

void SceneGame::Initialise(){
	castle->Initialise();
	collisionEngine->CreateTree(0, 0, 0, 50, 50, 50);
}

void SceneGame::Update(){
	castle->Update();

	if (Game->INPUT.keyPressed[VK_W]){
		mainCamera->getMove()->localMove(Z, -10.0f);
	}
	if (Game->INPUT.keyPressed[VK_S]){
		mainCamera->getMove()->localMove(Z, 10.0f);
	}
	if (Game->INPUT.keyPressed[VK_A]){
		mainCamera->getMove()->localMove(X, 10.0f);
	}
	if (Game->INPUT.keyPressed[VK_D]){
		mainCamera->getMove()->localMove(X, -10.0f);
	}
	if (Game->INPUT.keyPressed[VK_Q]){
		mainCamera->getMove()->rotateBy(Y, 90.0f);
	}
	if (Game->INPUT.keyPressed[VK_E]){
		mainCamera->getMove()->rotateBy(Y, -90.0f);
	}
	if (Game->INPUT.keyPressed[VK_R]){
		mainCamera->getMove()->localMove(Y, 10.0f);
	}
	if (Game->INPUT.keyPressed[VK_F]){
		mainCamera->getMove()->localMove(Y, -10.0f);
	}
	if (Game->INPUT.keyPressed[VK_T] && mainCamera->getMove()->getRotation().x > -90){
		mainCamera->getMove()->rotateBy(X, -90.0f);
	}
	if (Game->INPUT.keyPressed[VK_G] && mainCamera->getMove()->getRotation().x < 90){
		mainCamera->getMove()->rotateBy(X, 90.0f);
	}
}

void SceneGame::Render(){
	mainCamera->Update();

	castle->Render();
	collisionEngine->Render();
}
