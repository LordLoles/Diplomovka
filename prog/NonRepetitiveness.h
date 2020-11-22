#pragma once

#ifndef NONREPETITIVENESS_H
#define NONREPETITIVENESS_H

#include "Coloring.h"
//#include "Coloring.cpp"

using namespace std;

class NonRepetitiveness
{
    public:
        bool checkEqualityOnIndexWithSize(Coloring* coloring, int index, int size);
        bool checkNonRepetitivenessOnIndex(Coloring* coloring, int index);
        bool checkNonRepetitiveness(Coloring* coloring);
};
#endif
