#include "TestPath.h"
#include "TestPath.cpp"
#include "TestColoring.h"
#include "TestColoring.cpp"
#include "TestUtils.h"
#include "TestUtils.cpp"
#include "TestNonRepetitiveness.h"
#include "TestNonRepetitiveness.cpp"
#include "TestPathGenerator.h"
#include "TestPathGenerator.cpp"
#include "TestColoringGenerator.h"
#include "TestColoringGenerator.cpp"

TestPath testPath;
TestColoring testColoroing;
TestUtils testUtils;
TestNonRepetitiveness testNonRepetitiveness;
TestPathGenerator testNextPathGenerator;
TestColoringGenerator testColoringGenerator;

int main()
{
    testPath.test_all();
    testColoroing.test_all();
    testUtils.test_all();
    testNonRepetitiveness.test_all(10, 200);
    testNextPathGenerator.test_all();
    testColoringGenerator.test_all();

    cout << "Testing ended" << endl;
    return 0;
}
