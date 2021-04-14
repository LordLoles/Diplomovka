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
* Returns the number of colors used at this point of generation.
*/
int ByColorPathGenerator::colorsUsed()
{
    return maxColorUsed + 1; //don't forget the zero
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
* Returns true, if the given 'vertex' of 'lastResult' can be fully filled with 'remainingColors'.
* Returns false otherwise.
* O(1)
*/
bool ByColorPathGenerator::canBeFilledVertex(int vertex, int remainingColors)
{
    int freePos = freePosInVertex(vertex);
    return ((freePos == -1) || //vertex is already full
        ((3 - freePos) <= remainingColors)); //there are less empty positions, than colors left
}

/*
* Returns true, if the path 'lastResult' can be fully filled with remaining colors (colorsInPath() - 'color').
* Returns false, if there is at least one vertex, that can not be filled with remaining colors.
* Given 'color' is also assumed in computation.
* 
* Example on path [-1, -1, -1] [0, 2, -1], with 3 colors in path
*   canBeFilled(0) returns true, as both vertexes can be filled with 3 (= colorsInPath() - 'color') colors.
*   canBeFilled(1) returns false, as vertex 0 can not be filled with 2 (= colorsInPath() - 'color') colors.
*
* O(n)
*/
bool ByColorPathGenerator::canBeFilled(int color)
{
    int remainingColors = colorsInPath() - color;

    for (int i = 0; i < length; i++)
    {
        if (!canBeFilledVertex(i, remainingColors)) return false;
    }
    return true;
}

/*
* Returns true, if given color is lexicographically sooner, than smaller colors on vertex of color's first appearance.
* Function is applicable only for color, thats first appearence is on the same vertex as some other's color's first appearence.
* 
* Example on path [x, x, x] [1, 2, x] [x, 2, x] [x, 1, x] (x is anything expect 1, 2):
*   for color 2 this retruns false, as color 2 is present on next verteces lexicographically sooner, 
*   than color 1 (color 1 is on vertex 1 - first appearence of colors 1 and 2, thus we are checking it)
* Example on path [x, 1, x] [1, 2, x] [x, 2, x] [x, 1, x] (x is anything expect 1, 2):
*   for color 2 this retruns true, as there is no color starting on the same vertex as color 2 (not assuming color x).
*
* O(n)
*/
bool ByColorPathGenerator::checkWholeColorLex(int color)
{
    int vertex = getFirstAppearance(color);
    for (int i = 0; i < 3; i++)
    {
        int colorNow = lastResult.at(vertex).at(i);
        if (colorNow != -1 && colorNow < color && isFirstAppearance(colorNow, vertex))
        {
            bool lex = checkWholeColorsLex(colorNow, color, vertex);
            if (!lex) return false;
        }
    }
    return true;
}

/*
* Returns true, if the bigger color is lexicographically sooner, than the smaller one, going from given vertex forth.
* Colors order is not relevant - they are swapped, if color2 < color1.
* Function assumes, that the colors on verteces of 'lastResult' are lexicographical (for instance [2, 3, 5]).
* 
* Example on path [x, x, x] [1, 2, x] [x, 2, x] [x, 1, x] (x is anything expect 1, 2):
*   for colors 1, 2 (and 2, 1), vertex 1 this retruns false, as color 2 is present on next verteces lexicographically sooner, than color 1.
*
* Example on path [x, 1, x] [1, 2, x] [x, 2, x] [x, 1, x] (x is anything expect 1, 2):
*   for color 1, 2 (and 2, 1), vertex 1 this is the same as previous example, as given vertex is 1.
*
* O(n)
*/
bool ByColorPathGenerator::checkWholeColorsLex(int color1, int color2, int vertex)
{
    //swap colors, so color1 is lesser than color2
    if (color2 < color1)
    {
        int tmp = color1;
        color1 = color2;
        color2 = tmp;
    }

    //check path from vertex forth
    for (int i = vertex + 1; i < length; i++)
    {
        int pos1 = colorsPosition(i, color1);
        int pos2 = colorsPosition(i, color2);

        if (pos1 != -1)
        {
            if (pos2 != -1)
            {
                //vertex contains both colors, so continue
                continue;
            }
            else
            {
                //vertex contains only color1 and we haven't returned before, thus return true
                return true;
            }
        }
        else if (pos2 != -1)
        {
            //we are in vertex, that contains color2, but no color1 and we haven't returned before, thus return false
            return false;
        }
        //else { //we are in vertex that doesn't contain color1 nor color2, so continue}
    }
    return true; //colors are on identical verteces
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
        lastResult = lastResult.set(vertex, pos, -1);
    }
    colorsUsage.at(color) = set<int>();
}

/*
* Calls 'deleteColor(colorBeingGenerated)' and decrements 'colorBeingGenerated'.
*/
void ByColorPathGenerator::deleteColorBeingGenerated()
{
    deleteColor(colorBeingGenerated);
    colorBeingGenerated--;
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
* Returns true, if the given color is not present sooner than on given vertex (so it is color's first appearance on given vertex).
* Retruns false otherwise.
* Function does not check presence of given color on given vertex, or even on whole path.
*
* O(n)
*/
bool ByColorPathGenerator::isFirstAppearance(int color, int vertex)
{
    return getFirstAppearance(color) >= vertex;
}

/*
* Returns index of the most-left vertex (first), on which the given color is present.
* Returns -1, if the color is not present in 'lastResult'.
*
* O(n)
*/
int ByColorPathGenerator::getFirstAppearance(int color)
{
    for (int i = 0; i < length; i++)
    {
        if (colorsPosition(i, color) != -1) return i;
    }
    return -1;
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
* Generates given color in 'lastResult' on poistions, where it is not possible for the remaining colors to make the path full.
*
* Returns true, if at least one color was added.
* Returns false, if 'lastResult' was unchanged.
*
* O(n)
*/
bool ByColorPathGenerator::generateFillingColors(int color)
{
    set<int> colorUsage = colorsUsage.at(color);
    bool canBeFull = canBeFilled(color + 1);

    if (!canBeFull)
    {
        int remainingColors = colorsInPath() - (color + 1); //not counting with this 'color'
        for (int i = 0; i < length; i++)
        {
            if (!canBeFilledVertex(i, remainingColors) && (!colorUsage.count(i)))
            {
                colorsUsage.at(color).insert(i);
                int pos = freePosInVertex(i);
                lastResult = lastResult.set(i, pos, color);
            }
        }
    }
    return !canBeFull;
}

/*
* Generates next color's positions of given 'color' and modifies 'lastResult' to contain it.
* Algorithm creates the next possible deployment by vector 'colorsUsage'.
* Function preserves lexicographicity of colors in 'lastResult'.
* 
* Retruns true, if next color was generated
* Returns false, if the color was fully generated, and so 'lastResult' does not contain given color.
*
* O(n + log(k))
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

    /*
    if (colorBeingGenerated < 0)
    {
        cout << "colorBeingGenerated is below zero... this should not happen..." << endl <<
        "Is the generator running just once? If no, use constructor to start generating from begining." << endl;
        return false;
    }*/
    
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
        if (maxColorUsed < color) maxColorUsed = color; //just to know the max count of colors used on this length
        if (colorFinished)
        {
            colorBeingGenerated--;
            return false;
        }
        generateFillingColors(color); //when the color has not finished, fill spots that needs this color, so path can be full
        if (isColorDisjunct(color) || !checkWholeColorLex(color))
        {
            cout << "zahadzujem ";
            lastResult.printPath();
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
