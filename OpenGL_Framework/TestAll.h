#pragma once

#include <fstream>
#include <ctime>

#include "UnitTest++.h"
#include "XmlTestReporter.h"

class TestAll{
public:
	TestAll();
	~TestAll();

	int runAllTests();
};

