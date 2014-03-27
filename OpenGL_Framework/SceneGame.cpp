#include "SceneGame.h"

SceneGame::SceneGame(){
	troop = NULL;
	enemy = NULL;
}

SceneGame::~SceneGame(){
}

void SceneGame::Initialise(){
	numEnemy = 5;
	enemy = new ObjCube*[numEnemy];
	for (int i = 0; i < numEnemy; i++){
		enemy[i] = new ObjCube(1.0f);
		enemy[i]->setColor(COLOR_RED);
		enemy[i]->move()->position->set(0.0f, 0.0f, 2 * i);
	}

	target = new ObjCube(10, 0.2f, 0.1f);
	target->setColor(COLOR_PINK);
	target->move()->position->set(5, 0, 0);

	hasTroop = false;
	director->setGameInfo("Game", 1.0f);
	director->setGameInfo("Score", 0);
	director->setGameInfo("Health", 100);
	director->setGameInfo("tHealth", 0);
	mainCamera->move->setTargetDistance(2);
	mainCamera->move->position->set(5, 5, -10);

	sndEngine = createIrrKlangDevice();
	sndEngine->setSoundVolume(0.2f);

	sndEngine->play2D("Sounds/Call to Adventure.mp3", true);
}

void SceneGame::Update(){
	for (int i = 0; i < numEnemy; i++){
		enemy[i]->move()->move(Z, -1.0f);
		if (enemy[i]->getPos()->z < 0){
			if (hasTroop && enemy[i]->getPos()->x > troop->getPos()->x - 2 && enemy[i]->getPos()->x < troop->getPos()->x + 2){
				director->setGameInfo("Score", director->getGameInfo("Score") + 10);
				director->setGameInfo("tHealth", director->getGameInfo("tHealth") - 5);
			}
			else{
				director->setGameInfo("Health", director->getGameInfo("Health") - 10);
			}
			enemy[i]->move()->position->set(rand() % 10, 0.0f, 10.0f);
		}
	}
	if (Game->INPUT.keyPressed[VK_B]){
		if (!hasTroop && !troop){
			hasTroop = true;
			troop = new ObjCube(1.0f);
			troop->setColor(COLOR_BLUE);
			director->setGameInfo("tHealth", 10);
		}
	}
	if (director->getGameInfo("tHealth") <= 0){
		if (troop){
			delete troop;
			troop = NULL;
			hasTroop = false;
		}
	}
	if (Game->INPUT.keyPressed[VK_W]){
		mainCamera->move->move(Z, 10.0f);
	}
	if (Game->INPUT.keyPressed[VK_S]){
		mainCamera->move->move(Z, -10.0f);
	}
	if (Game->INPUT.keyPressed[VK_A]){
		mainCamera->move->move(X, 10.0f);
	}
	if (Game->INPUT.keyPressed[VK_D]){
		mainCamera->move->move(X, -10.0f);
	}
	if (Game->INPUT.keyPressed[VK_Q]){
		mainCamera->move->move(Y, 10.0f);
	}
	if (Game->INPUT.keyPressed[VK_E]){
		mainCamera->move->move(Y, -10.0f);
	}
	if (Game->INPUT.keyPressed[VK_Z]){
		if (troop && troop->getPos()->x < 10){
			troop->move()->move(X, 4.0f);
		}
	}
	if (Game->INPUT.keyPressed[VK_X]){
		if (troop && troop->getPos()->x > 0){
			troop->move()->move(X, -4.0f);
		}
	}
	if (director->getGameInfo("Health") <= 0){
		director->changeScene("Menu");
	}
}

void SceneGame::Render(){
	mainCamera->Update();
	for (int i = 0; i < numEnemy; i++){
		enemy[i]->Render();
	}
	if (troop){
		troop->Render();
	}
	target->Render();
}
