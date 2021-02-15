#include "./PathRelevanceCheck.h"
#include <iostream>
#include <algorithm>

using namespace std;

//O(n + m)
bool areDisjoint(set<int> set1, set<int> set2) 
{
    set<int>:: iterator it;
    for( it = set2.begin(); it != set2.end(); ++it)
    {
        int elem = *it;
        if (set1.find(elem) != set1.end()) 
            return false; 
    }
    return true; 
}

//O(n^3) !!!
//TODO da sa nejaky alg na lepsiu casovu zlozitost
/*
* Returns true, if some two colors in 'colorsUsage' are on disjunct verteces.
*/
bool hasDisjunctColor(vector<set<int>> colorsUsage)
{
    for (int color1 = 0; color1 < colorsUsage.size(); color1++)
    {
        set<int> colorUsage1 = colorsUsage[color1];
        for (int color2 = color1; color2 < colorsUsage.size(); color2++)
        {
            set<int> colorUsage2 = colorsUsage[color2];
            if (areDisjoint(colorUsage1, colorUsage2)) return true; //O(n)
        }
    }
    return false;
}

/*
* Returns negation of 'hasDisjunctColor'.
* Returns false, if some two colors in 'colorsUsage' are on disjunct verteces.
* Returns true, if all color pairs are on disjunct verteces.
*/
bool noColorsDisjunct(vector<set<int>> colorsUsage)
{
    return !hasDisjunctColor(colorsUsage);
}

/*
* Returns true, if the given path is lexicographically first, thus uses the smallest colors possible.
*/
bool isFirstLexicographically(Path path, int colorsInPath)
{
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

    return true;
}

/*
* Returns true, if the given path is empty, or all checks passes
*/
bool isPathRelevant(Path path, vector<set<int>> colorsUsage, int colorsInPath)
{
    return path.empty() || 
        (
            noColorsDisjunct(colorsUsage) && 
            isFirstLexicographically(path, colorsInPath)
        );
}
