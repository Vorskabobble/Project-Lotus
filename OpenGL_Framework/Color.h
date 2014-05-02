#pragma once

struct Colour{
	float r;
	float g;
	float b;
	float a;
};

#define COLOUR_WHITE	 Colour{1.0f, 1.0f, 1.0f, 1.0f}
#define COLOUR_GRAY		 Colour{0.5f, 0.5f, 0.5f, 1.0f}
#define COLOUR_BLACK	 Colour{0.0f, 0.0f, 0.0f, 1.0f}
#define COLOUR_RED		 Colour{1.0f, 0.0f, 0.0f, 1.0f}
#define COLOUR_GREEN	 Colour{0.0f, 1.0f, 0.0f, 1.0f}
#define COLOUR_BLUE		 Colour{0.0f, 0.0f, 1.0f, 1.0f}
#define COLOUR_YELLOW	 Colour{1.0f, 1.0f, 0.0f, 1.0f}
#define COLOUR_ORANGE	 Colour{1.0f, 0.5f, 0.0f, 1.0f}
#define COLOUR_PINK		 Colour{1.0f, 0.0f, 1.0f, 1.0f}
#define COLOUR_PURPLE	 Colour{0.5f, 0.0f, 1.0f, 1.0f}
#define COLOUR_CYAN		 Colour{0.0f, 1.0f, 1.0f, 1.0f}
#define COLOUR_LIME		 Colour{0.0f, 1.0f, 0,5f, 1.0f}
