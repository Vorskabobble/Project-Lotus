#include "TerrainGenerator.h"


TerrainGenerator::TerrainGenerator(void){
}

TerrainGenerator::~TerrainGenerator(void){
}

void TerrainGenerator::createLand(int seed){
	Image image, image2;

	image = renderNoiseGreyScale(1, 2.0f, 1.0f, 2.0f, seed);
	image2 = renderNoiseColor(1, 2.0f, 1.0f, 2.0f, seed);

	WriterBMP writer;
	writer.SetDestFilename("Images/TerrainHeight.bmp");
	writer.SetSourceImage(image);
	writer.WriteDestFile();

	writer.SetDestFilename("Images/TerrainTex.bmp");
	writer.SetSourceImage(image2);
	writer.WriteDestFile();
}

Image TerrainGenerator::renderNoiseGreyScale(int oct, float freq, float pers, float lacun, int seed){
	module::Perlin myModule;
	NoiseMap heightMap;
	NoiseMapBuilderPlane heightMapBuilder;
	RendererImage renderer;
	Image image;

	myModule.SetOctaveCount(oct);
	myModule.SetFrequency(freq);
	myModule.SetPersistence(pers);
	myModule.SetLacunarity(lacun);
	myModule.SetSeed(seed);

	heightMapBuilder.SetSourceModule(myModule);
	heightMapBuilder.SetDestNoiseMap(heightMap);
	heightMapBuilder.SetDestSize(256, 256);
	heightMapBuilder.SetBounds(2.0f, 4.0f, 2.0f, 4.0f);
	heightMapBuilder.Build();

	renderer.SetSourceNoiseMap(heightMap);
	renderer.SetDestImage(image);
	renderer.ClearGradient();
	renderer.AddGradientPoint(-1, utils::Color(0, 0, 0, 255));
	renderer.AddGradientPoint(1, utils::Color(255, 255, 255, 255));
	renderer.Render();

	return image;
}

Image TerrainGenerator::renderNoiseColor(int oct, float freq, float pers, float lacun, int seed){
	module::Perlin myModule;
	NoiseMap heightMap;
	NoiseMapBuilderPlane heightMapBuilder;
	RendererImage renderer;
	Image image;

	myModule.SetOctaveCount(oct);
	myModule.SetFrequency(freq);
	myModule.SetPersistence(pers);
	myModule.SetLacunarity(lacun);
	myModule.SetSeed(seed);

	heightMapBuilder.SetSourceModule(myModule);
	heightMapBuilder.SetDestNoiseMap(heightMap);
	heightMapBuilder.SetDestSize(256, 256);
	heightMapBuilder.SetBounds(2.0f, 4.0f, 2.0f, 4.0f);
	heightMapBuilder.Build();

	renderer.SetSourceNoiseMap(heightMap);
	renderer.SetDestImage(image);
	renderer.ClearGradient();
	renderer.AddGradientPoint(-1.0000, utils::Color(144, 95, 0, 255)); // shallow
	renderer.AddGradientPoint(-0.7000, utils::Color(118, 157, 0, 255)); // shore
	renderer.AddGradientPoint(0.22500, utils::Color(82, 143, 28, 255)); // sand
	renderer.AddGradientPoint(0.37500, utils::Color(87, 148, 0, 255)); // dirt
	renderer.AddGradientPoint(0.75000, utils::Color(128, 128, 128, 255)); // rock
	renderer.AddGradientPoint(1.00000, utils::Color(255, 255, 255, 255)); // snow
	renderer.Render();

	return image;
}

int TerrainGenerator::getCurrentType(){
	return m_curType;
}

void TerrainGenerator::generateMap(int seed, int type){
	if (type < 0 || type > LTCOUNT){
		return;
	}

	switch (type){
	case LAND:
		createLand(seed);
		break;
	default:
		createLand(seed);
		break;
	}

	m_curType = type;
}

void TerrainGenerator::generateMap(int type){
	srand(time(NULL));
	generateMap(rand() % 1000000, type);
}