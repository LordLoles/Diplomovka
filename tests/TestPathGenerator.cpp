#include "TestPathGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;


void TestPathGenerator::test_2_colors()
{
    try
    {
        PathGenerator pathGen = PathGenerator(2, 2);
        pathGen.nextPath();
        cout << "test_2_colors should have generated an exception!" << endl;
    }
    catch(const std::exception& e)
    {
        cout << "test_2_colors should have generated char const* exception!" << endl;
    }
    catch(char const* c)
    { }
}

void TestPathGenerator::test_3_colors()
{
    PathGenerator pathGen = PathGenerator(5, 3);
    Path path;

    path = pathGen.nextPath();
    if (path.empty()) {cout << "test_3_colors: path should not be empty "; path.printPath();}

    path = pathGen.nextPath();
    if (!path.empty()) {cout << "test_3_colors: path should be empty "; path.printPath();}
    path = pathGen.nextPath();
    if (!path.empty()) {cout << "test_3_colors: path should be empty "; path.printPath();}
}

void TestPathGenerator::test_4_colors()
{
    PathGenerator pathGen = PathGenerator(1, 4);
    Path path;

    path = pathGen.nextPath();
    if (path.empty()) {cout << "test_4_colors: path should not be empty "; path.printPath();}
    path = pathGen.nextPath();
    if (path.empty()) {cout << "test_4_colors: path should not be empty "; path.printPath();}
    path = pathGen.nextPath();
    if (path.empty()) {cout << "test_4_colors: path should not be empty "; path.printPath();}
    path = pathGen.nextPath();
    if (path.empty()) {cout << "test_4_colors: path should not be empty "; path.printPath();}

    path = pathGen.nextPath();
    if (!path.empty()) {cout << "test_4_colors: path should be empty "; path.printPath();}
    path = pathGen.nextPath();
    if (!path.empty()) {cout << "test_4_colors: path should be empty "; path.printPath();}
}

void TestPathGenerator::test_all()
{
    cout << "Testing PathGenerator..." << endl;
    test_2_colors();
    test_3_colors();
    test_4_colors();
}
