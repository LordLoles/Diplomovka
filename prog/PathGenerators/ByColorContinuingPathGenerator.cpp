#include "ByColorContinuingPathGenerator.h"
#include "PathRelevanceCheck.h"
#include <iostream>
#include "PathRelevanceCheck.h"
#include "../Utils.h"

using namespace std;


ByColorContinuingPathGenerator::ByColorContinuingPathGenerator(int lengthOfPath, int startingColor, int colorsInPath, Path initialPath)
    : startingColor(startingColor)
    , ByColorPathGenerator(lengthOfPath, colorsInPath)
{
    lastResult = initialPath;
    colorsUsage = getColorsUsage(initialPath, colorsInPath);
}


/*
* Sets 'lastResult' to corresponding path, that is next in order and is relevant.
* Function starts on given 'color' and increments it recursively, until possible.
* 
* Returns true, if the path is full.
* Returns false, if there is no possibility for next full path.
*
* O(2^k(n + log(k)))
*/
bool ByColorContinuingPathGenerator::nextFullPathGenerator(int color)
{
    if (color >= colorsInPath())
    {
        colorBeingGenerated--;
        return false;
    }
    
    //lets continue from color, we have ended previously, so skip the smaller colors
    //skip also those, that we are not supposed to change
    if (color < colorBeingGenerated || color < startingColor)
    {
        bool isPathFull = nextFullPathGenerator(color + 1);
        if (isPathFull) return true;

        //if this color is not on any vertex and it was skipped (pre-previous if), this color was previously fully generated
        if (colorsUsage.at(color).empty())
        {
            colorBeingGenerated--;
            return false;
        }

        if (color < startingColor) return false;
    }
    
    while(true)
    {
        //cout << "farba " << color << endl;
        bool colorFinished = !generateNextColor(color);
        if (maxColorUsed < color) maxColorUsed = color; //just to know the max count of colors used on this length
        if (colorFinished)
        {
            colorBeingGenerated--;
            return false;
        }
        generateFillingColors(color); //when the color has not finished, fill spots that needs this color, so path can be full
        if (isColorDisjunct(color) || !checkWholeColorLex(color))
        {
            continue;
        }
        if (isFullPath())
        {
            return true;
        }

        colorBeingGenerated++;
        bool isPathFull = nextFullPathGenerator(color + 1);
        if (isPathFull) {
            return true;
        }
    }
}

/*
* Sets 'lastResult' to corresponding path, that is next in order and is relevant.
* 
* Returns true, if the path is full.
* Returns false, if there is no possibility for next full path.
*/
bool ByColorContinuingPathGenerator::nextFullPath()
{
    return nextFullPathGenerator(0);
}

/*
* Initialize this path generator
* Returns the first path.
*/
Path ByColorContinuingPathGenerator::initialPath()
{
    return nextPath();
}

Path ByColorContinuingPathGenerator::nextPath()
{
    if (nextFullPath())
        return lastResult;

    else return Path();
}
