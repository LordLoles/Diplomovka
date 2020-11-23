#include "TestPath.h"
#include "TestPath.cpp"
#include "TestColoring.h"
#include "TestColoring.cpp"
#include "TestUtils.h"
#include "TestUtils.cpp"
#include "TestNonRepetitiveness.h"
#include "TestNonRepetitiveness.cpp"

TestPath testPath;
TestColoring testColoroing;
TestUtils testUtils;
TestNonRepetitiveness testNonRepetitiveness;

int main()
{
    testPath.test_all();
    testColoroing.test_all();
    testUtils.test_all(10);
    testNonRepetitiveness.test_all(10, 200, 10);

    cout << "Testing ended" << endl;
    return 0;
}
