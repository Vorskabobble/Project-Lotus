#pragma once
#include <noise.h>
#include "noiseutils.h"
#include "vector.h"
#include <vector>
#include <ctime>

using namespace std;
using namespace noise;
using namespace utils;

enum LAND_TYPE{LAND = 0, LTCOUNT};

class TerrainGenerator{
	int m_curType;
public:
	TerrainGenerator(void);
	~TerrainGenerator(void);

	int getCurrentType();

	void generateMap(int seed, int type);
	void generateMap(int type);
private:
	void createLand(int seed);

	Image renderNoiseGreyScale(int oct, float freq, float pers, float lacun, int seed);
	Image renderNoiseColor(int oct, float freq, float pers, float lacun, int seed);
};

