#include "SmallCastle.h"
#include "objGate.h"
#include "objThrone.h"

SmallCastle::SmallCastle(){
}

SmallCastle::~SmallCastle(){
}

void SmallCastle::Initialise(){
	loader->LoadModel("cube", "Models/cube.obj");
	loader->LoadModel("level", "Models/Level.obj");
	loader->LoadModel("gate", "Models/Gate.obj");

	ThroneLevel* throne = new ThroneLevel("throneLevel");
	Object* t_throne = new objThrone();
	t_throne->setModel(loader->getModel("cube"));
	t_throne->getMove()->getPosition().set(45, 0, 0);
	t_throne->setCollider(collision->newBoxCollider(t_throne->getMove()->getPosition(), 5, 5, 5));
	t_throne->getCollider()->setOffset(Vector(0, 2.5f, 0));
	throne->setThrone(t_throne);

	BarracksLevel* barracks = new BarracksLevel("barracksLevel");
//	Object* t_barracks = new Object("barracks");
//	t_barracks->setModel(loader->getModel("cube"));
//	t_barracks->setCollider(collision->newBoxCollider(t_barracks->getMove()->getPosition(), 2, 2, 2));
//	t_barracks->getCollider()->setCanRender(true);

	Object* level = new Object("level");
	level->setModel(loader->getModel("level"));
	level->getMove()->getRotation().set(0, -90, 0);
	
	Object* gate = new objGate();
	gate->setModel(loader->getModel("gate"));
	gate->getMove()->getPosition().set(0, 0, 0);
	gate->getMove()->getRotation().set(0, -90, 0);
	gate->getStats()->setMaxHealth(10);
	gate->getStats()->setHealth(10);
	gate->setCollider(collision->newBoxCollider(gate->getMove()->getPosition(), 0.5f, 3, 3));
	gate->getCollider()->setOffset(Vector(-10, 1.5f, 0));
	gate->setColour(COLOUR_ORANGE);

	levels["level1"] = new MachineLevel("machineLevel1");
	levels["level1"]->setModel(level);
	levels["level1"]->setGate(gate);

	levels["throne"] = throne;
	levels["throne"]->setModel(level);
	levels["throne"]->setGate(gate);
	levels["throne"]->setPosition(Vector(40, 0, 0));

	level->setCollider(collision->newBoxCollider(Vector(0, 0, 0), 5, 5, 5));
	level->getCollider()->setOffset(Vector(2, 2.5f, 0));
	level->getCollider()->setCanRender(true);

	levels["barracks"] = barracks;
	levels["barracks"]->setModel(level);
	levels["barracks"]->setGate(gate);
	levels["barracks"]->setPosition(Vector(20, 0, 0));

	delete gate;
	delete level;
}
