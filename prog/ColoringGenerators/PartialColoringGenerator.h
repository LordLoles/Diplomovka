#ifndef PARTIALCOLORINGGENERATOR_H
#define PARTIALCOLORINGGENERATOR_H

#include <vector>
#include "../Path.h"
#include "../Coloring.h"
#include "../Utils.h"

using namespace std;

class PartialColoringGenerator
{
    private:
        int fullLength;
        Path path;
        Coloring lastResult;
        vector<int> colorIndeces;

        bool canIncrement(Coloring col);
        Coloring increment(Coloring col);
        bool canBeEnlarged(Coloring col);
        Coloring enlarge(Coloring col);
        Coloring shrink(Coloring col);
        Coloring shrinkUntilCanIncrement(Coloring col);

    public:
        PartialColoringGenerator(Path path);
        Coloring initialColoring();
        Coloring nextColoring();
        Coloring skipColoring();
        bool isFullColoring();
        //TODO iny generator, ktory hned kontroluje (alebo vracia ciastocne farbenia?) ci je repeticia - nagenerujem prve dve farby farbenia 0 0 a treba skoncit.
        //asi ciastocne farbenie, vrati -> 0, 00, 000, 0000, 0001, 0002, 0003, 001, 0010, ... 
        //funkcia skip - preskoci podvetvy farbenia -> farbenie 00, zavolam skip, dalsie farbenie 01 (neprejde synov 000, 0000, 0001, ...)
        //kontrola staci na posledny generovany prvok
        //ako v pathGen, vracaj const na farbenie, co drzis ako premennu v triede a robis s nou ten nejaky next
};

#endif
