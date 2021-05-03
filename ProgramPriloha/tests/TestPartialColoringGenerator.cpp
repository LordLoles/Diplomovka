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
    if (!gen.canIncrement()) {cout << "test_canIncrement(): empty should be able to increment, result "; gen.lastResult.printColoring();}

    gen = PartialColoringGenerator(Path({{0,1,2}}));
    if (!gen.canIncrement()) {cout << "test_canIncrement(): empty should be able to increment, result "; gen.lastResult.printColoring();}
    gen.initialColoring(); //initialColoring() is tested on other place
    if (!gen.canIncrement()) {cout << "test_canIncrement(): should be able to increment on 0, result "; gen.lastResult.printColoring();}
    gen.increment();
    if (!gen.canIncrement()) {cout << "test_canIncrement(): should be able to increment on 1, result "; gen.lastResult.printColoring();}
    gen.increment();
    if (gen.canIncrement()) {cout << "test_canIncrement(): should not be able to increment on 2, result "; gen.lastResult.printColoring();}
}

void TestPartialColoringGenerator::test_increment()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path());
    try
    {
        gen.increment();
        cout << "test_increment(): should produce exception (Path()), result ";
        gen.lastResult.printColoring();
    }
    catch(exception e) { }

    gen = PartialColoringGenerator(Path({{2,5,17}}));
    gen.initialColoring(); //initialColoring() is tested on other place
    if (gen.lastResult.at(0) != 2) {cout << "test_increment(): should init-increment to 2, result "; gen.lastResult.printColoring();}
    gen.increment();
    if (gen.lastResult.at(0) != 5) {cout << "test_increment(): should increment to 5, result "; gen.lastResult.printColoring();}
    gen.increment();
    if (gen.lastResult.at(0) != 17) {cout << "test_increment(): should increment to 17, result "; gen.lastResult.printColoring();}
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
    if (gen.canBeEnlarged()) cout << "test_canBeEnlarged(): empty path should not be able to be enlarged" << endl;
    
    gen = PartialColoringGenerator(Path({{2,5,17}}));
    if (!gen.canBeEnlarged()) {cout << "test_canBeEnlarged(): Path({{2,5,17}}) should be enlargable";}
    gen.initialColoring();
    if (gen.canBeEnlarged()) {cout << "test_canBeEnlarged(): Path({{2,5,17}}) should not be enlargable now (1) "; gen.lastResult.printColoring();}
    gen.increment();
    if (gen.canBeEnlarged()) {cout << "test_canBeEnlarged(): Path({{2,5,17}}) should not be enlargable now (2) "; gen.lastResult.printColoring();}

    gen = PartialColoringGenerator(Path({{2,5,17}, {5, 0, 6}}));
    gen.initialColoring();
    if (!gen.canBeEnlarged()) {cout << "test_canBeEnlarged(): Path({{2,5,17}, {5, 0, 6}}) should be enlargable now "; gen.lastResult.printColoring();}
    gen.enlarge();
    if (gen.canBeEnlarged()) {cout << "test_canBeEnlarged(): Path({{2,5,17}, {5, 0, 6}}) should not be enlargable now "; gen.lastResult.printColoring();}
}

void TestPartialColoringGenerator::test_enlarge()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path({{1, 16, 9}}));
    gen.initialColoring();
    try
    {
        gen.enlarge();
        cout << "test_enlarge(): Enlarging should produce exception (Path({{1, 16, 9}}), result ";
        gen.lastResult.printColoring();
    }
    catch(exception e) { }

    gen = PartialColoringGenerator(Path({{1, 16, 9}, {6, 0, 7}}));
    gen.initialColoring();
    gen.enlarge();
    if (gen.lastResult.at(0) != 1 || gen.lastResult.at(1) != 6) 
        {cout << "test_enlarge(): Enlarged badly, should be 16, was "; gen.lastResult.printColoring();}
    if (gen.colorIndeces[0] != 0 || gen.colorIndeces[1] != 0)
        {cout << "test_enlarge(): Indeces enlarged badly, should be 00, was {" + to_string((gen.colorIndeces[0])) + ", " + to_string((gen.colorIndeces[1])) + "}" << endl;}

    
    gen = PartialColoringGenerator(Path({{1, 16, 9}, {6, 0, 7}, {6, 0, 7}, {6, 0, 7}, {6, 0, 7}, {6, 0, 7}}));
    gen.initialColoring();
    while(gen.canBeEnlarged()) gen.enlarge();
    if (gen.lastResult.size() != 6) {cout << "test_enlarge(): Enlarged badly, should be sized 6, but coloring was "; gen.lastResult.printColoring();}
}

void TestPartialColoringGenerator::test_shrink()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path());
    try
    {
        gen.shrink();
        cout << "test_shrink(): Shrinking should produce exception (Path()), result ";
        gen.lastResult.printColoring();
    }
    catch(exception e) { }

    gen = PartialColoringGenerator(Path({{1, 16, 9}, {6, 0, 7}}));
    gen.initialColoring();
    gen.enlarge();
    gen.shrink();
    if (gen.lastResult.size() != 1 || gen.colorIndeces.size() != 1) {cout << "test_shrink(): Shrinked badly, should be sized 1, but coloring was "; gen.lastResult.printColoring();}
    gen.shrink();
    if (!gen.lastResult.empty() || gen.colorIndeces.size() != 0) {cout << "test_shrink(): Shrinked badly, should be empty, but coloring was "; gen.lastResult.printColoring();}
}

