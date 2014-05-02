#pragma once

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include <string>

#include "CollisionEngine.h"

#include "Move.h"
#include "Model.h"
#include "Collider.h"
#include "Stats.h"

#include "Color.h"

//Base class for all objects in the game
//most, if not all renderable and collidable objects should inherit from this class

using namespace std;

class Object{
protected:
	const GameInfo* Game;
private:
	Move* m_move;
	Model* m_model;
	Collider* m_collider;
	Stats* m_stats;
//private:
	bool m_enabled;
	int m_id;
	float m_scale;
	string m_name;

	Colour m_color;

	CollisionEngine* CE;

	static int uniqueID;
public:
	Object();
	Object(Object const& obj);
	Object(string name);
	virtual ~Object();

	//set whether to update or not
	void setEnabled(bool enabled);
	//sets the name of the object
	void setName(string name);
	//sets the scale of the object
	void setScale(float scale);
	//sets the collider and sets the colliders attached object to this
	void setCollider(Collider* collider);
	//sets the renderable model of the object
	void setModel(Model* model);
	//sets the colour of the rendable object
	void setColour(Colour color);

	//check if it is enabled
	bool getEnabled();
	//get unique object ID
	int getID();
	//get object name
	string getName();
	//get object model
	Model* getModel();
	//get the movement class to move the object
	Move* getMove();
	//get the collider of the object
	Collider* getCollider();
	//get the stats of the object
	Stats* getStats();
	
	void Update();
	void Render();

	//virtual function to handle collisions
	virtual void Collided(Collider* hitObj){};
	virtual void localUpdate(){};
	virtual void localRender(){};
private:
	static int getUniqueID();
};