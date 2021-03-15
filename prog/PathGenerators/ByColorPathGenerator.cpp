#include "ByColorPathGenerator.h"
#include "PathRelevanceCheck.h"
#include <iostream>
#include "PathRelevanceCheck.h"

using namespace std;


ByColorPathGenerator::ByColorPathGenerator(int lengthOfPath, int colorsInPath) 
    : allColors(getSetToLength(colorsInPath))
    , length(lengthOfPath)
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
* Returns false, if the given 'color' is on vertex with every other color (with number lesser to 'color').
* Returns true otherwise.
* O(n + k)
*/
bool ByColorPathGenerator::isColorDisjunct(int color)
{
    vector<bool> seen = vector<bool>(color - 1);
    int colorsSeen = 0;
    set<int> vertecesToCheck = colorsUsage.at(color);
    for (int i : vertecesToCheck)
    {
        for (int j = 0; j < 3; j++)
        {
            int colorNow = lastResult.at(i).at(j);
            if (colorNow != -1 && colorNow != color && !seen.at(colorNow))
            {
                seen.at(colorNow) = true;
                colorsSeen++;
            }
        }
    }

    return colorsSeen != (color - 1);
}

/*
* Returns the count of colors in this path
*/
int ByColorPathGenerator::colorsInPath()
{
    return allColors.size();
}

/*
* Returns the position (from 0 to 2) of the color 'color' on vertex 'vertex'.
* Returns -1, if the color is not present on vertex.
* O(1)
*/
int ByColorPathGenerator::colorAtPos(int vertex, int color)
{
    array<int, 3> list = lastResult.at(vertex);
    return (list.at(0) == color ? 0 : (list.at(1) == color ? 1 : (list.at(2) == color ? 2 : -1)));
}

/*
* Returns the index (from 0 to 2) of the first position on given 'vertex' that has no color assigned.
* Returns -1 if the vertex is full.
* O(1)
*/
int ByColorPathGenerator::freePosInVertex(int vertex)
{
    array<int, 3> list = lastResult.at(vertex);
    return (list.at(0) == -1 ? 0 : (list.at(1) == -1 ? 1 : (list.at(2) == -1 ? 2 : -1)));
}

/*
* returns true, whether the vertex at given position is filled with 3 colors.
* O(1)
*/
bool ByColorPathGenerator::isFullVertex(int vertex)
{
    return freePosInVertex(vertex) == -1;
}

/*
* returns true, whether every vertex of 'lastResult' is filled with 3 colors.
*/
bool ByColorPathGenerator::isFullPath()
{
    throw new exception("da sa spravit v O(1), ak toto vidis, tak dorob!");
}

/*
* Generates next color's positions of given 'color' and modifies 'lastResult' to contain it.
* Algorithm creates the next possible deployment by vector 'colorsUsage'.
* Function preserves lexicographicity of colors in 'lastResult'.
* 
* Retruns true, if next color was generated
* Returns false, if the color was fully generated, and so 'lastResult' does not contain given color.
*/
bool ByColorPathGenerator::generateNextColor(int color)
{
    //Store usage of given color
    set<int> colorUsage = colorsUsage.at(color);

    //Generate new 'colorUsage' record and alter 'lastResult' correspondingly
    //TODO lexikografickost a disjunktnost
    for (int vertex = length - 1; vertex >= 0; vertex--)
    {
        if (colorUsage.count(vertex))
        {
            colorUsage.erase(vertex);
            int pos = colorAtPos(vertex, color);
            lastResult.set(vertex, pos, -1);
        }
        else
        {
            if (!isFullVertex(vertex))
            {
                colorUsage.insert(vertex);
                int pos = freePosInVertex(vertex);
                lastResult.set(vertex, pos, color);
                break;
            }
        }
        if (vertex == 0)
        {
            //we haven't found place to insert color - the color was fully geenrated
            //lastResult doesn't contain 'color' right now, no need to alter it even more
            if (colorsUsage.at(color) == colorUsage) cout << "TODO Uz sa rovnaju -> colorsUsage.at(color) == colorUsage"; //TODO opytaj sa ci treba nasledujuci riadok, alebo otesuj
            colorsUsage.at(color) = colorUsage; //colorUsage is emptied now, no need to call 'set<int>()'.
            return false;
        }
    }

    //Save new usage of color
    if (colorsUsage.at(color) == colorUsage) cout << "TODO Uz sa rovnaju -> colorsUsage.at(color) == colorUsage"; //TODO opytaj sa ci treba nasledujuci riadok, alebo otesuj
    colorsUsage.at(color) = colorUsage; //maybe not needed

    return true;
}

/*
* Sets 'lastResult' to corresponding path, that is next in order and is relevant.
* Function starts on given 'color' and increments it recursively, until possible.
* 
* Returns true, if the path is full.
* Returns false, if there is no possibility for next full path.
*/
bool ByColorPathGenerator::nextFullPathGenerator(int color)
{
    if (color >= colorsInPath()) return;

    while(true)
    {
        bool isFullPath = nextFullPathGenerator(color + 1);
        if (isFullPath) return true;

        bool colorFinished = !generateNextColor(color);
        if (colorFinished) return false;
    }
}

/*
* Sets 'lastResult' to corresponding path, that is next in order and is relevant.
* 
* Returns true, if the path is full.
* Returns false, if there is no possibility for next full path.
*/
bool ByColorPathGenerator::nextFullPath()
{
    return nextFullPathGenerator(0);
}

/*
* Initialize this path generator
* Returns the first path.
*/
Path ByColorPathGenerator::initialPath()
{
    return nextPath();
}

Path ByColorPathGenerator::nextPath()
{
    if (nextFullPath())
        return lastResult;

    else Path();
}
