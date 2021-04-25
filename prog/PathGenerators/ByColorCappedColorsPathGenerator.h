#ifndef BYCOLORCAPPEDCOLORSPATHGENERATOR_H
#define BYCOLORCAPPEDCOLORSPATHGENERATOR_H

#include <vector>
#include <tuple>
#include <unordered_map>
#include <set>
#include "../Path.h"
#include "../Utils.h"
#include "./ByColorPathGenerator.h"

using namespace std;

class ByColorCappedColorsPathGenerator : public ByColorPathGenerator
{
    private:
        int cap;

    public:
        ByColorCappedColorsPathGenerator(int lengthOfPath, int colorsCap);

        bool isFullPath();
        bool nextFullPathGenerator(int color);
        bool nextFullPath();

        Path initialPath();
        Path nextPath();
};

#endif
