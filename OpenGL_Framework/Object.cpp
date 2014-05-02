#include "Object.h"

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

int Object::uniqueID = 0;

Object::Object(){
	m_move = NULL;
	m_model = NULL;
	m_collider = NULL;
	m_stats = NULL;
	m_enabled = false;
	m_scale = 1.0f;
	m_name = "Unnamed";
	m_color = COLOUR_WHITE;
	m_id = getUniqueID();
	CE = CollisionEngine::getInstance();
	Game = GameInfo::getInstance();
}

Object::Object(Object const& obj){
	CE = CollisionEngine::getInstance();
	m_move = new Move(*obj.m_move);

	if (obj.m_model){
		m_model = new Model(*obj.m_model);
	}
	else {
		m_model = NULL;
	}
	if (obj.m_stats){
		m_stats = new Stats();
		memcpy(m_stats, obj.m_stats, sizeof(Stats));
	}
	else{
		m_stats = NULL;
	}
	if (obj.m_collider){
		m_collider = CE->newBoxCollider(obj.m_move->getPosition(), obj.m_collider->getDimensions().x, obj.m_collider->getDimensions().y, obj.m_collider->getDimensions().z);
		m_collider->setAttachedObject(this);
		m_collider->setCanRender(obj.m_collider->getRenderable());
		m_collider->setOffset(obj.m_collider->getOffset());
	}
	else{
		m_collider = NULL;
	}
	m_enabled = obj.m_enabled;
	m_scale = obj.m_scale;
	m_name = obj.m_name;
	m_color = obj.m_color;
	m_id = getUniqueID();
	Game = GameInfo::getInstance();
}

Object::Object(string name){
	m_move = new Move();
	m_model = NULL;
	m_collider = NULL;
	m_stats = new Stats();
	m_enabled = true;
	m_scale = 1.0f;
	m_name = name;
	m_color = COLOUR_WHITE;
	m_id = getUniqueID();
	CE = CollisionEngine::getInstance();
	Game = GameInfo::getInstance();
}

Object::~Object(){
	if (m_move){
		delete m_move;
	}
	if (m_stats){
		delete m_stats;
	}
	if (m_collider){
		CE->releaseCollider(m_collider);
		m_collider = NULL;
	}
	if (m_model){
		delete m_model;
	}
}

void Object::setEnabled(bool enabled){
	m_enabled = enabled;
}

void Object::setName(string name){
	m_name = name;
}

void Object::setScale(float scale){
	m_scale = scale;
}

void Object::setCollider(Collider* collider){
	m_collider = collider;
	collider->setAttachedObject(this);
}

void Object::setModel(Model* model){
	if (m_model){
		delete m_model;
	}
	m_model = new Model(*model);
}

void Object::setColour(Colour color){
	m_color = color;
}

bool Object::getEnabled(){
	return m_enabled;
}

int Object::getID(){
	return m_id;
}

string Object::getName(){
	return m_name;
}

Model* Object::getModel(){
	return m_model;
}

Move* Object::getMove(){
	return m_move;
}

Collider* Object::getCollider(){
	return m_collider;
}

Stats* Object::getStats(){
	return m_stats;
}

void Object::Update(){
	if (m_move){
		m_move->Update();
	}
	if (m_collider){
		m_collider->setPosition(m_move->getPosition());
	}
	localUpdate();
}

void Object::Render(){
	if (m_move){
		glPushMatrix();
		float colLight[] = { m_color.r, m_color.g, m_color.b, m_color.a };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, colLight);
		if (m_color.a < 1.0f){
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glDepthMask(0);
		}
			glTranslatef(m_move->getPosition().x, m_move->getPosition().y, m_move->getPosition().z);		
			
			if (m_collider){
				m_collider->Render();
			}

			glRotatef(m_move->getRotation().y, 0.0f, 1.0f, 0.0f);
			glRotatef(m_move->getRotation().x, 1.0f, 0.0f, 0.0f);
			glRotatef(m_move->getRotation().z, 0.0f, 0.0f, 1.0f);
			glScalef(m_scale, m_scale, m_scale);
			glColor4f(m_color.r, m_color.g, m_color.b, m_color.a);
			if (m_model){
				m_model->Render();
			}
			localRender();
		glDisable(GL_BLEND);
		glDepthMask(1);
		float whiteLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteLight);
		glPopMatrix();
	}
}

int Object::getUniqueID(){
	int t = uniqueID;
	uniqueID++;
	return t;
}