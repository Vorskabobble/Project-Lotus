#include "TerrainGenerator.h"


TerrainGenerator::TerrainGenerator(void){
}

TerrainGenerator::~TerrainGenerator(void){
}

void TerrainGenerator::createLand(int seed){
	Image image, image2;

	image = renderNoiseGreyScale(2, 1.0f, 1.0f, 1.0f, seed);
	image2 = renderNoiseColor(2, 1.0f, 1.0f, 1.0f, seed);

	WriterBMP writer;
	writer.SetDestFilename("Images/LandGreyScale.bmp");
	writer.SetSourceImage(image);
	writer.WriteDestFile();

	writer.SetDestFilename("Images/LandColor.bmp");
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
	heightMapBuilder.SetDestSize(512, 256);
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
	heightMapBuilder.SetDestSize(512, 256);
	heightMapBuilder.SetBounds(2.0f, 4.0f, 2.0f, 4.0f);
	heightMapBuilder.Build();

	renderer.SetSourceNoiseMap(heightMap);
	renderer.SetDestImage(image);
	renderer.ClearGradient();
	renderer.AddGradientPoint(-1, utils::Color(0, 0, 0, 255)); // sand
	renderer.AddGradientPoint(1, utils::Color(255, 255, 255, 255)); // grass
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