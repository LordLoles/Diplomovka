#include "SimpleWithMemoryPathGenerator.h"
#include "PathRelevanceCheck.h"
#include <iostream>
#include "PathRelevanceCheck.h"

using namespace std;


SimpleWithMemoryPathGenerator::SimpleWithMemoryPathGenerator(int lengthOfPath, int colorsInPath) 
    : allColors(getSetToLength(colorsInPath))
    , length(lengthOfPath)
    , lastResult(Path())
{
    if (colorsInPath < 3) throw "At least 3 colors are required.";

    colorsUsage = vector<set<int>>(colorsInPath);
    for (int i = 0; i < colorsInPath; i++)
    {
        colorsUsage[i] = set<int>();
    }
}

void SimpleWithMemoryPathGenerator::setColor(int vertex, int position, int color)
{
    updateColorsUsage(vertex, position, color);
    lastResult = lastResult.set(vertex, position, color); //modify our resulting path
}

/* 
* Updates 'colorsUsage' (so with colorsUsage['newColor'] you will also get 'vertex' in returning set)
* Erasing index 'vertex' from old color key and inserting 'vertex' to 'newColor' key
*/
void SimpleWithMemoryPathGenerator::updateColorsUsage(int vertex, int position, int newColor)
{
    int oldColor = lastResult.at(vertex)[position]; //Gets old color on that vertex and position
    colorsUsage[oldColor].erase(vertex); //Position 'vertex' has no longer old color
    colorsUsage[newColor].insert(vertex); //Position 'vertex' now contains color 'color'
}

/*
* Returns if the color at given vertex and position is the last possible color
*/
bool SimpleWithMemoryPathGenerator::isLast(int vertex, int position)
{
    return lastResult.at(vertex).at(position) == (allColors.size() - 3 + position);
}

/*
* At given vertex and position of lastResult resets the color -> sets it to color 'position'
*/
void SimpleWithMemoryPathGenerator::reset(int vertex, int position)
{
    updateColorsUsage(vertex, position, position);
    lastResult = lastResult.set(vertex, position, position); //modify our resulting path
}

/*
* Returns true, if increment was performed.
* Retruns false, if nothing happened.
*/
bool SimpleWithMemoryPathGenerator::incrementVertexPostion(int vertex, int position)
{
    if (isLast(vertex, position)) return false;
    else
    {
        lastResult = lastResult.increment(vertex, position); //modify our resulting path
        updateColorsUsage(vertex, position, lastResult.at(vertex).at(position));
        return true;
    }
}

/*
* Returns true, if increment was performed.
* Retruns false, if everything was just reset.
*/
bool SimpleWithMemoryPathGenerator::incrementVertex(int vertex)
{

    if (!incrementVertexPostion(vertex, 2))
    {
        if (!incrementVertexPostion(vertex, 1))
        {
            if (!incrementVertexPostion(vertex, 0))
            {
                //if nothing was incremented, reset and return false
                reset(vertex, 0);
                reset(vertex, 1);
                reset(vertex, 2);
                return false;
            }
            else
            {
                //if 1st color was incremented, set 2nd and 3rd color to subsequent colors
                int newColor = lastResult.at(vertex).at(0);
                setColor(vertex, 1, newColor + 1);
                setColor(vertex, 2, newColor + 2);
            }
        }
        else
        {
            //if 2nd color was incremented, set 3rd to subsequent color
            int newColor = lastResult.at(vertex).at(1);
            setColor(vertex, 2, newColor + 1);
        }
    }
    //if 3rd color was incremented, nothing else needs to be done

    return true;
}

/*
* Increments the color on some position on some vertex.
* Increments the most right one, if can. if can not, goes one position left, and so on.
* Sets 'lastResult' to empty, if nothing can be incremented.
*/
void SimpleWithMemoryPathGenerator::increment()
{
    int vertexPos = length - 1;
    while(!incrementVertex(vertexPos))
    {
        vertexPos--;
        if (vertexPos < 1) //Don't increment first vertex, as it needs to be {0,1,2}
        {
            //Can't increment anything
            //colorsUsage = unordered_map<int, set<int>>();
            lastResult = Path();
            return;
        }
    }
}


/*
* Initialize this path generator
* Returns the first path.
*/
Path SimpleWithMemoryPathGenerator::initialPath() //const nejde, lebo nepojde "colorsUsage[i] = set..."
{
    vector<array<int, 3>> path;
    for (int i = 0; i < length; i++)
        path.push_back({0,1,2});
    lastResult = Path(path);

    vector<int> allVertecesVector = getSetToLength(length);
    for (int i = 0; i < 3; i++)
        colorsUsage[i] = set<int>(allVertecesVector.begin(), allVertecesVector.end());
        
    return lastResult; //Initial path is relevant and doesn't need a check
}

Path SimpleWithMemoryPathGenerator::nextPath() //const nejde, lebo nepojde "colorsUsage[i] = set"
{
    bool pathIsRelevant = false;
    while (!pathIsRelevant)
    {
        increment();
        pathIsRelevant = isPathRelevant(lastResult, colorsUsage);
    }
    return lastResult;
}
