#pragma once
#include "Object.h"
#include "AssimpLoader.h"
#include "DebugPrint.h"

class ObjModel : public Object{
private:
	int numModels;
	MODEL* model;
	float* vertArray;
public:
	ObjModel();
	~ObjModel();

	bool LoadModel(const std::string& pFile);
	void Render();

	void vertPos();
};

