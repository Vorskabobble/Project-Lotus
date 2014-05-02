#include "BarracksLevel.h"

BarracksLevel::BarracksLevel(std::string name) : CastleLevel(name){
	m_spawn = NULL;
	captured = false;
	occupied = false;
	creator = new TroopCreator();
	spawnWait = 0.0f;
	milupgr = 1;
	guitimer = 0.0f;
	guiHandle->newWindow("createtroop", 0, 0, 100, 100);
	guiHandle->getWindow("createtroop")->setActive(false);
	guiHandle->getWindow("createtroop")->setRender(false);
	guiHandle->newElement(BUTTON, "militia", 100, 100, 140, 40, "createtroop");
	guiHandle->newElement(BUTTON, "milupgr", 250, 100, 140, 40, "createtroop");
	guiHandle->newElement(BUTTON, "goldlvl", Game->SCREEN.width / 2 - 210, Game->SCREEN.height - 100, 200, 75, name);
	guiHandle->getWindow(name)->getElement("goldlvl")->setRender(false);
	guiHandle->getWindow(name)->getElement("goldlvl")->setFont(50);
	guiHandle->getWindow(name)->getElement("goldlvl")->setColour(Colour{ 0.8, 0.0, 0.0, 1.0 });
	guiHandle->getWindow("createtroop")->getElement("militia")->setFont(30);
	guiHandle->getWindow("createtroop")->getElement("milupgr")->setFont(30);
	guiHandle->getWindow("createtroop")->getElement("militia")->setText("Militia");
	guiHandle->getWindow("createtroop")->getElement("milupgr")->setText("Upgrade");
}

BarracksLevel::~BarracksLevel(){
	if (m_spawn){
		delete m_spawn;
	}
	if (creator){
		delete creator;
	}
	while (!troops.empty()){
		delete troops[troops.size() - 1];
		troops.pop_back();
	}

	guiHandle->ReleaseWindow("createtroop");
}

void BarracksLevel::setSpawn(Vector position){
	if (!m_spawn){
		m_spawn = new Vector(0, 0, 0);
	}
	*m_spawn = position;
}

Vector BarracksLevel::getSpawn(){
	if (m_spawn){
		return *m_spawn;
	}
	return NULL;
}

void BarracksLevel::localUpdate(){
	//Check if player clicked on model collider
	if (Game->INPUT.keyPressed[VK_LBUTTON]){
		GLdouble fx, fy, fz;
		gluUnProject(Game->INPUT.mouseX, (Game->SCREEN.height - Game->INPUT.mouseY), 1.0f, Game->GL.modelView, Game->GL.projection, Game->GL.viewport, &fx, &fy, &fz);
		Vector t_pos = Vector(fx, fy, fz);
		if (model->getCollider()->clickCollision(Vector(Game->SCREEN.camX, Game->SCREEN.camY, Game->SCREEN.camZ), t_pos)){
			guiHandle->getWindow("createtroop")->setActive(true);
			guiHandle->getWindow("createtroop")->setRender(true);
			Game->INPUT.keyPressed[VK_LBUTTON] = false;
		}
		else{
			guiHandle->getWindow("createtroop")->setActive(false);
			guiHandle->getWindow("createtroop")->setRender(false);
		}
	}

	//check if player clicked on spawn militia button
	if (spawnWait > 5.0f && gold >= 100 + (10 * milupgr) && guiHandle->getWindow("createtroop")->getElement("militia")->getState()->used){
		//if yes, spawn militia troop
		PlayerTroop* temp = creator->CreateTroop(MILITIA);
		temp->getMove()->getPosition() = getPosition();
		troops.push_back(temp);
		spawnWait = 0.0f;

		//add healthbar to newly spawned troop
		char c[255];
		sprintf(c, "%i", temp->getID());
		GUIElement* t_gui = guiHandle->newElement(STATUS, c, 0, 0, 50, 10, name);
		t_gui->set3D(true);
		t_gui->setPosition(temp->getMove()->getPosition().x, temp->getMove()->getPosition().y, temp->getMove()->getPosition().z);
		t_gui->setOffset(0, 3, 0);
		t_gui->setSubColour(COLOUR_GREEN);

		//hide buttons
		guiHandle->getWindow("createtroop")->getElement("militia")->getState()->used = false;
		guiHandle->getWindow("createtroop")->setActive(false);
		guiHandle->getWindow("createtroop")->setRender(false);

		//upgrade troop for the amount of upgrade levels
		for (int i = 1; i < milupgr; i++){
			temp->Upgrade(1.1f);
		}

		gold -= 100 + (10 * milupgr);
		guitimer = 3.0f;
		guiHandle->getWindow(name)->getElement("goldlvl")->setText("-100G");
	}

	guiHandle->getWindow("createtroop")->getElement("militia")->setColour(Colour{ 1 -(gold / (100 + (10 * milupgr))), spawnWait / 5.0f, 0.0f, 1.0f });
	guiHandle->getWindow("createtroop")->getElement("milupgr")->setColour(Colour{ 0.0f, gold / (100 + (10 * milupgr)), 0.0f, 1.0f });

	//show gold loss for amount of time
	if (guitimer > 0){
		guiHandle->getWindow(name)->getElement("goldlvl")->setRender(true);
		guitimer -= Game->TIME.delta;
	}
	else{
		guitimer = 0;
		guiHandle->getWindow(name)->getElement("goldlvl")->setRender(false);
	}

	//check if player clicked upgrade button
	if (guiHandle->getWindow("createtroop")->getElement("milupgr")->getState()->used){
		if (gold >= 50 * milupgr){
			gold -= 50 * milupgr;
			guitimer = 3.0f;
			char s[100];
			float t = 50 * milupgr;
			sprintf_s(s, "-%1.0fG", t);
			guiHandle->getWindow(name)->getElement("goldlvl")->setText(s);
			milupgr++;
			guiHandle->getWindow("createtroop")->setActive(false);
			guiHandle->getWindow("createtroop")->setRender(false);
		}
		else{
			//not enough gold
		}
		guiHandle->getWindow("createtroop")->getElement("milupgr")->getState()->used = false;
	}

	//show upgrade level on upgrade button
	char s[255];
	sprintf_s(s, "Upgrade : %i", milupgr);
	guiHandle->getWindow("createtroop")->getElement("milupgr")->setText(s);

	//update all of the player troops
	for (auto& troop : troops){
		troop->Update();
		troop->getMove()->move(X, -troop->getStats()->getSpeed());
		char c[255];
		sprintf(c, "%i", troop->getID());
		guiHandle->getWindow(name)->getElement(c)->getState()->state = troop->getStats()->getHealth() / troop->getStats()->getMaxHealth();
		guiHandle->getWindow(name)->getElement(c)->setPosition(troop->getMove()->getPosition().x, troop->getMove()->getPosition().y, troop->getMove()->getPosition().z);
	}

	//delete a troop if they have no health
	troops.erase(std::remove_if(troops.begin(), troops.end(), [this](PlayerTroop* troop)
	{
		if (troop->getStats()->getHealth() <= 0){
			removeTroop(troop);
			delete troop;
			return true;
		}
		return false;
	}), troops.end());


	spawnWait += Game->TIME.delta;
}

void BarracksLevel::localRender(){
	for (auto& troop : troops){
		troop->Render();
	}
}

void BarracksLevel::removeTroop(PlayerTroop* troop){
	if (troop){
		char c[255];
		sprintf(c, "%i", troop->getID());
		guiHandle->getWindow(name)->releaseElement(c);
	}
}