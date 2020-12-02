#ifndef COLORINGGENERATOR_H
#define COLORINGGENERATOR_H

#include <vector>
#include "Path.h"
//#include "Path.cpp"
#include "Coloring.h"
//#include "Coloring.cpp"
#include "Utils.h"

using namespace std;

class ColoringGenerator
{
    private:
        int length;
        long long nextPathColoring; //next indeces of colors in path (list of colors for path) to be used in nextColoring() in decimal
        Path path;

    public:
        ColoringGenerator(Path path);
        Coloring nextColoring();
};

#endif
