#include "./tests/TestPath.h"
#include "./tests/TestColoring.h"
#include "./tests/TestUtils.h"
#include "./tests/TestNonRepetitiveness.h"
#include "./tests/TestSimplePathGenerator.h"
#include "./tests/TestWholeColoringGenerator.h"
#include "./tests/TestPartialColoringGenerator.h"

TestPath testPath;
TestColoring testColoroing;
TestUtils testUtils;
TestNonRepetitiveness testNonRepetitiveness;
TestSimplePathGenerator testSimplePathGenerator;
TestWholeColoringGenerator testWholeColoringGenerator;
TestPartialColoringGenerator testPartialColoringGenerator;

int main()
{
    testPath.test_all();
    testColoroing.test_all();
    testUtils.test_all();
    testNonRepetitiveness.test_all(10, 200);
    testSimplePathGenerator.test_all();
    testWholeColoringGenerator.test_all();
    testPartialColoringGenerator.test_all();

    cout << "Testing ended" << endl;
    return 0;
}
