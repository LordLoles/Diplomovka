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
        Path allColorSubsets; //all possible lists of colors (triplets) that will be used on verteces  -------not really a Path -> just to store it nicely-------

    public:
        SimplePathGenerator(int lengthOfPath, int colorsInPath);
        Path nextPath(); //const Path & nextPath(), ked to bude rozumne brat cestu a ulozi si ju popredu, namiesto longlong nextLists;
        //TODO negeneruj tie cesty, ktore maju farby s prienikom - rovno zahod (ze farba 1 a farba 2 su presne v tych istych zoznamoch - to nechceme)
        //TODO novy generator - po farbach - kde budu farby 1, kde farby 2, ... (hned vyuzijes, kde maju farby prienik)
};

#endif