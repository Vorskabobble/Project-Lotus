#include "SceneGame.h"

SceneGame::SceneGame(){
	castle = new SmallCastle();
	terrain = NULL;
}

SceneGame::~SceneGame(){
	if (castle){
		delete castle;
	}
	if (tGen){
		delete tGen;
	}
	if (spawner){
		delete spawner;
	}
	if (terrain){
		delete terrain;
	}

	while (!barbarians.empty()){
		delete barbarians[barbarians.size() - 1];
		barbarians.pop_back();
	}
	collisionEngine->DeleteTree();
	GUIHandle->ReleaseWindow("game");
}

void SceneGame::Initialise(){
	collisionEngine->CreateTree(0, 0, 0, 50, 50, 50);
	castle->Initialise();

	guitimer = 0.0f;

	mainCamera->getMove()->getPosition().set(10, 20, 40);
	mainCamera->getMove()->rotateTo(X, 30);

	numEnemies = 1;

	//randomly create the terrain
	tGen = new TerrainGenerator();
	tGen->generateMap(LAND);
	terrain = new Terrain();
	terrain->Initialise();
	terrain->setPosition(Vector(-200, -100, -400));


	spawner = new BRTroopCreator();
	spawnTimer = 0.0f;
	spawnSpeed = 10.0f;

	gameTime = 0.0f;

	director->setGameInfo("gold", 300);

	//Creating GUI elements for the scene
	GUIHandle->newWindow("game", 0, 0, 100, 100);
	GUIHandle->newElement(BUTTON, "gold", Game->SCREEN.width / 2 - 150, Game->SCREEN.height - 210, 300, 75, "game");
	GUIHandle->getWindow("game")->getElement("gold")->setFont(50);
	GUIHandle->newElement(BUTTON, "time", Game->SCREEN.width / 2 - 100, 20, 200, 75, "game");
	GUIHandle->getWindow("game")->getElement("time")->setFont(50);

	GUIHandle->newElement(BUTTON, "goldlvl", Game->SCREEN.width / 2 + 10, Game->SCREEN.height - 100, 200, 75, "game");
	GUIHandle->getWindow("game")->getElement("goldlvl")->setRender(false);
	GUIHandle->getWindow("game")->getElement("goldlvl")->setFont(50);
	GUIHandle->getWindow("game")->getElement("goldlvl")->setColour(Colour{ 0.0, 0.8, 0.0, 1.0 });
}

void SceneGame::Update(){
	//Update game info with camera position
	Game->SCREEN.camX = mainCamera->getMove()->getPosition().x;
	Game->SCREEN.camY = mainCamera->getMove()->getPosition().y;
	Game->SCREEN.camZ = mainCamera->getMove()->getPosition().z;

	collisionEngine->Update();

	spawnTimer += Game->TIME.delta;
	gameTime += Game->TIME.delta;

	//spawn enemies at a set interval that decreases over time
	if (spawnTimer > spawnSpeed){
		numEnemies++;
		PlayerTroop* t_troop = spawner->CreateTroop(BRMILITIA);
		t_troop->getMove()->getPosition().set(-100, 0, 0);
		barbarians.push_back(t_troop);
		spawnTimer = 0;
		spawnSpeed -= Game->TIME.delta * 3;
		if (spawnSpeed < 1.0f){
			spawnSpeed = 1.0f;
		}
		int upgrade = numEnemies / 10;
		for (int i = 0; i < upgrade; i++){
			t_troop->Upgrade(1.3f);
		}
	}

	//Update castle and pass gold variable for use
	castle->setGold(director->getGameInfo("gold"));
	castle->Update();
	if (castle->Defeated()){
		director->unloadScene("Game");
		director->changeScene("Menu");
	}

	//set updated gold variable
	director->setGameInfo("gold", castle->getGold());

	//update all of the barbarians
	for (auto& troop : barbarians){
		troop->Update();
		troop->getMove()->move(X, troop->getStats()->getSpeed());
	}

	//delete a barbarian if their health is 0
	int bSize = barbarians.size();
	barbarians.erase(std::remove_if(barbarians.begin(), barbarians.end(), [](PlayerTroop* troop)
	{
		if (troop->getStats()->getHealth() <= 0){
			delete troop;
			return true;
		}
		return false;
	}), barbarians.end());

	//update players gold based on the amount of barbarians killed
	if (bSize > barbarians.size()){
		director->setGameInfo("gold", director->getGameInfo("gold") + (bSize - barbarians.size()) * (50 * (1 + numEnemies/10)));
		char s[100];
		float t = (bSize - barbarians.size()) * (50 * (1 + numEnemies / 10));
		sprintf_s(s, "+%1.0fG", t);
		GUIHandle->getWindow("game")->getElement("goldlvl")->setText(s);
		guitimer = 3.0f;
	}

	//increase gold over time
	director->setGameInfo("gold", director->getGameInfo("gold") + Game->TIME.delta * 2);

	//show gold difference for a short amount of time
	if (guitimer > 0){
		GUIHandle->getWindow("game")->getElement("goldlvl")->setRender(true);
		guitimer -= Game->TIME.delta;
	}
	else{
		guitimer = 0;
		GUIHandle->getWindow("game")->getElement("goldlvl")->setRender(false);
	}

	//show total gold amount
	char c[100];
	sprintf_s(c, "Gold : %1.0f", director->getGameInfo("gold"));
	GUIHandle->getWindow("game")->getElement("gold")->setText(c);

	sprintf_s(c, "%1.0f", gameTime);
	GUIHandle->getWindow("game")->getElement("time")->setText(c);


	//camera input
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
		mainCamera->getMove()->localMove(Y, -10.0f);
	}
	if (Game->INPUT.keyPressed[VK_E]){
		mainCamera->getMove()->localMove(Y, 10.0f);
	}
	if (Game->INPUT.keyPressed[VK_RBUTTON]){
		if (Game->INPUT.lmouseX > 0){
			mainCamera->getMove()->rotateBy(Y, (Game->INPUT.lmouseX - Game->INPUT.mouseX) * 10);
		}
		if (Game->INPUT.lmouseY > 0 && mainCamera->getMove()->getRotation().x < 90 && mainCamera->getMove()->getRotation().x > -90){
			mainCamera->getMove()->rotateBy(X, (Game->INPUT.mouseY - Game->INPUT.lmouseY) * 10);
		}
	}
	//end of camera input
}

void SceneGame::Render(){
	mainCamera->Update();

	terrain->Render();
	castle->Render();
	collisionEngine->Render();

	for (auto& troop : barbarians){
		troop->Render();
	}
}
