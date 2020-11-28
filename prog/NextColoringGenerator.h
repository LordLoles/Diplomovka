#ifndef NEXTCOLORINGGENERATOR_H
#define NEXTCOLORINGGENERATOR_H

#include <vector>
#include "Path.h"
//#include "Path.cpp"
#include "Coloring.h"
//#include "Coloring.cpp"
#include "Utils.h"

using namespace std;

class NextColoringGenerator
{
    private:
        int length;
        long long nextPathColoring; //next indeces of colors in path (list of colors for path) to be used in nextColoring() in decimal
        Path & path;

    public:
        NextColoringGenerator(int lengthOfPath, Path & path);
        Coloring nextColoring();
        void resetColoring();
};

#endif
