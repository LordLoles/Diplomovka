#ifndef ALLANDWHOLECOLORINGGENERATOR_H
#define ALLANDWHOLECOLORINGGENERATOR_H

#include <vector>
#include "../Path.h"
#include "../Coloring.h"
#include "../Utils.h"

using namespace std;

class AllAndWholeColoringGenerator
{
    private:
        int length;
        long long nextPathColoring; //next indeces of colors in path (list of colors for path) to be used in nextColoring() in decimal
        Path path;

    public:
        AllAndWholeColoringGenerator(Path path);
        Coloring nextColoring();
};

#endif
