#pragma once

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include <string>

#include "Move.h"
#include "Model.h"
#include "Collider.h"
#include "Stats.h"

#include "Color.h"

using namespace std;

class Object{
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

	Color m_color;

	static int uniqueID;
public:
	Object();
	Object(Object const& obj);
	Object(string name);
	~Object();

	void setEnabled(bool enabled);
	void setName(string name);
	void setScale(float scale);
	void setCollider(Collider* collider);
	void setModel(Model* model);
	void setColor(Color color);

	bool getEnabled();
	int getID();
	string getName();
	Model* getModel();
	Move* getMove();
	Collider* getCollider();
	Stats* getStats();
	
	void Update();
	void Render();

	virtual void Collided(Collider* hitObj){};
	virtual void localUpdate(){};
	virtual void localRender(){};
private:
	static int getUniqueID();
};