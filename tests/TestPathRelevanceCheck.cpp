#include "TestPathRelevanceCheck.h"
#include <iostream>
#include <vector>
#include <tuple>
#include "../prog/Path.h"

using namespace std;

void TestPathRelevanceCheck::test_hasDisjunctColor()
{
    vector<set<int>> colorsUsage =  {{0,1,2}, {0,1,2}}; //at position 'i' (in vector) are verteces for color 'i' (in set)
    if (hasDisjunctColor(colorsUsage))
        cout << "test_hasDisjunctColor() 1: should not have disjunct colors" << endl;

    colorsUsage = {{0,1,2}, {2,3,4}};
    if (hasDisjunctColor(colorsUsage))
        cout << "test_hasDisjunctColor() 2: should not have disjunct colors" << endl;

    colorsUsage = {{0,2}, {0,3}, {1,4,3}};
    if (!hasDisjunctColor(colorsUsage))
        cout << "test_hasDisjunctColor() 3: should not have disjunct colors" << endl;

    colorsUsage = {{0,1,2}, {3,4}};
    if (!hasDisjunctColor(colorsUsage))
        cout << "test_hasDisjunctColor() 4: should have disjunct colors" << endl;

    colorsUsage = {{0,2}, {0,4}, {1,3,4}};
    if (!hasDisjunctColor(colorsUsage))
        cout << "test_hasDisjunctColor() 4: should have disjunct colors" << endl;
}

void TestPathRelevanceCheck::test_isFirstLexicographically()
{
    Path path = Path({{0,1,2}, {0,1,3}});
    if (!isFirstLexicographically(path, 4))
        {cout << "test_isFirstLexicographically(): should be lex. first - "; path.printPath();}

    path = Path({{0,1,2}, {0,1,3}, {2,4,5}});
    if (!isFirstLexicographically(path, 6))
        {cout << "test_isFirstLexicographically(): should be lex. first - "; path.printPath();}

    path = Path({{0,2,3}, {0,1,2}});
    if (isFirstLexicographically(path, 4))
        {cout << "test_isFirstLexicographically(): [0,1,2] [0,3,1] is equivalent and lex. sooner than path "; path.printPath();}

    path = Path({{0,1,2}, {0,1,3}, {2,5,4}});
    if (isFirstLexicographically(path, 6))
        {cout << "test_isFirstLexicographically(): [0,1,2] [0,1,3] [2,4,5] is equivalent and lex. sooner than path "; path.printPath();}
}

void TestPathRelevanceCheck::test_all()
{
    cout << "Testing PathRelevanceCheck..." << endl;

    test_hasDisjunctColor();
    test_isFirstLexicographically();

}