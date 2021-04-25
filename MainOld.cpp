#include "Main.h"
#include "./prog/Utils.h"
#include "./prog/Coloring.h"
#include "./prog/Path.h"
#include "./prog/PathGenerators/SimplePathGenerator.h"
#include "./prog/ColoringGenerators/WholeColoringGenerator.h"
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

    while (!(nowPath.empty()))
    {
        found = false;

        WholeColoringGenerator coloringGenerator = WholeColoringGenerator(nowPath);
        Coloring coloring = coloringGenerator.nextColoring();

        while (!(coloring.empty()))
        {
            if (checkNonRepetitiveness(coloring))
            {
                //this coloring is non-repetitive, so skipping whole path
                found = true;
                break;
            }
            coloring = coloringGenerator.nextColoring();
        }
        if (!found)
        {
            cout << "COUNTEREXAMPLE!" << endl;
        }
        nowPath = pathGenerator.nextPath();
    }
}
