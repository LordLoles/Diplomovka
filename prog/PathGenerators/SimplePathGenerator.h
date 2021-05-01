#ifndef SIMPLEPATHGENERATOR_H
#define SIMPLEPATHGENERATOR_H

#include <vector>
#include <tuple>
#include "../Path.h"
#include "../Utils.h"

using namespace std;

class SimplePathGenerator
{
    private:
        int length;
        long long nextLists; //next indeces of color lists (allColorSubsets) to be used in nextPath() in decimal
        Path allColorSubsets; //all possible lists of colors (triplets) that will be used on verteces
                              //-------not really a Path -> just to store it nicely-------

    public:
        SimplePathGenerator(int lengthOfPath, int colorsInPath);
        Path nextPath();
};

#endif
