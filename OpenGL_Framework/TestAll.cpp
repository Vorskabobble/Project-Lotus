#include "TestAll.h"

TestAll::TestAll(){
}

TestAll::~TestAll(){
}

int TestAll::runAllTests(){
	std::time_t t;
	time(&t);

	char str[255];
	sprintf(str, "Tests/Test-%i.xml", t);
	std::ofstream file(str);
	UnitTest::XmlTestReporter reporter(file);
	UnitTest::TestRunner runner(reporter);

	return runner.RunTestsIf(UnitTest::Test::GetTestList(), NULL, UnitTest::True(), 0);
}