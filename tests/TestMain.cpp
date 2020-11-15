#include "TestPath.h"
#include "TestPath.cpp"
#include "TestColoring.h"
#include "TestColoring.cpp"
#include "TestUtils.h"
#include "TestUtils.cpp"

TestPath testPath;
TestColoring testColoroing;
TestUtils testUtils;

int main()
{
    testPath.test_all();
    testColoroing.test_all();
    testUtils.test_all(10);

    cout << "Testing ended" << endl;
    return 0;
}
