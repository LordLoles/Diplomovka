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
        //TODO iny generator, ktory hned kontroluje (alebo vracia ciastocne farbenia?) ci je repeticia - nagenerujem prve dve farby farbenia 0 0 a treba skoncit.
        //asi ciastocne farbenie, vrati -> 0, 00, 000, 0000, 0001, 0002, 0003, 001, 0010, ... 
        //funkcia skip - preskoci podvetvy farbenia -> farbenie 00, zavolam skip, dalsie farbenie 01 (neprejde synov 000, 0000, 0001, ...)
        //kontrola staci na posledny generovany prvok
        //ako v pathGen, vracaj const na farbenie, co drzis ako premennu v triede a robis s nou ten nejaky next
};

#endif
