#include "ObjModel.h"

ObjModel::ObjModel(){
	m_color = COLOR_WHITE;
	m_scale = 1.0f;
	m_move = new Move();
}

ObjModel::~ObjModel(){
	delete model;
}

bool ObjModel::LoadModel(const std::string& pFile){
	AssimpLoader loader;
	if (loader.loadScene(pFile)){
		
		model = new MODEL;
		*model = *loader.getModel();
		vertArray = new float[model->numVerts*3];
		int num = 0;
		for (int i = 0; i < model->numVerts; i++){
			vertArray[num] = model->vertices[i].x;
			vertArray[num+1] = model->vertices[i].y;
			vertArray[num+2] = model->vertices[i].z;
			num += 3;

			char s[255];
			sprintf(s, "V1: %2.3f, V2 %2.3f, V3 %2.3f", model->vertices[i].x, model->vertices[i].y, model->vertices[i].z);
			DebugOut(s);
		}
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
		for (int i = 0; i < model->numTris; i++){
			glBegin(GL_TRIANGLES);
				glVertex3f(model->vertices[model->triangles[i].vertIndices[0]].x, model->vertices[model->triangles[i].vertIndices[0]].y, model->vertices[model->triangles[i].vertIndices[0]].z);
				glVertex3f(model->vertices[model->triangles[i].vertIndices[1]].x, model->vertices[model->triangles[i].vertIndices[1]].y, model->vertices[model->triangles[i].vertIndices[1]].z);
				glVertex3f(model->vertices[model->triangles[i].vertIndices[2]].x, model->vertices[model->triangles[i].vertIndices[2]].y, model->vertices[model->triangles[i].vertIndices[2]].z);
			glEnd();
		}
		//glEnable(GL_VERTEX_ARRAY);
		//	glVertexPointer(3, GL_FLOAT, 0, vertArray);
		//	glDrawArrays(GL_TRIANGLES, 0, model->numVerts);
		//glDisable(GL_VERTEX_ARRAY);
	glPopMatrix();
}

void ObjModel::vertPos(){
	int curNum = 0, num = 0;
	for (int i = 0; i < model->numVerts; i++){
		curNum++;
		char s[255];
		sprintf(s, "V1: %2.3f, V2 %2.3f, V3 %2.3f - CurNum: %i - Verts: %i", vertArray[num], vertArray[num + 1], vertArray[num + 2], curNum);
		DebugOut(s);

		num += 3;
	}
}