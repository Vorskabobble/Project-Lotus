#include "Cuboid.h"


Cuboid::Cuboid(float w, float h, float l){
	setDimensions(w, h, l);
	m_dir = m_pos = Vector(0.0f, 0.0f, 0.0f);
	m_color =  Vector(1.0f, 1.0f, 1.0f);
	m_angle = 0;
	texture = 0;
	m_alpha = 1;
}

Cuboid::Cuboid(char* image, float w, float h, float l){
	setDimensions(w, h, l);
	m_dir = m_pos = Vector(0.0f, 0.0f, 0.0f);
	m_color =  Vector(1.0f, 1.0f, 1.0f);
	m_angle = 0;
	m_alpha = 1;
	setTexture(image);
}

Cuboid::~Cuboid(void){
}

void Cuboid::setColor(Vector color){
	m_color = color;
}

void Cuboid::setPos(Vector pos){
	m_pos = pos;
}

void Cuboid::setAlpha(float alpha){
	m_alpha = alpha;
}

void Cuboid::render(){
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, verts);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);

	glPushMatrix();
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glRotatef(m_angle, m_dir.x, m_dir.y, m_dir.z);
	glTranslatef(m_pos.x, m_pos.y, m_pos.z);
	glColor4f(m_color.x, m_color.y, m_color.z, m_alpha);

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, indices);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Cuboid::setDimensions(float w, float h, float l){
	m_width = w; m_height = h; m_length = l;

	verts[0] = -w; verts[1] = h; verts[2] = l;
	verts[3] = w; verts[4] = h; verts[5] = l;
	verts[6] = w; verts[7] = h; verts[8] = -l;
	verts[9] = -w; verts[10] = h; verts[11] = -l;
	verts[12] = -w; verts[13] = -h; verts[14] = l;
	verts[15] = w; verts[16] = -h; verts[17] = l;
	verts[18] = w; verts[19] = -h; verts[20] = -l;
	verts[21] = -w; verts[22] = -h; verts[23] = -l;

	float tl, tw, th;

	tl = l;
	tw = w;
	th = h;

	if (tl < 0){
		tl -= tl;
	}
	if (tw < 0){
		tw -= tw;
	}
	if (th < 0){
		th = -th;
	}

	//Top Face
	texCoords[0] = 0.0f; texCoords[1] = 0.0f;
	texCoords[2] = 1.0f; texCoords[3] = 0.0f;
	texCoords[4] = 1.0f; texCoords[5] = 1.0f;
	texCoords[6] = 0.0f; texCoords[7] = 1.0f;

	//Bottom Face
	/*texCoords[8] = 0.5f; texCoords[9] = 0.25f;
	texCoords[10] = 1.0f; texCoords[11] = 0.25f;
	texCoords[12] = 1.0f; texCoords[13] = 0.5f;
	texCoords[14] = 0.5f; texCoords[15] = 0.5f;

	texCoords[16] = 0.5f; texCoords[17] = 0.75f;
	texCoords[18] = 0.25f; texCoords[19] = 0.75f;
	texCoords[20] = 0.25f; texCoords[21] = 0.5f;
	texCoords[22] = 0.0f; texCoords[23] = 0.5f;*/

	/*texCoords[24] = 0.0f; texCoords[25] = 0.0f;
	texCoords[26] = tw; texCoords[37] = 0.0f;
	texCoords[28] = tw; texCoords[29] = th;
	texCoords[30] = 0.0f; texCoords[31] = th;

	texCoords[32] = 0.0f; texCoords[33] = 0.0f;
	texCoords[34] = tw; texCoords[35] = 0.0f;
	texCoords[36] = tw; texCoords[37] = th;
	texCoords[38] = 0.0f; texCoords[39] = th;

	texCoords[40] = 0.0f; texCoords[41] = 0.0f;
	texCoords[42] = tw; texCoords[43] = 0.0f;
	texCoords[44] = tw; texCoords[45] = th;
	texCoords[46] = 0.0f; texCoords[47] = th;*/

	indices[0] = 0; indices[1] = 4; indices[2] = 5;
	indices[3] = 1; indices[4] = 3; indices[5] = 7;
	indices[6] = 4; indices[7] = 0; indices[8] = 2;
	indices[9] = 6; indices[10] = 7; indices[11] = 3;
	indices[12] = 1; indices[13] = 5; indices[14] = 6;
	indices[15] = 2; indices[16] = 3; indices[17] = 0;
	indices[18] = 1; indices[19] = 2; indices[20] = 4;
	indices[21] = 7; indices[22] = 6; indices[23] = 5;
}

void Cuboid::setTexture(char* image){
	LoadTextures *lt = new LoadTextures(image);  //for texture
	texture = lt->getTexture();
	delete lt;
}

//void Cuboid::update(hkpRigidBody* rb){
//	if(rb){
//		setPos(Vector(rb->getPosition().getComponent(0), rb->getPosition().getComponent(1), rb->getPosition().getComponent(2)));
//		hkQuaternion quaternion = rb->getRotation();	//get orientation as a quaternion
//		if(quaternion.hasValidAxis()){
//			m_angle = quaternion.getAngle() * 180.0f / HK_REAL_PI;	//convert to degrees for OpenGL rotation
//			hkVector4 axis;
//			quaternion.getAxis(axis);
//			m_dir = (Vector(axis.getSimdAt(0), axis.getSimdAt(1), axis.getSimdAt(2)));
//		}
//	}
//}

bool Cuboid::checkCollision(Vector pos){
	Vector min, max;

	min.x = m_pos.x - m_width;
	min.y = m_pos.y - m_height;
	min.z = m_pos.z - m_length;

	max.x = m_pos.x + m_width;
	max.y = m_pos.y + m_height;
	max.z = m_pos.z + m_length;

	if(pos.x < max.x && pos.x > min.x){
		if(pos.y < max.y && pos.y > min.y){
			if(pos.z < max.z && pos.z > min.z){
				return true;
			}
		}
	}

	return false;
}