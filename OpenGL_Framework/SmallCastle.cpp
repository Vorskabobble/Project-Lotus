#include "SmallCastle.h"
#include "objGate.h"
#include "objThrone.h"`

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
	throne->setThrone(t_throne);
	t_throne->getMove()->getPosition().set(25, 0, 0);

	BarracksLevel* barracks = new BarracksLevel("barracksLevel");
	Object* t_barracks = new Object("barracks");
	t_barracks->setModel(loader->getModel("cube"));
	t_barracks->setCollider(collision->newBoxCollider(t_barracks->getMove()->getPosition(), 2, 2, 2));
	t_barracks->getCollider()->setCanRender(true);
	barracks->setModel(t_barracks);

	Object* level = new Object("level");
	level->setModel(loader->getModel("level"));
	level->getMove()->getRotation().set(0, -90, 0);
	
	Object* gate = new objGate();
	gate->setModel(loader->getModel("gate"));
	gate->getMove()->getPosition().set(0, 0, 0);
	gate->getMove()->getRotation().set(0, -90, 0);
	gate->setCollider(collision->newBoxCollider(gate->getMove()->getPosition(), 2, 2, 2));
	gate->getCollider()->setCanRender(true);
	gate->setColor(COLOR_ORANGE);

	levels["level1"] = new MachineLevel("machineLevel1");
	levels["level1"]->setModel(level);
	levels["level1"]->setGate(gate);

	gate->setColor(COLOR_BLUE);
	level->setColor(COLOR_CYAN);

	levels["throne"] = throne;
	levels["throne"]->setModel(level);
	levels["throne"]->setGate(gate);
	levels["throne"]->setPosition(Vector(20, 0, 0));

	gate->setColor(COLOR_PINK);

	levels["barracks"] = barracks;
	levels["barracks"]->setGate(gate);
	levels["barracks"]->setPosition(Vector(40, 0, 0));

}
