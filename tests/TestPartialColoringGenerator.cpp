#include "TestPartialColoringGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include "../prog/ToStringPatch.h"

using namespace std;


void TestPartialColoringGenerator::test_canIncrement()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path());
    if (!gen.canIncrement()) {cout << "empty should be able to increment, result "; gen.lastResult.printColoring();}

    gen = PartialColoringGenerator(Path({{0,1,2}}));
    if (!gen.canIncrement()) {cout << "empty should be able to increment, result "; gen.lastResult.printColoring();}
    gen.initialColoring(); //initialColoring() is tested on other place
    if (!gen.canIncrement()) {cout << "should be able to increment on 0, result "; gen.lastResult.printColoring();}
    gen.increment();
    if (!gen.canIncrement()) {cout << "should be able to increment on 1, result "; gen.lastResult.printColoring();}
    gen.increment();
    if (gen.canIncrement()) {cout << "should not be able to increment on 2, result "; gen.lastResult.printColoring();}
}

void TestPartialColoringGenerator::test_increment()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path());
    try 
    {
        gen.increment();
        cout << "should produce exception (Path()), result ";
        gen.lastResult.printColoring();
    }
    catch(exception e) { }

    gen = PartialColoringGenerator(Path({{2,5,17}}));
    gen.initialColoring(); //initialColoring() is tested on other place
    if (gen.lastResult.at(0) != 2) {cout << "should init-increment to 2, result "; gen.lastResult.printColoring();}
    gen.increment();
    if (gen.lastResult.at(0) != 5) {cout << "should increment to 5, result "; gen.lastResult.printColoring();}
    gen.increment();
    if (gen.lastResult.at(0) != 17) {cout << "should increment to 17, result "; gen.lastResult.printColoring();}
    try 
    {
        gen.increment();
        cout << "should produce exception (Path({{2,5,17}}) on increment, result ";
        gen.lastResult.printColoring();
    }
    catch(exception e) { }
}

void TestPartialColoringGenerator::test_canBeEnlarged()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path());
    if (gen.canBeEnlarged()) cout << "empty path should not be able to be enlarged" << endl;

    
    gen = PartialColoringGenerator(Path({{2,5,17}}));
    if (!gen.canBeEnlarged()) {cout << "Path({{2,5,17}}) should be enlargable";}
    gen.initialColoring();
    if (gen.canBeEnlarged()) {cout << "Path({{2,5,17}}) should not be enlargable now (1) "; gen.lastResult.printColoring();}
    gen.increment();
    if (gen.canBeEnlarged()) {cout << "Path({{2,5,17}}) should not be enlargable now (2) "; gen.lastResult.printColoring();}

    gen = PartialColoringGenerator(Path({{2,5,17}, {5, 0, 6}}));
    gen.initialColoring();
    if (!gen.canBeEnlarged()) {cout << "Path({{2,5,17}, {5, 0, 6}}) should be enlargable now "; gen.lastResult.printColoring();}
    gen.enlarge();
    if (gen.canBeEnlarged()) {cout << "Path({{2,5,17}, {5, 0, 6}}) should not be enlargable now "; gen.lastResult.printColoring();}
}

void TestPartialColoringGenerator::test_enlarge()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path({{1, 16, 9}}));
    gen.initialColoring();
    try 
    {
        gen.enlarge();
        cout << "Enlarging should produce exception (Path({{1, 16, 9}}), result ";
        gen.lastResult.printColoring();
    }
    catch(exception e) { }

    gen = PartialColoringGenerator(Path({{1, 16, 9}, {6, 0, 7}}));
    gen.initialColoring();
    gen.enlarge();
    if (gen.lastResult.at(0) != 1 || gen.lastResult.at(1) != 6) 
        {cout << "Enlarged badly, should be {1, 6}, was "; gen.lastResult.printColoring();}
    if (gen.colorIndeces[0] != 0 || gen.colorIndeces[1] != 0)
        {cout << "Indeces enlarged badly, should be {0, 0}, was {" + to_string((gen.colorIndeces[0])) + ", " + to_string((gen.colorIndeces[1])) + "}" << endl;}

    
    gen = PartialColoringGenerator(Path({{1, 16, 9}, {6, 0, 7}, {6, 0, 7}, {6, 0, 7}, {6, 0, 7}, {6, 0, 7}}));
    gen.initialColoring();
    while(gen.canBeEnlarged()) gen.enlarge();
    if (gen.lastResult.size() != 6) {cout << "Enlarged badly, should be sized 6, but coloring was "; gen.lastResult.printColoring();}
}

void TestPartialColoringGenerator::test_shrink()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path());
    try 
    {
        gen.shrink();
        cout << "shrinking should produce exception (Path({{2,5,17}}), result ";
        gen.lastResult.printColoring();
    }
    catch(exception e) { }

    gen = PartialColoringGenerator(Path({{1, 16, 9}, {6, 0, 7}}));
    gen.initialColoring();
    gen.enlarge();
    gen.shrink();
    if (gen.lastResult.size() != 1 || gen.colorIndeces.size() != 1) {cout << "Shrinked badly, should be sized 1, but coloring was "; gen.lastResult.printColoring();}
    gen.shrink();
    if (!gen.lastResult.empty() || gen.colorIndeces.size() != 0) {cout << "Shrinked badly, should be empty, but coloring was "; gen.lastResult.printColoring();}
}

void TestPartialColoringGenerator::test_shrinkUntilCanIncrement()
{

}


void TestPartialColoringGenerator::test_initialColoring()
{

}

void TestPartialColoringGenerator::test_nextColoring()
{

}

void TestPartialColoringGenerator::test_skipColoring()
{

}

void TestPartialColoringGenerator::test_isFullColoring()
{

}


void TestPartialColoringGenerator::test_all()
{
    cout << "Testing PartialColoringGenerator..." << endl;

    test_canIncrement();
    test_increment();
    test_canBeEnlarged();
    test_enlarge();
    test_shrink();
    test_shrinkUntilCanIncrement();

    test_initialColoring();
    test_nextColoring();
    test_skipColoring();
    test_isFullColoring();

    test_empty_path();
    test_3_sized_path();
    test_1_sized_path();
    test_2_sized_path();
}