#include "ByColorPathGenerator.h"
#include "PathRelevanceCheck.h"
#include <iostream>

using namespace std;


ByColorPathGenerator::ByColorPathGenerator(int lengthOfPath, int colorsInPath) 
    : allColors(getSetToLength(colorsInPath))
    , length(lengthOfPath)
{
    if (colorsInPath < 3) throw "At least 3 colors are required.";

    for (int i = 0; i < colorsInPath; i++)
    {
        colorsUsage[i] = set<int>();
    }
}

void ByColorPathGenerator::setColor(int vertex, int position, int color)
{
    updateColorsUsage(vertex, position, color);
    lastResult = lastResult.set(vertex, position, color); //modify our resulting path
}

/* 
* Updates 'colorsUsage' so by key 'newColor' you will get also 'vertex' in returning set
* Eraseing index 'vertex' from old color key and inserting 'vertex' to 'newColor' key
*/
void ByColorPathGenerator::updateColorsUsage(int vertex, int position, int newColor)
{
    int oldColor = lastResult.at(vertex)[position]; //Gets old color on that vertex and position
    colorsUsage[oldColor].erase(vertex); //Position 'vertex' has no longer old color
    colorsUsage[newColor].insert(vertex); //Position 'vertex' now contains color 'color'
}

/*
* Returns if the color at given vertex and position is the last possible color
*/
bool ByColorPathGenerator::isLast(int vertex, int position)
{
    return lastResult.at(vertex).at(position) == allColors.size();
}

/*
* At given vertex and position of lastResult resets the color -> sets it to color 'position'
*/
void ByColorPathGenerator::reset(int vertex, int position)
{
    updateColorsUsage(vertex, position, position);
    lastResult = lastResult.set(vertex, position, position);
}

/*
* Returns true, if increment was performed.
* Retruns false, if nothing happened.
*/
bool ByColorPathGenerator::incrementVertexPostion(int vertex, int position)
{
    if (isLast(vertex, position)) return false;
    else
    {
        lastResult = lastResult.increment(vertex, position);
        updateColorsUsage(vertex, position, lastResult.at(vertex).at(position));
        return true;
    }
}

/*
* Returns true, if increment was performed.
* Retruns false, if everything was just reset.
*/
bool ByColorPathGenerator::incrementVertex(int vertex)
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

void ByColorPathGenerator::increment()
{
    int vertexPos = length;
    while(!incrementVertex(vertexPos))
    {
        vertexPos--;
        if (vertexPos == -1)
        {
            //Can not increment more
            lastResult = Path();
            //colorsUsage = unordered_map<int, set<int>>();
        }
    }
}

Path ByColorPathGenerator::initialPath() //const nejde, lebo nepojde "colorsUsage[i] = set"
{
    vector<array<int, 3>> path;
    for (int i = 0; i < length; i++)
        path.push_back({0,1,2});

    vector<int> allVertecesVector = getSetToLength(length);
    for (int i = 0; i < 3; i++)
        colorsUsage[i] = set<int>(allVertecesVector.begin(), allVertecesVector.end());

    return Path(path); //Assuming initial path is relevant and doesn't need a check
}

Path ByColorPathGenerator::nextPath() //const nejde, lebo nepojde "colorsUsage[i] = set"
{
    increment();

    if (PathRelevanceCheck::isPathRelevant(lastResult, colorsUsage, allColors.size())) return lastResult;
    else return nextPath();
}
