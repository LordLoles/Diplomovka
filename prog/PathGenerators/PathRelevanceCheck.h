#ifndef PATHRELEVANCECHECK_H
#define PATHRELEVANCECHECK_H

#include <vector>
#include <tuple>
#include <unordered_map>
#include <set>
#include "../Path.h"

using namespace std;

bool hasDisjunctColor(vector<set<int>> colorsUsage);

bool noColorsDisjunct(vector<set<int>> colorsUsage);

bool isFirstLexicographically(Path path, int colorsInPath);

/*
* Returns true, if the given path is empty, or all checks passes
*/
bool isPathRelevant(Path path, vector<set<int>> colorsUsage, int colorsInPath);

#endif
