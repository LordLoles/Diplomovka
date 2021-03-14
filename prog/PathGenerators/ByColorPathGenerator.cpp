#include "ByColorPathGenerator.h"
#include "PathRelevanceCheck.h"
#include <iostream>
#include "PathRelevanceCheck.h"

using namespace std;


ByColorPathGenerator::ByColorPathGenerator(int lengthOfPath, int colorsInPath) 
    : allColors(getSetToLength(colorsInPath))
    , length(lengthOfPath)
    , fullVertecesCount(0)
    , colorsDisjunct(true)
{
    if (colorsInPath < 3) throw "At least 3 colors are required.";

    colorsUsage = vector<set<int>>(colorsInPath);
    for (int i = 0; i < colorsInPath; i++)
    {
        colorsUsage[i] = set<int>();
    }

    vector<array<int, 3>> emptyPath;
    for (int i = 0; i < lengthOfPath; i++)
    {
        emptyPath.push_back({-1, -1, -1});
    }
    lastResult = Path(emptyPath);
}


/*
* returns true, whether the vertex at given position is filled with 3 colors.
* O(1)
*/
bool ByColorPathGenerator::isFullVertex(int vertex)
{
    return (lastResult.at(vertex).at(0) != -1 &&
            lastResult.at(vertex).at(1) != -1 &&
            lastResult.at(vertex).at(2) != -1);
}

/*
* returns true, whether every vertex of 'lastResult' is filled with 3 colors.
* relys on updated 'fullVertecesCount'
* O(1)
*/
bool ByColorPathGenerator::isFullPath()
{
    return fullVertecesCount == length;
}

/*
* Sets 'lastResult' to corresponding path, that is next in order and is relevant.
* Resulting path doesn't need to have all slots occupied by color (not full).
*/
void ByColorPathGenerator::nextNotFullRelevantPath()
{

    //if ('colorsdisjunct') and we're adding color, then check, if its value hasn't changed.
    //if (!'colorsdisjunct') and we're deleting color, then check, if it hasn't become true.
    //if we're adding new color (that hasn't been used yet), 'colorsdisjunct' should be (in most cases) true.
    
}

/*
* while path is not full, performs 'nextNotFullRelevantPath()'
*/
void ByColorPathGenerator::nextFullRelevantPath()
{
    while (!isFullPath())
    {
        nextNotFullRelevantPath();
    }
}


/*
* Initialize this path generator
* Returns the first path.
*/
Path ByColorPathGenerator::initialPath() //const nejde, lebo nepojde "colorsUsage[i] = set..."
{

    return lastResult; //Initial path is relevant and doesn't need a check
}

Path ByColorPathGenerator::nextPath() //const nejde, lebo nepojde "colorsUsage[i] = set"
{

    return lastResult;
}
