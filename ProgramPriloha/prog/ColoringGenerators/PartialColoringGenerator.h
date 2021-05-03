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

    public:
        Coloring lastResult;
        vector<int> colorIndeces;
        
        bool canIncrement();
        void increment();
        bool canBeEnlarged();
        void enlarge();
        void shrink();
        void shrinkUntilCanIncrement();

        PartialColoringGenerator(Path path);
        Coloring initialColoring();
        Coloring nextColoring();
        Coloring skipColoring();
        bool isFullColoring();
};

#endif
