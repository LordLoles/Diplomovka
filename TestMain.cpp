#include "./tests/TestPath.h"
#include "./tests/TestColoring.h"
#include "./tests/TestUtils.h"
#include "./tests/TestNonRepetitiveness.h"
#include "./tests/TestSimplePathGenerator.h"
#include "./tests/TestWholeColoringGenerator.h"
#include "./tests/TestPartialColoringGenerator.h"
#include "./tests/TestSimpleWithMemoryPathGenerator.h"
#include "./tests/TestPathRelevanceCheck.h"
#include "./tests/TestByColorPathGenerator.h"
#include "./tests/TestByColorCappedColorsPathGenerator.h"
#include "./tests/TestByColorContinuingPathGenerator.h"

TestPath testPath;
TestColoring testColoroing;
TestUtils testUtils;
TestNonRepetitiveness testNonRepetitiveness;
TestSimplePathGenerator testSimplePathGenerator;
TestWholeColoringGenerator testWholeColoringGenerator;
TestPartialColoringGenerator testPartialColoringGenerator;
TestSimpleWithMemoryPathGenerator testSimpleWithMemoryPathGenerator;
TestPathRelevanceCheck testPathRelevanceCheck;
TestByColorPathGenerator testByColorPathGenerator;
TestByColorCappedColorsPathGenerator testByColorCappedColorsPathGenerator;
TestByColorContinuingPathGenerator testByColorContinuingPathGenerator;

int main()
{
    testPath.test_all();
    testColoroing.test_all();
    testUtils.test_all();
    testNonRepetitiveness.test_all(10, 200);
    testSimplePathGenerator.test_all();
    testWholeColoringGenerator.test_all();
    testPartialColoringGenerator.test_all();
    testSimpleWithMemoryPathGenerator.test_all();
    testPathRelevanceCheck.test_all();
    testByColorPathGenerator.test_all();
    testByColorCappedColorsPathGenerator.test_all();
    testByColorContinuingPathGenerator.test_all();

    cout << "Testing ended" << endl;
    return 0;
}
