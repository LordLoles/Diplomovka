#ifndef PATHGENERATOR_H
#define PATHGENERATOR_H

#include <vector>
#include <tuple>
#include "Path.h"
//#include "Path.cpp"
#include "Utils.h"

using namespace std;

class PathGenerator
{
    private:
        int length;
        long long nextLists; //next indeces of color lists (allColorSubsets) to be used in nextPath() in decimal
        Path allColorSubsets; //all possible lists of colors (triplets) that will be used on verteces  -------not really a Path -> just to store it nicely-------

    public:
        PathGenerator(int lengthOfPath, int colorsInPath);
        Path nextPath();
};

#endif