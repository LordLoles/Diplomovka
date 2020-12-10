#ifndef PATHGENERATOR_H
#define PATHGENERATOR_H

#include <vector>
#include <tuple>
#include "Path.h"
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
        Path nextPath(); //const Path & nextPath(), ked to bude rozumne brat cestu a ulozi si ju popredu, namiesto longlong nextLists;
        //TODO novy generator - po farbach - kde budu farby 1, kde farby 2, ... (hned vyuzijes, kde maju farby prienik
        //TODO negeneruj tie cesty, ktore maju farby bez prienikom. cesty s prienikom zahod (ze farba 1 a farba 2 su presne v tych istych zoznamoch - to nechceme)
};

#endif
