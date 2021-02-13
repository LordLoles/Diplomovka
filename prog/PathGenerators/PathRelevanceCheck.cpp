#include "./PathRelevanceCheck.h"

using namespace std;


bool hasDisjunctColor(unordered_map<int, set<int>> colorsUsage)
{
    //TODO
    return false;
}

bool noColorsDisjunct(unordered_map<int, set<int>> colorsUsage)
{
    return !hasDisjunctColor(colorsUsage);
}

bool isFirstLexicographically(Path path, int colorsInPath)
{
    //TODO
    return true;
}

/*
* Returns true, if the given path is empty, or all checks passes
*/
bool isPathRelevant(Path path, unordered_map<int, set<int>> colorsUsage, int colorsInPath)
{
    return path.empty() || 
        (
            noColorsDisjunct(colorsUsage) && 
            isFirstLexicographically(path, colorsInPath)
        );
}
