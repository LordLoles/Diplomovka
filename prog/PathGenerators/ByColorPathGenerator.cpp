#include "ByColorPathGenerator.h"
#include "PathRelevanceCheck.h"
#include <iostream>
#include "PathRelevanceCheck.h"

using namespace std;


ByColorPathGenerator::ByColorPathGenerator(int lengthOfPath, int colorsInPath) 
    : allColors(getSetToLength(colorsInPath))
    , length(lengthOfPath)
    , colorBeingGenerated(0)
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
* Returns false, if the given 'color' is on verteces with every other color (only those colors with number lesser than 'color').
* Returns true otherwise.
* O(n + k)
*/
bool ByColorPathGenerator::isColorDisjunct(int color)
{
    vector<bool> seen = vector<bool>(color);
    int colorsSeen = 0;
    set<int> vertecesToCheck = colorsUsage.at(color);
    for (int i : vertecesToCheck)
    {
        for (int j = 0; j < 3; j++)
        {
            int colorNow = lastResult.at(i).at(j);
            if (colorNow != -1 && colorNow < color && !seen.at(colorNow))
            {
                seen.at(colorNow) = true;
                colorsSeen++;
            }
        }
    }

    return colorsSeen != color;
}

/*
* Deletes given color from 'lastResult' and from 'colorsUsage'.
*/
void ByColorPathGenerator::deleteColor(int color)
{
    set<int> vertecesToCheck = colorsUsage.at(color);
    for (int vertex : vertecesToCheck)
    {
        int pos = colorsPosition(vertex, color);
        lastResult.set(vertex, pos, -1);
    }
    colorsUsage.at(color) = set<int>();
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
int ByColorPathGenerator::colorsPosition(int vertex, int color)
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
    return colorsPosition(vertex, -1);
}

/*
* returns true, if the vertex at given position is filled with 3 colors.
* O(1)
*/
bool ByColorPathGenerator::isFullVertex(int vertex)
{
    return freePosInVertex(vertex) == -1;
}

/*
* returns true, if every vertex of 'lastResult' is filled with 3 colors.
*/
bool ByColorPathGenerator::isFullPath()
{
    return getFirstNotFullVertex() == -1;
}

/*
* Returns the position of first not full vertex.
* Returns -1 if the path is full.
* O(n)
* TODO O(1)
*/
int ByColorPathGenerator::getFirstNotFullVertex()
{
    for (int i = 0; i < length; i++)
    {
        if (!isFullVertex(i)) return i;
    }
    return -1;
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
    bool inserted = false;

    //Store usage of given color
    set<int> colorUsage = colorsUsage.at(color);

    //Make color lexicographically first, if it's not already - this happens on the color addition
    int firstNotFullVertex = getFirstNotFullVertex();
    int firstVertexWithThisColor = colorUsage.empty() ? length : *colorUsage.begin(); //minimal element in set<int>, or 'length', if no vertex has this color
    if ((firstNotFullVertex != -1) && (firstNotFullVertex < firstVertexWithThisColor)) //path is not full && color is not lexicographically first
    {
        colorUsage.insert(firstNotFullVertex);
        colorsUsage.at(color) = colorUsage;
        int pos = freePosInVertex(firstNotFullVertex);
        lastResult = lastResult.set(firstNotFullVertex, pos, color);
        return true; //we can return, as next color was added
    }

    //Generate new 'colorUsage' record and alter 'lastResult' correspondingly
    for (int vertex = length - 1; vertex >= 0; vertex--)
    {
        if (colorUsage.count(vertex))
        {
            colorUsage.erase(vertex);
            int pos = colorsPosition(vertex, color);
            lastResult = lastResult.set(vertex, pos, -1);
        }
        else
        {
            if (!isFullVertex(vertex))
            {
                colorUsage.insert(vertex);
                int pos = freePosInVertex(vertex);
                lastResult = lastResult.set(vertex, pos, color);
                inserted = true;
                break;
            }
        }
    }

    if (!inserted)
    {
        //we haven't found place to insert color - the color was fully geenrated, so return false
        //lastResult doesn't contain 'color' any more, no need to alter it
        colorsUsage.at(color) = colorUsage; //colorUsage is emptied now, no need to call 'set<int>()'.
        return false;
    }

    //TODO disjunktnost

    //Save new usage of color
    colorsUsage.at(color) = colorUsage;

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
    if (color >= colorsInPath())
    {
        colorBeingGenerated--;
        return false;
    }
    

    //lets continue from color, we have ended previously, so pass the smaller colors
    if (color < colorBeingGenerated)
    {
        bool isPathFull = nextFullPathGenerator(color + 1);
        if (isPathFull) return true;

        //if this color is not on any vertex and it was passed (previous if), this color was previously fully generated
        if (colorsUsage.at(color).empty())
        {
            colorBeingGenerated--;
            return false;
        }
    }
    

    while(true)
    {
        bool colorFinished = !generateNextColor(color);
        if (colorFinished)
        {
            colorBeingGenerated--;
            return false;
        }
        if (isColorDisjunct(color))
        {
            deleteColor(color);
            colorBeingGenerated--;
            return false;
        }
        if (isFullPath()) return true;

        colorBeingGenerated++;
        bool isPathFull = nextFullPathGenerator(color + 1);
        if (isPathFull) return true;
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

    else return Path();
}
