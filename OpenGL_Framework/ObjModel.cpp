#include "ObjModel.h"

ObjModel::ObjModel(){
	m_color = COLOR_WHITE;
	m_scale = 1.0f;
	m_move = new Move();
	model = NULL;
}

ObjModel::~ObjModel(){
	delete model;
}

bool ObjModel::LoadModel(const std::string& pFile){
	AssimpLoader loader;
	if (loader.loadScene(pFile)){
		model = loader.getModel();
		return true;
	}
	return false;
}

void ObjModel::Render(){
	m_move->Update();
	glPushMatrix();
		glTranslatef(m_move->position->x, m_move->position->y, m_move->position->z);
		glRotatef(m_move->rotation->y, 0.0f, 1.0f, 0.0f);
		glRotatef(m_move->rotation->x, 1.0f, 0.0f, 0.0f);
		glRotatef(m_move->rotation->z, 0.0f, 0.0f, 1.0f);
		glScalef(m_scale, m_scale, m_scale);
		glColor3f(m_color.r, m_color.g, m_color.b);
		model->Render();
	glPopMatrix();
}