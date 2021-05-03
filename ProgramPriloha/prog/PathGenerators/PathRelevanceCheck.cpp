#include "./PathRelevanceCheck.h"
#include <iostream>

using namespace std;

/*
* Returns true, if some two colors are on disjunct verteces.
* Time O(n + k^2), n is path size, k is count of colors
* Space O(k^2)
*/
bool hasDisjunctColor(Path path, vector<set<int>> colorsUsage)
{
    int colorsInPath = colorsUsage.size();
    
    
    //Count, how mnay colors are actually used
    vector<bool> colorsSeen = vector<bool>(colorsInPath);
    int usedColorsCount = 0;

    for (int i = 0; i < path.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int color = path.at(i).at(j);
            if(!colorsSeen[color])
            {
                colorsSeen[color] = true;
                usedColorsCount++;
            }
        }
    }


    //1st heuristic
    //example on path {0,1,2}, {2,3,4}, {1,4,5} -> on each vertex there are 3 pairs of colors, so 9 pairs on whole path
    //now count all possible pairs (sum) for 6 colors - there are 15 possibilities
    //because (9 < 15), we can not fulfil the condition, that all colors needs to be with every color on some vertex, to avoid disjunction

    // '3 * path.size()' means, that on vertex we will consider 3 pairs (0th color with 1st, 0th with 2nd, 1st with 2nd), that can affect disjunction of colors,
    //thus we will try to find information about disjunction of color 3 times on every vertex on 'path' -> from there is '3 * path.size()'
    // '(usedColorsCount * usedColorsCount)' is whole matrix - pair of colors
    // '- usedColorsCount' is whole matrix without elements on diagonal ((0,0), (1,1), etc.)
    // '/ 2' is there, because we count only those lexicographically sonner (we count (0,1), but not (1,0)))
    //whole '(((usedColorsCount * usedColorsCount) - usedColorsCount) / 2)' is then count of different pairs, that needs to be found, 
    //in order to know, if some two colors are on disjunct verteces.
    //
    //if there will be less tries than count of different pairs, we can surely say, there will be some color disjunct, thus return true
    if ((3 * path.size()) < (((usedColorsCount * usedColorsCount) - usedColorsCount) / 2)) return true;


    //2nd heuristic
    //example on path {0,1,2} {3,4,5} -> color '0' is used only once, thus only two colors (1,2 respectively) will not be disjunct with it
    //but as there are 6 colors in use, from dirichlet, there exists at least one color that is on verteces, where '0' is not, so those colors are disjunct

    //firstly find out the least used color - color used on the least amount of verteces on 'path'
    int leastUsedColor = 0;
    for (int i = 0; i < colorsInPath; i++)
    {
        if ((!colorsUsage[i].empty()) && (colorsUsage[i].size() < colorsUsage[leastUsedColor].size()))
        {
            leastUsedColor = i;
        }
    }
    // 'colorsUsage[leastUsedColor].size() * 2' means, that the least used color can be at every vertex maximally with 2 different color
    //the least used color can be disjunct with maximally this many colors
    //if this number is less than count of used colors in 'path' (expect the least used one, so '- 1'), 
    //some color needs to be disjunct with the least used color, so we can return true
    if ((colorsUsage[leastUsedColor].size() * 2) < (usedColorsCount - 1)) return true;


    //actual start of code for this function
    vector<vector<bool>> seen = vector<vector<bool>>(colorsInPath);
    for (int i = 0; i < colorsInPath; i++)
    {
        seen[i] = vector<bool>(colorsInPath);
    }
    int seenCount = 0;

    array<int, 2> a = {0,1};
    array<array<int, 2>, 3> vertexPairs = {a, {0,2}, {1,2}};

    for (int i = 0; i < path.size(); i++)
    {
        array<int, 3> vertex = path.at(i);
        
        for (int pairIndex = 0; pairIndex < 3; pairIndex++)
        {
            int vertexIndex0 = vertexPairs[pairIndex][0];
            int vertexIndex1 = vertexPairs[pairIndex][1];
            if (!seen[vertex[vertexIndex0]][vertex[vertexIndex1]])
            {
                //add to 'seen' and count in 'seenCount'
                seen[vertex[vertexIndex0]][vertex[vertexIndex1]] = true;
                seen[vertex[vertexIndex1]][vertex[vertexIndex0]] = true;
                seenCount += 2;
            }
        }
    }
    if (seenCount == ((usedColorsCount * usedColorsCount) - usedColorsCount)) return false; //have we seen every pair? (not counting (0,0), (1,1), etc.)
    else return true; //there is some color, that was not seen in vertex with some other color, thus is disjunct
}

/*
* Returns negation of 'hasDisjunctColor'.
* Returns false, if some two colors in 'colorsUsage' are on disjunct verteces.
* Returns true, if all color pairs are on disjunct verteces.
*/
bool noColorsDisjunct(Path path, vector<set<int>> colorsUsage)
{
    return !hasDisjunctColor(path, colorsUsage);
}

/*
* Returns true, if the given path is lexicographically first, thus uses the smallest colors possible.
* Time O(n), where n is path.size()
*/
bool isFirstLexicographically(Path path, int colorsInPath)
{
    //Heuristic - first vertex needs to be {0, 1, 2}
    //if (path.at(0) != array<int, 3>{0, 1, 2}) return false; //is already in 'increment()' in 'By

    //TODO prebehni cestu, narataj farby, nech sa nemusi posielat argument 'colorsInPath'... alebo rovno vytvor vector bez pociatocnej velkosti
    vector<bool> colorsSeen = vector<bool>(colorsInPath); //at position 'i' is information, whether we have seen color 'i' already
    int nextColor = 0; //what is the next lexicographical color

    for (int i = 0; i < path.size(); i++)
    {
        array<int, 3> vertex = path.at(i);
        for (int j = 0; j < 3; j++)
        {
            //from left to right check every color on path
            int color = vertex.at(j);
            if (!colorsSeen[color]) //little bit faster than (color >= nextColor)
            {
                if (color == nextColor)
                {
                    colorsSeen[nextColor] = true;
                    nextColor++;
                }
                else //if (color > nextColor)
                {
                    return false;
                }
            }
        }
    }
    //TODO otoc cestu a skus, ci nie je este lepsia

    return true;
}

/*
* Returns true, if the given path is empty, or all checks passes
*/
bool isPathRelevant(Path path, vector<set<int>> colorsUsage)
{
    return path.empty() || 
        (
            isFirstLexicographically(path, colorsUsage.size()) &&
            noColorsDisjunct(path, colorsUsage)
        );
}
