#ifndef BYCOLORPATHGENERATOR_H
#define BYCOLORPATHGENERATOR_H

#include <vector>
#include <tuple>
#include <unordered_map>
#include <set>
#include "../Path.h"
#include "../Utils.h"

using namespace std;

class ByColorPathGenerator
{
    protected:
        int length;
        vector<int> allColors;
        int colorBeingGenerated;
        int maxColorUsed = -1;


    public:
        Path lastResult;
        vector<set<int>> colorsUsage;

        ByColorPathGenerator(int lengthOfPath, int colorsInPath);

        int colorsUsed(); // just for curiousity

        bool isColorDisjunct(int color);
        bool canBeFilledVertex(int vertex, int remainingColors);
        bool canBeFilled(int color);
        bool checkWholeColorLex(int color);
        bool checkWholeColorsLex(int color1, int color2, int vertex);
        void deleteColor(int color);
        void deleteColorBeingGenerated();

        int colorsInPath();
        int colorsPosition(int vertex, int color);
        int freePosInVertex(int vertex);
        bool isFirstAppearance(int color, int vertex);
        int getFirstAppearance(int color);
        bool isFullVertex(int vertex);
        bool isFullPath();
        int getFirstNotFullVertex();

        bool generateFillingColors(int color);
        bool generateNextColor(int color);
        bool nextFullPathGenerator(int color);
        bool nextFullPath();

        Path initialPath();
        Path nextPath();
};

#endif
