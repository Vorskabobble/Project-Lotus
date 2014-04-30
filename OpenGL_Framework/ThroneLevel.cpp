#include "ThroneLevel.h"

ThroneLevel::ThroneLevel(std::string name): CastleLevel(name){
	troopHealth = guiHandle->newElement(STATUS, "throneHealth", 0, 0, 100, 10, name);
	troopHealth->setRender(false);
	troopHealth->set3D(true);
	kingsGaurd = NULL;
	throne = NULL;
}

ThroneLevel::~ThroneLevel(){
}

void ThroneLevel::setThrone(Object* obj){
	throne = obj;
}

void ThroneLevel::localUpdate(){
	if (model && model->getCollider()){

	}
	if (kingsGaurd){
		troopHealth->setPosition(kingsGaurd->getMove()->getPosition().x, kingsGaurd->getMove()->getPosition().y, kingsGaurd->getMove()->getPosition().z);
		kingsGaurd->Update();
	}
	if (Game->INPUT.keyPressed[VK_LBUTTON]){
		GLdouble fx, fy, fz;
		gluUnProject(Game->INPUT.mouseX, Game->INPUT.mouseY, 1.0f, Game->GL.modelView, Game->GL.projection, Game->GL.viewport, &fx, &fy, &fz);
		Vector temp = Vector(fx, fy, fz);
		if (gateMod->getCollider()->clickCollision(Vector(Game->SCREEN.camX, Game->SCREEN.camY, Game->SCREEN.camZ), temp)){
			OutputDebugStringA("click");
		}
	}
}

void ThroneLevel::localRender(){
	if (throne){
		throne->Render();
	}
	if (kingsGaurd){
		kingsGaurd->Render();
	}
}