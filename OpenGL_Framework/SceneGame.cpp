#include "SceneGame.h"

SceneGame::SceneGame(){
	player = NULL;
	enemy = NULL;
	target = NULL;
}

SceneGame::~SceneGame(){
	if (target){
		delete target;
	}
	if (enemy){
		for (int i = 0; i < numEnemy; i++){
			delete enemy[i];
			enemy[i] = NULL;
		}
		delete enemy;
	}
	GUIHandle->getWindow("base")->releaseElement("TestSlider");
	GUIHandle->getWindow("base")->releaseElement("TestButton");
	GUIHandle->getWindow("base")->releaseElement("HealthSlider");
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
	sndEngine->setSoundVolume(0.3f);

	GUIHandle->newElement(SLIDER, "TestSlider", 10, 10, 20, 500);
	spawnButton = GUIHandle->newElement(BUTTON, "TestButton", 50, 50, 100, 30);
	spawnButton->set3D(true);
	spawnButton->setPosition(-1, 5, 0);
	spawnButton->setText("Buy Troop");
	playerHealth = GUIHandle->newElement(STATUS, "HealthSlider", 10, Game->SCREEN.height - 30, 500, 20);
	playerHealth->set3D(true);
	playerHealth->setPosition(10, -1, 0);
	troopHealth = GUIHandle->newElement(STATUS, "troopHealth", 0, 0, 80, 10);
	troopHealth->set3D(true);
	troopHealth->setRender(false);
//	troopHealth->setColor(COLOR_GREEN);

	sndEngine->play2D("Sounds/The Descent.mp3", true);
}

void SceneGame::Update(){
	float health = director->getGameInfo("Health") / 100;
	playerHealth->getState()->state = health;

	if (hasTroop){
		troopHealth->setPosition(player->move()->position->x, 5, 0);
		troopHealth->getState()->state = (float)player->getStats()->getHealth() / (float)player->getStats()->getMaxHealth();
	}

	for (int i = 0; i < numEnemy; i++){
		enemy[i]->move()->move(Z, -1.0f);
		if (enemy[i]->getPos()->z < 0){
			if (hasTroop && enemy[i]->getPos()->x > player->move()->position->x - 2 && enemy[i]->getPos()->x < player->move()->position->x + 2){
				director->setGameInfo("Score", director->getGameInfo("Score") + 10);
				player->DealDamage(5);
			}
			else{
				director->setGameInfo("Health", director->getGameInfo("Health") - 10);
			}
			enemy[i]->move()->position->set(rand() % 10, 0.0f, 10.0f);
		}
	}
	if (spawnButton->getState()->used){
		if (!hasTroop && !player){
			hasTroop = true;
			player = creator.CreateTroop(MILITIA);
			player->move()->rotateTo(Y, 90);
			troopHealth->setRender(true);
		}
	}
	if (player){
		director->setGameInfo("tHealth", player->getStats()->getHealth());
		if (player->getStats()->getHealth() <= 0){
			delete player;
			player = NULL;
			hasTroop = false;
			troopHealth->setRender(false);
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
		if (player){
			if (player && player->move()->position->x < 10){
				player->move()->move(X, 4.0f);
			}
		}
	}
	if (Game->INPUT.keyPressed[VK_X]){
		if (player){
			if (player && player->move()->position->x > 0){
				player->move()->move(X, -4.0f);
			}
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
	if (player){
		player->Render();
	}
	target->Render();
}