void TestPartialColoringGenerator::test_shrinkUntilCanIncrement()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path({{1, 16, 9}, {6, 0, 7}}));
    gen.initialColoring();
    gen.enlarge();
    gen.increment();
    gen.increment();
    gen.shrinkUntilCanIncrement();
    if (gen.lastResult.size() != 1 || gen.lastResult.at(0) != 1) 
        {cout << "test_shrinkUntilCanIncrement(): should be size 1 and have value 1 at index 0, but was "; gen.lastResult.printColoring();}

    gen = PartialColoringGenerator(Path({{0,1,2}, {0,1,2}, {0,1,2}, {0,1,2}, {0,1,2}}));
    gen.initialColoring();
    gen.increment();
    gen.enlarge();
    gen.shrinkUntilCanIncrement();
    if (gen.lastResult.size() != 2 || gen.lastResult.at(0) != 1 || gen.lastResult.at(1) != 0) 
        {cout << "test_shrinkUntilCanIncrement(): coloring should be 10, but was "; gen.lastResult.printColoring();}

    gen.enlarge();
    gen.increment();
    gen.shrinkUntilCanIncrement();
    if (gen.lastResult.size() != 3 || gen.lastResult.at(0) != 1 || gen.lastResult.at(1) != 0 || gen.lastResult.at(2) != 1) 
        {cout << "test_shrinkUntilCanIncrement(): coloring should be 101, but was "; gen.lastResult.printColoring();}

    gen.enlarge();
    gen.increment();
    gen.increment();
    gen.enlarge();
    gen.increment();
    gen.increment();
    gen.shrinkUntilCanIncrement();
    if (gen.lastResult.size() != 3 || gen.lastResult.at(0) != 1 || gen.lastResult.at(1) != 0 || gen.lastResult.at(2) != 1) 
        {cout << "test_shrinkUntilCanIncrement(): coloring should be again 101, but was "; gen.lastResult.printColoring();}
    
}


void TestPartialColoringGenerator::test_initialColoring()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path({{1, 16, 9}, {6, 0, 7}}));
    gen.initialColoring();
    if (gen.lastResult.size() != 1 || gen.lastResult.at(0) != 1)
        {cout << "test_initialColoring(): coloring should be 1, but was "; gen.lastResult.printColoring();}
    if (gen.colorIndeces.size() != 1 || gen.colorIndeces[0] != 0)
        {cout << "test_nextColoring(): color indeces should be 0, but was "<< to_string(gen.colorIndeces[0]) << endl;}
    
    gen = PartialColoringGenerator(Path());
    gen.initialColoring();
    if (!gen.lastResult.empty())
        {cout << "test_initialColoring(): coloring should be empty, but was "; gen.lastResult.printColoring();}
}

void TestPartialColoringGenerator::test_nextColoring()
{
    //examples from function's docu
    PartialColoringGenerator gen = PartialColoringGenerator(Path({{0,1,2}, {0,1,2}, {0,1,2}, {0,1,2}, {0,1,2}}));
    gen.initialColoring();
    gen.enlarge();
    //Coloring 00 -> next should be 000
    gen.nextColoring();
    if (gen.lastResult.size() != 3 || gen.lastResult.at(0) != 0 || gen.lastResult.at(1) != 0 || gen.lastResult.at(2) != 0)
        {cout << "test_nextColoring(): coloring should be 000, but was "; gen.lastResult.printColoring();}
    if (gen.colorIndeces.size() != 3 || gen.colorIndeces[0] != 0 || gen.colorIndeces[1] != 0 || gen.colorIndeces[2] != 0)
        {cout << "test_nextColoring(): color indeces should be 000, but was " << to_string(gen.colorIndeces[0]) << " " << to_string(gen.colorIndeces[1]) 
            << " " << to_string(gen.colorIndeces[2]) << " with size " << to_string(gen.colorIndeces.size()) << endl;}

    gen.shrink();
    gen.shrink();
    gen.increment();
    gen.enlarge();
    gen.enlarge();
    gen.increment();
    gen.enlarge();
    gen.increment();
    gen.increment();
    gen.enlarge();
    //Coloring 10120 -> next should be 10121
    gen.nextColoring();
    if (gen.lastResult.size() != 5 || gen.lastResult.at(0) != 1 || gen.lastResult.at(1) != 0 || gen.lastResult.at(2) != 1 || gen.lastResult.at(3) != 2 || gen.lastResult.at(4) != 1)
        {cout << "test_nextColoring(): coloring should be 10121, but was "; gen.lastResult.printColoring();}
    if (gen.colorIndeces.size() != 5 || gen.colorIndeces[0] != 1 || gen.colorIndeces[1] != 0 || gen.colorIndeces[2] != 1 || gen.colorIndeces[3] != 2 || gen.colorIndeces[4] != 1)
        {cout << "test_nextColoring(): color indeces should be 10121, but was " << to_string(gen.colorIndeces[0]) << " " 
            << to_string(gen.colorIndeces[1]) << " " << to_string(gen.colorIndeces[2]) << " " << to_string(gen.colorIndeces[3]) << " " 
            << to_string(gen.colorIndeces[4]) << " with size " << to_string(gen.colorIndeces.size()) << endl;}
    
    gen.increment();
    //Coloring 10122 -> next should be 102
    gen.nextColoring();
    if (gen.lastResult.size() != 3 || gen.lastResult.at(0) != 1 || gen.lastResult.at(1) != 0 || gen.lastResult.at(2) != 2)
        {cout << "test_nextColoring(): coloring should be 102, but was "; gen.lastResult.printColoring();}
    if (gen.colorIndeces.size() != 3 || gen.colorIndeces[0] != 1 || gen.colorIndeces[1] != 0 || gen.colorIndeces[2] != 2)
        {cout << "test_nextColoring(): color indeces should be 102, but was "<< to_string(gen.colorIndeces[0]) << " " << to_string(gen.colorIndeces[1]) 
            << " " << to_string(gen.colorIndeces[2]) << " with size " << to_string(gen.colorIndeces.size()) << endl;}
}

