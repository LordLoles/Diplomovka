#include "TestPathRelevanceCheck.h"
#include <iostream>
#include <tuple>
#include <iterator>
#include "../prog/Path.h"

using namespace std;

void TestPathRelevanceCheck::print(std::set<int> const &s)
{
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
}

vector<set<int>> TestPathRelevanceCheck::getColorsUsage(Path path, int colorsInPath)
{
    vector<set<int>> colorsUsage = vector<set<int>>(colorsInPath);

    for (int i = 0; i < path.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int color = path.at(i).at(j);
            colorsUsage[color].insert(i);
        }
    }

    return colorsUsage;
}

void TestPathRelevanceCheck::test_getColorsUsage()
{
    Path path = Path({{0,1,2}, {0,1,2}});
    vector<set<int>> colorsUsage = getColorsUsage(path, 5);
    if(colorsUsage.at(0) != colorsUsage.at(1) ||
        colorsUsage.at(0) != colorsUsage.at(2) ||
        colorsUsage.at(0) != set<int>{0,1})
        {cout << "test_getColorsUsage(): expected all sets {0,1}, but get "; print(colorsUsage.at(0)); print(colorsUsage.at(1)); print(colorsUsage.at(2)); cout << endl;}

    path = Path({{0,1,5}, {0,1,5}});
    colorsUsage = getColorsUsage(path, 7);
    if(colorsUsage.at(0) != colorsUsage.at(1) ||
        colorsUsage.at(0) != colorsUsage.at(5) ||
        colorsUsage.at(0) != set<int>{0,1} ||
        colorsUsage.at(2) != colorsUsage.at(3) ||
        colorsUsage.at(2) != colorsUsage.at(4) ||
        colorsUsage.at(2) != colorsUsage.at(6) ||
        colorsUsage.at(2) != set<int>{})
        {cout << "test_getColorsUsage(): expected all sets {0,1} or empty, but get "; 
        print(colorsUsage.at(0)); print(colorsUsage.at(1)); print(colorsUsage.at(2)); print(colorsUsage.at(3)); 
        print(colorsUsage.at(4)); print(colorsUsage.at(5)); print(colorsUsage.at(6)); cout << endl;}
}

void TestPathRelevanceCheck::test_hasDisjunctColor()
{
    Path path = Path({{0,1,2}, {0,1,2}});
    if (hasDisjunctColor(path, getColorsUsage(path, 3)))
        cout << "test_hasDisjunctColor() 1: should not have disjunct colors" << endl;

    path = Path({{0,1,2}, {0,3,4}, {1,3,4}, {2,3,4}});
    if (hasDisjunctColor(path, getColorsUsage(path, 5)))
        cout << "test_hasDisjunctColor() 2: should not have disjunct colors" << endl;

    path = Path({{0,1,2}, {0,1,3}, {2,4,5}, {3,4,5}, {0,1,4}, {0,1,5}, {2,3,4}});
    if (hasDisjunctColor(path, getColorsUsage(path, 6)))
        cout << "test_hasDisjunctColor() 3: should not have disjunct colors" << endl;

    path = Path({{0,1,5}, {0,1,5}});
    if (hasDisjunctColor(path, getColorsUsage(path, 7)))
        cout << "test_hasDisjunctColor() 4: should not have disjunct colors" << endl;

    path = Path({{0,1,2}, {0,1,3}});
    if (!hasDisjunctColor(path, getColorsUsage(path, 4))) //2nd heuristic should return us with true
        cout << "test_hasDisjunctColor() 5: should have disjunct colors" << endl;

    path = Path({{0,1,2}, {2,3,4}, {1,4,5}});
    if (!hasDisjunctColor(path, getColorsUsage(path, 6))) //1st heuristic should return us with true
        cout << "test_hasDisjunctColor() 6: should have disjunct colors" << endl;

    path = Path({{0,1,2}, {0,1,2}, {0,1,3}, {1,2,4}, {0,2,3}});
    if (!hasDisjunctColor(path, getColorsUsage(path, 5))) //2nd heuristic should return us with true
        cout << "test_hasDisjunctColor() 7: should have disjunct colors" << endl;

    path = Path({{0,1,2}, {0,1,3}, {2,4,5}, {3,4,5}, {0,1,4}, {0,1,5}});
    if (!hasDisjunctColor(path, getColorsUsage(path, 6))) //2nd heuristic should return us with true
        cout << "test_hasDisjunctColor() 8: should have disjunct colors" << endl;

    path = Path({{0,1,2}, {0,1,3}, {0,1,2}, {0,1,3}});
    if (!hasDisjunctColor(path, getColorsUsage(path, 4)))
        cout << "test_hasDisjunctColor() 5: should have disjunct colors" << endl;
}

void TestPathRelevanceCheck::test_isFirstLexicographically()
{
    Path path = Path({{0,1,2}, {0,1,3}});
    if (!isFirstLexicographically(path, 4))
        {cout << "test_isFirstLexicographically(): should be lex. first - "; path.printPath();}

    path = Path({{0,1,2}, {0,1,3}, {2,4,5}});
    if (!isFirstLexicographically(path, 6))
        {cout << "test_isFirstLexicographically(): should be lex. first - "; path.printPath();}

    path = Path({{0,1,2}, {0,1,3}, {2,3,4}});
    if (!isFirstLexicographically(path, 5))
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

    test_getColorsUsage();
    test_hasDisjunctColor();
    test_isFirstLexicographically();

}