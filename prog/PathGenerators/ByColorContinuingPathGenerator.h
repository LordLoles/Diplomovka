#ifndef BYCOLORCONTINUINGPATHGENERATOR_H
#define BYCOLORCONTINUINGPATHGENERATOR_H

#include <vector>
#include <tuple>
#include <unordered_map>
#include <set>
#include "../Path.h"
#include "../Utils.h"
#include "./ByColorPathGenerator.h"

using namespace std;

class ByColorContinuingPathGenerator : public ByColorPathGenerator
{
    private:
        int startingColor;

    public:
        ByColorContinuingPathGenerator(int lengthOfPath, int startingColor, int colorsInPath, Path initialPath);

        bool nextFullPathGenerator(int color);
        bool nextFullPath();

        Path initialPath();
        Path nextPath();
};

#endif
