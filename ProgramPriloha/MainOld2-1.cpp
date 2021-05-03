#include "Main.h"
#include "./prog/Utils.h"
#include "./prog/Coloring.h"
#include "./prog/Path.h"
#include "./prog/PathGenerators/SimplePathGenerator.h"
#include "./prog/ColoringGenerators/PartialColoringGenerator.h"
#include "./prog/NonRepetitiveness.h"
#include "./prog/Consts.h"
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;


int main()
{
    bool found;

    SimplePathGenerator pathGenerator = SimplePathGenerator(lengthOfPath, colorsInPath);
    Path nowPath = pathGenerator.nextPath();
    int paths = 0;

    while (!(nowPath.empty()))
    {
        found = false;
        paths++;

        PartialColoringGenerator coloringGenerator = PartialColoringGenerator(nowPath);
        Coloring coloring = coloringGenerator.initialColoring();
        
        while (!(coloring.empty()))
        {
            if (checkNonRepetitivenessOnLastIndex(coloring))
            {
                if (coloringGenerator.isFullColoring())
                {
                    found = true;
                    break;
                }
                else
                {
                    coloring = coloringGenerator.nextColoring();
                }
            }
            else
            {
                //coloring contains repetition
                coloring = coloringGenerator.skipColoring();
            }
        }
        if (!found)
        {
            cout << "COUNTEREXAMPLE!" << endl;
            nowPath.printPath();
        }
        nowPath = pathGenerator.nextPath();
    }
    cout << "MainOld2: Paths count " << paths << endl;
}