void TestPartialColoringGenerator::test_skipColoring()
{
    //examples from function's docu
    PartialColoringGenerator gen = PartialColoringGenerator(Path({{0,1,2}, {0,1,2}, {0,1,2}, {0,1,2}, {0,1,2}}));
    gen.initialColoring();
    gen.enlarge();
    //Coloring 00 -> should skip to 01
    gen.skipColoring();
    if (gen.lastResult.size() != 2 || gen.lastResult.at(0) != 0 || gen.lastResult.at(1) != 1)
        {cout << "test_skipColoring(): coloring should be 01, but was "; gen.lastResult.printColoring();}
    if (gen.colorIndeces.size() != 2 || gen.colorIndeces[0] != 0 || gen.colorIndeces[1] != 1)
        {cout << "test_skipColoring(): color indeces should be 01, but was "<< to_string(gen.colorIndeces[0]) << " " << to_string(gen.colorIndeces[1]) 
            << " with size " << to_string(gen.colorIndeces.size()) << endl;}
        
    gen.shrink();
    gen.increment();
    gen.enlarge();
    gen.enlarge();
    gen.increment();
    gen.increment();
    //Coloring 102 -> should skip to 11
    gen.skipColoring();
    if (gen.lastResult.size() != 2 || gen.lastResult.at(0) != 1 || gen.lastResult.at(1) != 1)
        {cout << "test_skipColoring(): coloring should be 11, but was "; gen.lastResult.printColoring();}
    if (gen.colorIndeces.size() != 2 || gen.colorIndeces[0] != 1 || gen.colorIndeces[1] != 1)
        {cout << "test_skipColoring(): color indeces should be 11, but was "<< to_string(gen.colorIndeces[0]) << " " << to_string(gen.colorIndeces[1]) 
            << " with size " << to_string(gen.colorIndeces.size()) << endl;}

    gen.shrink();
    gen.enlarge();
    gen.enlarge();
    gen.increment();
    gen.enlarge();
    gen.increment();
    gen.increment();
    gen.enlarge();
    gen.increment();
    gen.increment();
    //Coloring 10122 -> should skip to 102
    gen.skipColoring();
    if (gen.lastResult.size() != 3 || gen.lastResult.at(0) != 1 || gen.lastResult.at(1) != 0 || gen.lastResult.at(2) != 2)
        {cout << "test_skipColoring(): coloring should be 102, but was "; gen.lastResult.printColoring();}
    if (gen.colorIndeces.size() != 3 || gen.colorIndeces[0] != 1 || gen.colorIndeces[1] != 0 || gen.colorIndeces[2] != 2)
        {cout << "test_skipColoring(): color indeces should be 102, but was "<< to_string(gen.colorIndeces[0]) << " " << to_string(gen.colorIndeces[1]) 
            << " " << to_string(gen.colorIndeces[2]) << " with size " << to_string(gen.colorIndeces.size()) << endl;}
}

void TestPartialColoringGenerator::test_isFullColoring()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path());
    gen.initialColoring();
    if (!gen.isFullColoring())
        {cout << "test_isFullColoring(): coloring should be full, but was "; gen.lastResult.printColoring();}
        
    gen = PartialColoringGenerator(Path({{1, 16, 9}, {6, 0, 7}}));
    gen.initialColoring();
    if (gen.isFullColoring())
        {cout << "test_isFullColoring(): coloring should not be full, but was "; gen.lastResult.printColoring();}

    gen.enlarge();
    if (!gen.isFullColoring())
        {cout << "test_isFullColoring(): coloring should be full, but was "; gen.lastResult.printColoring();}

    gen.shrink();
    if (gen.isFullColoring())
        {cout << "test_isFullColoring(): again, coloring should not be full, but was "; gen.lastResult.printColoring();}
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
}
