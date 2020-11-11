#include "TestPath.h"
#include "TestPath.cpp"
#include "TestColoring.h"
#include "TestColoring.cpp"

TestPath testPath;
TestColoring testColoroing;

int main()
{
    testPath.test_all();
    testColoroing.test_all();
    return 0;
}