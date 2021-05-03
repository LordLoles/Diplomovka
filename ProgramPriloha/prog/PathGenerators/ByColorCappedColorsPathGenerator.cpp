#include "ByColorCappedColorsPathGenerator.h"
#include "PathRelevanceCheck.h"
#include <iostream>
#include "PathRelevanceCheck.h"

using namespace std;


ByColorCappedColorsPathGenerator::ByColorCappedColorsPathGenerator(int lengthOfPath, int colorsCap)
    : cap(colorsCap)
    , ByColorPathGenerator(lengthOfPath, colorsCap + 3)
{ }


/*
* returns true, if every vertex of 'lastResult' is filled with 3 colors.
*/
bool ByColorCappedColorsPathGenerator::isFullPath()
{
    return colorBeingGenerated >= cap - 1;
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
bool ByColorCappedColorsPathGenerator::nextFullPathGenerator(int color)
{
    if (color >= cap)
    {
        colorBeingGenerated--;
        return false;
    }
    
    //lets continue from color, we have ended previously, so skip the smaller colors
    if (color < colorBeingGenerated)
    {
        bool isPathFull = nextFullPathGenerator(color + 1);
        if (isPathFull) return true;

        //if this color is not on any vertex and it was skipped (pre-previous if), this color was previously fully generated
        if (colorsUsage.at(color).empty())
        {
            colorBeingGenerated--;
            return false;
        }
    }
    
    while(true)
    {
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
            /*cout << "zahadzujem ";
            lastResult.printPath();*/
            continue;
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
bool ByColorCappedColorsPathGenerator::nextFullPath()
{
    return nextFullPathGenerator(0);
}

/*
* Initialize this path generator
* Returns the first path.
*/
Path ByColorCappedColorsPathGenerator::initialPath()
{
    return nextPath();
}

Path ByColorCappedColorsPathGenerator::nextPath()
{
    if (nextFullPath())
        return lastResult;

    else return Path();
}
